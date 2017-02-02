#ifndef QUEUELL_H_INCLUDED
#define QUEUELL_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class QueueLL;

template<typename T>
class LLNode{

    T data;
    LLNode*next;
public:
    LLNode(const T&ele=0,LLNode*Next=0):data(ele),next(Next){}
    friend class QueueLL<T>;
};

template<typename T>
class QueueLL{

    LLNode<T>*head,*tail;

    void Clear(){
       while(!isEmpty()){
            Dequeue();
        }

    }
    void DuplicateAs(const QueueLL&Q){
        LLNode<T>*temp=Q.head;
        while(temp){
            Enqueue(temp->data);
            temp=temp->next;
        }

    }
public:
    QueueLL():head(0),tail(0){}
    QueueLL(const QueueLL&Q):head(0),tail(0){
        *this=Q;
    }
    QueueLL&operator=(const QueueLL&Q){

        Clear();
        DuplicateAs(Q);
        return *this;
    }

    ~QueueLL(){
        Clear();
    }

    bool isEmpty()const{

        return head==0;
    }
    void Enqueue(const T&el){

        LLNode<T>*temp=new LLNode<T>(el);
        if(isEmpty()){
            head=temp;
        }else{
            tail->next=temp;
        }
        tail=temp;
    }

    void Dequeue(){

        if(isEmpty()){
            throw "Queue Empty!";
        }
        LLNode<T>*temp=head;
        if(head==tail){
            tail=0;
        }
        head=head->next;
        delete temp;
    return;
    }


    T&Front()const{

        if(isEmpty()){
            throw "Queue Empty!";
        }
        return head->data;

    }

};

#endif // QUEUELL_H_INCLUDED
