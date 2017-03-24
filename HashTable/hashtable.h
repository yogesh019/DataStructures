#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCUDED
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

unsigned int myHashFunction(const string&key){
    int hashvalue=0;
    for(int i=0;i<key.size();i++){
        hashvalue=hashvalue*37+key[i];
    }
    return hashvalue;
}
unsigned int myHashFunction(int key){
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

template<typename HashObj>
class HashTable{
    vector<list<HashObj> >table;
    unsigned int currentSize;
    
    int myHash(const  HashObj&key)const{
        return myHashFunction(key)%table.size();
    }
    
    void rehash(){
        vector<list<HashObj> >oldTable=table;
        makeEmpty();
        table.resize(nextPrime(2*table.size()));
        for(int i=0;i<oldTable.size();i++){
            while(oldTable[i].size()){
                Insert(oldTable[i].front());
                oldTable[i].pop_front();
            }
        }
    }
    public:
        HashTable(unsigned int Size=11):currentSize(0){
            table.resize(Size);
        }
        void makeEmpty(){
            for(int i=0;i<table.size();i++){
                table[i].clear();
            }
        }
        bool contains(const HashObj&x)const{
            const list<HashObj>&temp=table[myHash(x)];
            return find(temp.begin(),temp.end(),x)!=temp.end();
        }
        bool Insert(const HashObj&x){
            list<HashObj>&temp=table[myHash(x)];
            if(find(temp.begin(),temp.end(),x)!=temp.end())
                return false;
            temp.push_back(x);
            if(++currentSize>table.size())
                rehash();
            return true;
        }
        bool Remove(const HashObj&x){
            list<HashObj>&temp=table[myHash(x)];
            typename list<HashObj>::iterator it=find(temp.begin(),temp.end(),x);
            if(it==temp.end())
                return false;
            temp.erase(it);
            --currentSize;
            return true;
        }
};

#endif
