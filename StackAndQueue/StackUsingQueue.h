#ifndef STACKUSINGQUEUE_H_INCLUDED
#define STACKUSINGQUEUE_H_INCLUDED
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class StackUsingQueue{

queue<T>Q;
public:
    bool isEmpty()const{
        return Q.empty();
    }
    void Push(const T&ele){
        int Size=Q.size();
        Q.push(ele);
        for(int i=0;i<Size;i++){
            Q.push(Q.front());
            Q.pop();
        }
    }
    void Pop(){
        if(isEmpty()){
            throw "Stack Empty!";
        }
        Q.pop();
    }

    T&Top(){
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        return Q.front();
    }

};



#endif // STACKUSINGQUEUE_H_INCLUDED
