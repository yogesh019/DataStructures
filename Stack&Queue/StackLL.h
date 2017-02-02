#ifndef STACKLL_H_INCLUDED
#define STACKLL_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class StackLL;

template<typename T>
class LLNode{
    T data;
    LLNode *next;
public:
    LLNode(const T&ele=0,LLNode*NEXT=0):data(ele),next(NEXT){}

    friend class StackLL<T>;
};

template<typename T>
class StackLL{
    LLNode<T>*head;
    unsigned int len;

    void Clear(){
        while(!isEmpty()){
            Pop();
        }
    }
    void DuplicateAs(const StackLL&S){

    LLNode<T>*temp=S.head;
    LLNode<T>*prevNode=0;
    while(temp){
        LLNode<T>*copyNode=new LLNode<T>(*temp);
        if(!head){
            head=copyNode;

        }else{
            prevNode->next=copyNode;
        }

        prevNode=copyNode;
        temp=temp->next;
    }
    len=S.len;

    return;
    }

public:
    StackLL():head(0),len(0){}

    StackLL(const StackLL&S):head(0),len(0){
        (*this)=S;
        return;
    }
    StackLL&operator=(const StackLL&S){
        Clear();
        DuplicateAs(S);
        return (*this);
    }

    bool isEmpty()const{
    return head==0;
    }

    ~StackLL(){
        Clear();
    }
    const unsigned int Size()const{

        return len;

    }
    void Push(const T&ele){
        LLNode<T>*temp=new LLNode<T>(ele);
        temp->next=head;
        head=temp;
        len++;
    }
    void Pop(){
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        len--;
        LLNode<T>*temp=head;
        head=head->next;
        delete temp;
        return;

    }
    T&Top()const{
        if(isEmpty()){
            throw "Stack Empty!!";
        }
        return head->data;
    }
};

#endif // STACKLL_H_INCLUDED
