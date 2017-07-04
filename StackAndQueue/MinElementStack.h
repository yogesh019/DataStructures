#ifndef MINELEMENTSTACK_H_INCLUDED
#define MINELEMENTSTACK_H_INCLUDED
#include"StackLL.h"

// Design a Data Structure SpecialStack that supports getMin() in O(1)
template<typename T>
class SpecialStack:public StackLL<T>{
    StackLL<T>min;
public:
   
    void Push(const T&ele){
        StackLL<T>::Push(ele);
        if(min.isEmpty()){
            min.Push(ele);
        }else{
            if(ele<=min.Top()){
                min.Push(ele);
            }
        }
        return;
    }
    void Pop(){
        if(StackLL<T>::isEmpty())
            throw "Stack Empty!";
        T ele=StackLL<T>::Top();
        StackLL<T>::Pop();
        if(min.Top()==ele){
            min.Pop();
        }
    return;
    }
    T&getMinimum(){
        if(StackLL<T>::isEmpty())
            throw "Stack Empty!";
        return min.Top();
    }
};

#endif
