#ifndef QUEUEUSING2STACKS_H_INCLUDED
#define QUEUEUSING2STACKS_H_INCLUDED
#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class QueueUsingStacks{           /// making deque costlier
    stack<T>S1,S2;
    public:
        bool isEmpty()const{
            return S1.empty()&&S2.empty();
        }
        void Enqueue(const T&ele){
            S1.push(ele);
        }
        void Dequeue(){
            if(isEmpty()){
                throw "Queue Empty!!";
            }
            if(S2.empty()){
                while(!S1.empty()){
                    S2.push(S1.top());
                    S1.pop();
                }
            }
            S2.pop();

        }
      T&Front(){
        if(isEmpty()){
            throw "Queue Empty!!";
        }
        if(S2.empty()){
            while(!S1.empty()){
                    S2.push(S1.top());
                    S1.pop();
                }
            }
      return S2.top();
      }
};


#endif // QUEUEUSING2STACKS_H_INCLUDED
