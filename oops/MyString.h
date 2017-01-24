#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include<iostream>
#include<cstring>
using namespace std;

class MyString{

    char *str;
    unsigned int len;
    unsigned int cap;

    void addChar( const char &ch){

        if(!cap){
            cap=1;
            str=new char[cap];
        }
        if(len==cap){
            cap*=2;
            char *temp=new char[cap];
            strcpy(temp,str);
            delete [] str;
            str=temp;

        }
        str[len]=ch;
        str[len+1]=0;
        len++;

    }
public:

    MyString():len(0),cap(0),str(0){}

    MyString(unsigned int capacity,const char &c){
        cap=capacity;
        len=cap;
        str=new char[cap];
        for(int i=0;i<len;i++){
            str[i]=c;
        }
    }

    MyString(const char*s){
        len=strlen(s);
        cap=len;
        str=new char[cap];
        strcpy(str,s);
    }

    MyString(const MyString&S):len(S.len),cap(S.cap){
        str=new char[cap];
        strcpy(str,S.str);
    }

    MyString&operator=(const MyString&S){
        len=S.len;
        cap=S.cap;
        delete [] str;
        str=new char[cap];
        strcpy(str,S.str);
        return (*this);
    }

    void printString(){

        cout<<str;
    }

    const unsigned int length()const{

        return len;
    }

    const unsigned int capacity()const{

        return cap;
    }

    void readString( char delim='\n'){

        char ch=cin.get();
        while(ch!=delim){
            addChar(ch);
            ch=cin.get();
        }
    }

    MyString&operator+=(const MyString&S){

        int i=0;
        while(S.str[i]){
            addChar(S.str[i]);
            i++;
        }
        return (*this);
    }

    MyString&operator+(const char &ch){

        addChar(ch);
        return *this;
    }

    MyString operator+(const MyString&S){

        MyString temp=*this;
        temp+=S;
        return temp;
    }

    bool operator<(const MyString&S){

        return strcmp(str,S.str)<0?true:false;
    }

    char&operator[](int index){
        if(!cap){
                char ch='\0';
            return ch;
        }
        return str[index];

    }
    ~MyString(){
        if(cap){
            delete [] str;
        }

    }
    void Push_Back(const char &ch){

        addChar(ch);

    }
    friend istream&operator>>(istream&,MyString&);
    friend ostream&operator<<(ostream&,const MyString&);
};


    istream&operator>>(istream&in,MyString&S){
    S.len=0;
    char ch=in.get();
    while(ch!=' '&&ch!='\t'&&ch!='\n'){
        S.addChar(ch);
        ch=in.get();
    }
    return in;
    }
ostream&operator<<(ostream&out,const MyString&S){

    out<<S.str;
    return out;
}


#endif // MYSTRING_H_INCLUDED
