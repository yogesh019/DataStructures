#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class MyList;

template<typename T>
class LLNode{
    T data;
    LLNode*prev,*next;
public:
    LLNode():data(0),prev(0),next(0){}
    LLNode(const T&ele,LLNode*p=NULL,LLNode*n=NULL):data(ele),prev(p),next(n){}
    friend class MyList<T>;
};

template<typename T>
class MyList{
    LLNode<T>*head,*tail;
    unsigned int len;

    void init(){
        len=0;
        head=new LLNode<T>;//sentinel nodes
        tail=new LLNode<T>;
        head->next=tail;
        tail->prev=head;
    }
    void Clear(){
        while(!isEmpty()){
            Pop_Front();
        }
    }

public:
    MyList(){
        init();
    }
    int Size() const{
        return len;
    }
    bool isEmpty()const{
        return Size()==0;
    }
    ~MyList(){
        Clear();
        delete head;
        delete tail;
    }
    class Iterator{
        public:
        LLNode<T>*current;

        
            Iterator(LLNode<T>*temp=NULL):current(temp){}
            
            const Iterator&operator++(){
                current=current->next;
                return (*this);
            }
            Iterator operator++(int){
                Iterator old=*this;
                ++(*this);
                return old;
            }
            const Iterator&operator--(){
                current=current->prev;
                return *this;
            }
            bool operator==(const Iterator&I)const{
                return current==I.current;
            }
            
            bool operator!=(const Iterator&I)const{
                return !(*this==I);
            }
            
            const T&operator*()const{
                return current->data;
             }
        };

    MyList&operator=(MyList&L){
        if(!isEmpty()){
            Clear();
        }
        for(Iterator itr=L.Begin();itr!=L.End();itr++){
            Push_Back(*itr);
        }
        return (*this);
    }
    
    MyList(MyList&L){
        init();
        *this=L;
    }
    Iterator Begin(){
        return Iterator(head->next);
    }
    Iterator End(){
        return Iterator(tail);
    }
        
    const T&Front(){
        if(isEmpty()){
            throw "Empty Container!";
        }
        return *Begin();
    }
    const T&Back(){
        if(isEmpty()){
            throw "Empty Container";
        }
        return *--End();
    }
    
    // insert the element befor the pos specified by the iterator
    Iterator Insert(Iterator itr,const T&ele){ 
        LLNode<T>*temp=itr.current;
        len++;
        /**
        LLNode<T>*newNode=new LLNode<T>(ele);
        newNode->next=temp;
        newNode->prev=temp->prev;
        temp->prev->next=newNode;
        temp->prev=newNode;
        **/
        return Iterator(temp->prev=temp->prev->next=new LLNode<T>(ele,temp->prev,temp));
    }
    void Push_Front(const T&ele){
        Insert(Begin(),ele);
    }
    void Push_Back(const T&ele){
        Insert(End(),ele);
    }
    Iterator Erase(Iterator itr){
        if(isEmpty()){
            throw "Empty Container";
        }
        LLNode<T>*temp=itr.current;
        Iterator retVal(temp->next);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        len--;
        return retVal;
    }
    Iterator Erase(Iterator Start, Iterator End){
        Iterator itr;
        for(itr=Start;itr!=End;){
            itr=Erase(itr);
        }
        return itr;
    }
    void Pop_Front(){
        Erase(Begin());
    }
    void Pop_Back(){
        Erase(--End());
    }
};

#endif //MYLIST_H_INCLUDED
