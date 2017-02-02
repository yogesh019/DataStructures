#ifndef STATICSTACK_H_INCLUDED
#define STATICSTACK_H_INCLUDED
#include<iostream>
#define MAX_SIZE 100
using namespace std;

template<typename T>

class StaticStack{

T arr[MAX_SIZE];
int index;

public:
    StaticStack():index(0){}

    bool isEmpty()const{

            return index==0;

    }

    bool isFull()const{

            return index==MAX_SIZE;

    }

    bool Push(const T&ele){

    if(isFull()){

                throw "Stack Full !!!";

    }

        arr[index]=ele;
        index++;

        return true;
    }

   bool Pop(){

   if(isEmpty()){
    throw "Stack Empty!!!";

   }

   index--;
   return true;
   }

    T&Top(){

    if(isEmpty()){

            throw "Stack Empty !!!";

}

return arr[index-1];
}


};
#endif // STATICSTACK_H_INCLUDED

