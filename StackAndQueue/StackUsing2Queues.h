#ifndef STACKUSING2QUEUES_H_INCLUDED
#define STACKUSING2QUEUES_H_INCLUDED
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class StackUsingQueues{
    queue<T>Q1,Q2;
                                                                                            ///making push operation costlier
public:
    bool isEmpty() const{
        return Q1.empty();
    }
    void Push(const T&ele){
        Q2.push(ele);
        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1=Q2;
        while(!Q2.empty()){
            Q2.pop();
        }
    return;
    }

    void Pop(){
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        Q1.pop();
    return;
    }

    T &Top(){

        if(isEmpty()){
            throw "Stack Empty!!";
        }
        return Q1.front();

    }

};


#endif // STACKUSING2QUEUES_H_INCLUDED
