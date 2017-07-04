#ifndef MIDDLEELEMENTSTACK_H_INCLUDED
#define MIDDLEELEMENTSTACK_H_INCLUDED
#include<iostream>
using namespace std;

// stack with operations : getMiddle in O(1) and deleteMiddle in O(1)
template<typename T>
class Stack;

template<typename T>
class LLNode{
    T data;
    LLNode*next,*prev;
public:
    LLNode(const T&ele=0,LLNode*NEXT=0,LLNode*PREV=0):data(ele),next(NEXT),prev(PREV){}
friend class Stack<T>;
};

template<typename T>
class Stack{
    LLNode<T>*head,*mid;
    unsigned int len;
    
    void Clear(){
        while(!isEmpty()){
            Pop();
        }
    };
    void DuplicateAs(const Stack&S){
        LLNode<T>*temp=S.head;
        while(temp->next){
            temp=temp->next;
        }
        while(temp){
            Push(temp->data);
            temp=temp->prev;
        }
        return;
    }
public:
    Stack():head(0),mid(0),len(0){}
    
    Stack(const Stack&S):head(0),mid(0),len(0){
        DuplicateAs(S);
    }
    Stack&operator=(const Stack&S){
        DuplicateAs(S);
        return (*this);
    }
    ~Stack(){
            Clear();
    }
    bool isEmpty()const{
        return head==0;
    }
    
    T&getMiddle(){
        if(isEmpty())
            throw "Stack Empty!";
        return mid->data;
    }
    void deleteMiddle(){
        if(isEmpty())
            throw "Stack Emmpty!";
        if(len==1){
            len--;
            delete mid;
            mid=0;
            head=0;
        }else{
            len--;
            LLNode<T>*temp=mid;
            mid->prev->next=mid->next;
            mid->next->prev=mid->prev;
            mid=len&1?mid->prev:mid->next;
            delete temp;
        }
        return;
    }
    const unsigned int Size()const{
        return len;
    }
    void Push(const T&ele){
        len++;
        head=new LLNode<T>(ele,head);
        if(head->next)
            head->next->prev=head;
        mid=len==1?head:len&1?mid->prev:mid;
    }
    void Pop(){
        if(isEmpty())
            throw "Stack Empty!";
        LLNode<T>*temp=head;
        if(head->next)
            head->next->prev=0;
        head=head->next;
        len--;
        mid=!len?0:len%2==0?mid->next:mid;
    }

    T&Top(){
        if(isEmpty())
            throw "Stack Empty";
        return head->data;
    }
};

#endif
