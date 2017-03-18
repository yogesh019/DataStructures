#ifndef MYVECTOR_H_INCLUDED
#define MYVECTOR_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>

class MyVector{

    T*arr;
    unsigned int len,cap;

    void reserve(unsigned int cap){
        if(this->cap>=cap)return;
        this->cap=cap;
        T*temp=new T[cap];
        for(int i=0;i<len;i++){
            temp[i]=arr[i];
        }
        delete [] arr;

        arr=temp;
    }
public:
    typedef T* Iterator;
    typedef const T* Const_Iterator;
    MyVector():len(0),cap(0),arr(0){}

    MyVector(unsigned int c,const T&value=0):len(c),cap(c){
        arr=new T[cap];
        for(int i=0;i<cap;i++){
            arr[i]=value;
        }
    }

    MyVector(const MyVector&V){
        *this=V;
    }

    MyVector&operator=(const MyVector&V){

        delete []arr;
        cap=V.cap;
        len=V.len;
        arr=new T[cap];
        for(int i=0;i<cap;i++){
            arr[i]=V.arr[i];
        }
    }

    ~MyVector(){
        if(arr){
            delete [] arr;
        }

    }

/**Here we have implemented only expandable dynamic array ,i.e array capacity gets double when len==capacity, we can also
    make this contractable when there is a large difference between array size and capacity, when array size is capacity/4
    make capacity be capacity/2
    **/
    void Push_Back(const T&ele){
        if(!cap){
            cap=1;
            arr=new T[cap];
        }
        if(len==cap){
            reserve(cap*2);
        }
        arr[len]=ele;
        len++;
    }
    void Pop_Back(){

        if(isEmpty())
            return;
        len--;
    }

        bool isEmpty()const{
            return len==0;
    }

    void Clear(){

        while(!isEmpty()){
                Pop_Back();
    }
    }

    const unsigned int Size()const{
        return len;
    }
    const unsigned int Capacity()const{
        return cap;
    }
    T&Front()const{
        return arr[0];
    }
    T&Back()const{
        return arr[len-1];
    }
    T&operator[](int index){
        return arr[index];
    }

    void shrink_to_fit(){
        for(int i=len;i<cap;i++){
            delete (arr+i);
        }
        cap=len;
    }
    Iterator Begin() {
        return &arr[0];
    }
    Iterator End() {
        return &arr[len];
    }

    Const_Iterator Begin() const{
        return &arr[0];
    }

    Const_Iterator End() const {
        return &arr[len];
    }

    void Insert(unsigned int pos,const T&ele){
        len++;
        if(len==cap)
                reserve(cap*2);
        for(int i=len-1;i>=pos;i--){
            arr[i]=arr[i-1];
            arr[i-1]=ele;
        }

 }

    void Insert(unsigned int pos,T*el,int Count){
        len=len+Count;
        if(len==cap)reserve(cap*2);
        for(int i=len-1;i>=pos;i--){
            arr[i+Count]=arr[i];
        }
        for(int i=0;i<Count;i++){
            arr[pos+i]=el[i];
        }
    return;
    }
    void Erase(int pos){
        if(pos<=0)return;

        for(int i=pos;i<len;i++){
            arr[i-1]=arr[i];
        }
        len--;
    }
    void Erase(int Start,int End){

        for(int i=End+1;i<len;i++){
            arr[i-(End-Start)-1]=arr[i];

        }
    len=len-(End-Start+1);
    }


};

#endif // MYVECTOR_H_INCLUDED
