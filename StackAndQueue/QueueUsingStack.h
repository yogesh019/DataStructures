#ifndef QUEUEUSINGSTACK_H_INCLUDED
#define QUEUEUSINGSTACK_H_INCLUDED
#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class QueueUsingStack{
    stack<T>S;
    public:
    bool isEmpty()const{
        return S.empty();
    }
    void Enqueue(const T&ele){
        S.push(ele);
        return;
    }
    void Dequeue(){
        if(isEmpty())
            throw "Queue Empty!";
        if(S.size()==1){
            S.pop();
            return;
        }
        const T ele=S.top();
        S.pop();
        Dequeue();
        S.push(ele);
        return;
    }
    T&Front(){
        if(isEmpty())
            throw "Queue Empty!";
        if(S.size()==1)
            return S.top();
       const T ele=S.top();S.pop();
        T &value=Front();
        S.push(ele);
        return value;
    }
};

#endif
