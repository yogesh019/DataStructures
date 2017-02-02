#ifndef CIRCULARQUEUE_H_INCLUDED
#define CIRCULARQUEUE_H_INCLUDED
#include<iostream>
#define CAPACITY 10
using namespace std;

template<typename T>
class CircularQueue{
    T*arr;
    int beginIndex,lastIndex;
    unsigned int capacity;

public:
    CircularQueue():beginIndex(-1),lastIndex(-1),capacity(CAPACITY){
        arr=new T[capacity];
    }
    CircularQueue(unsigned int c):beginIndex(-1),lastIndex(-1),capacity(c){
        arr=new T[capacity];
    }
    CircularQueue(const CircularQueue&Q):arr(0){
        (*this)=Q;
    }

    CircularQueue&operator=(const CircularQueue&Q){
        if(arr)delete [] arr;
        beginIndex=Q.beginIndex;
        lastIndex=Q.lastIndex;
        capacity=Q.capacity;
        arr=new T[capacity];
        for(int i=0;i<capacity;i++){
            arr[i]=Q.arr[i];
        }
        return *this;
    }

    ~CircularQueue(){
        delete []  arr;
    }
    bool isEmpty()const{
        return beginIndex==-1;
    }

    bool isFull()const{
        return (lastIndex+1)%capacity==beginIndex;

    }

    unsigned int Size()const{

        if(isEmpty())return 0;

        if(beginIndex<=lastIndex)return (lastIndex-beginIndex+1);

        return capacity-(beginIndex-lastIndex-1);
    }
    void Enqueue(const T&ele){
        if(isFull()){
            throw "Queue Full!";
        }
        if(isEmpty()){
            beginIndex=0;
        }
        lastIndex=(lastIndex+1)%capacity;
        arr[lastIndex]=ele;
        return;

    }
    void Dequeue(){
        if(isEmpty()){
            throw "Queue Empty!";
        }
        if(beginIndex==lastIndex){
            beginIndex=-1;
            lastIndex=-1;
        }else{
            beginIndex=(beginIndex+1)%capacity;
        }
    return;
    }

    T&Front()const{

        if(isEmpty()){
            throw "Queue Empty!";
        }
        return arr[beginIndex];
    }


};


#endif // CIRCULARQUEUE_H_INCLUDED
