#ifndef MYUNORDERED_MAP_H_INCLUDED
#define MYUNORDERED_MAP_H_INCLUDED
#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

unsigned int myHashFunction(const string&key){
    int hashvalue=0;
    for(int i=0;i<key.size();i++){
        hashvalue=hashvalue*37+key[i];
    }
    return hashvalue;
}
unsigned int myHashFunction(const int&key){
    return key;
}

bool isPrime(int n){
    if(n==1||n%2==0)return false;
    if(n==2||n==3)return true;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0)return false;
    }
    return true;
}
int nextPrime(int n){
    if(n%2==0)n++;
    for(;!isPrime(n);n+=2);
    return n;
}

template<typename key, typename value>
class MyUnorderedMap{
    vector<list<pair<key,value> > >table;
    unsigned int currentSize;
    
    int myhash(const key&k){
        return myHashFunction(k)%table.size();
    }

    void rehash(){
        vector<list<pair<key,value> > >oldTable=table;
        makeEmpty();
        table.resize(nextPrime(2*table.size()));
        for(int i=0;i<oldTable.size();i++){
            while(oldTable[i].size()){
                Insert(oldTable[i].front());
                oldTable[i].pop_front();
            }
        }
        return;
    }
    
    public:
        MyUnorderedMap(unsigned int Size=11):currentSize(0){
            table.resize(Size);
        }
        void makeEmpty(){
            for(int i=0;i<table.size();i++){
                table[i].clear();
            }
            return;
        }
        bool contains(const key&k){
             list<pair<key,value> >&temp=table[myhash(k)];
            typename list<pair<key,value> >::const_iterator itr;
            for(itr=temp.begin();itr!=temp.end();itr++){
                if(itr->first==k)
                    return true;
            }
            return false;
        }
        bool Insert(const pair<key,value>&P){
            list<pair<key,value> >&temp=table[myhash(P.first)];
            typename list<pair<key,value> >::const_iterator it;
            for(it=temp.begin();it!=temp.end();it++){
                if(it->first==P.first)
                    return false;
            }
            temp.push_back(P);
            if(++currentSize>table.size())
                rehash();
            return true;
        }
        value&operator[](const key&k){
            list<pair<key,value> >&temp=table[myhash(k)];
            typename list<pair<key,value> >::iterator itr;
            for(itr=temp.begin();itr!=temp.end();itr++){
                if(itr->first==k){
                    return itr->second;
                }
            }
            pair<key,value>*ptr=new pair<key,value>(k,0);
            temp.push_back(*ptr);
            return ptr->second;
        }
       
        bool Remove(const key&k){
            list<pair<key,value> >&temp=table[myhash(k)];
            typename list<pair<key,value> >::iterator it;
            for(it=temp.begin();it!=temp.end();it++){
                if(it->first==k){
                    temp.erase(it);
                    --currentSize;
                return true;
                }
            }

            return false;
        }
};





#endif

