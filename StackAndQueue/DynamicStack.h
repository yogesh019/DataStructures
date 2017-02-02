#ifndef DYNAMICSTACK_H_INCLUDED
#define DYNAMICSTACK_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class DynamicStack{
    T *arr;
    unsigned int len,cap;

    void reserve(unsigned int capacity){
        if(cap>=capacity){
            return;
        }
        cap=capacity;
        T *temp=new T[cap];
        for(int i=0;i<len;i++){
            temp[i]=arr[i];
        }
        delete [] arr;
        arr=temp;
        return;
    }

public:
    DynamicStack():arr(0),len(0),cap(0){}

    bool isEmpty() const{
            return len==0;
    }
    DynamicStack(const DynamicStack&S){
        (*this)=S;
    }
    DynamicStack&operator=(const DynamicStack&S){
        if(arr){
            delete [] arr;
        }
        len=S.len;
        cap=S.cap;
        arr=new T[cap];
        for(int i=0;i<cap;i++){
            arr[i]=S.arr[i];
        }
        return (*this);
    }


    ~DynamicStack(){
        if(arr){
            delete [] arr;
            len=0;
        }
    }

    unsigned int Size()const{
        return len;
    }

    void Push(const T&ele){
        if(!cap){
            cap=1;
            arr=new T[cap];
        }
        if(len==cap){
            reserve(cap*2);
        }
        arr[len]=ele;
        len++;
        return;
    }
    void Pop(){
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        len--;
    }
    T&Top()const{
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        return arr[len-1];
    }
};


#endif // DYNAMICSTACK_H_INCLUDED
