#ifndef MYCOMPLEX_H_INCLUDED
#define MYCOMPLEX_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class MyComplex;

template<typename T>
istream&operator>>(istream&,MyComplex<T>&);

template<typename T>
ostream&operator<<(ostream&,const MyComplex<T>&);


template<typename T>

class MyComplex{
    T real,img;

public:
    MyComplex(const T&real=0,const T&img=0){
        this->real=real;
        this->img=img;
    }
    MyComplex&operator++(){
        real++;
        img++;
        return (*this);
    }
    MyComplex operator++(int){
        MyComplex C=*this;
        real++;
        img++;
        return C;
    }
    MyComplex&operator+=(const MyComplex&C){
        real+=C.real;
        img+=C.img;
        return (*this);
    }
    MyComplex operator+(const MyComplex&C){
        MyComplex temp=*this;
        temp+=C;
        return temp;
    }
    bool operator==(const MyComplex&C)const{
        return (real==C.real)&&(img==C.img);
    }
    bool operator!=(const MyComplex&C)const{
        return !(*this==C);
    }

    friend istream&operator>><T>(istream&,MyComplex<T>&);
    friend ostream&operator<< <T>(ostream&,const MyComplex<T>&);
    };
    template<typename T>
    istream&operator>>(istream&in,MyComplex<T>&C){
        cout<<"Enter the real and imaginary part: ";
        in>>C.real>>C.img;
        return in;
    }

    template<typename T>
    ostream&operator<<(ostream&out,const MyComplex<T>&C){
        out<<"Complex Number is: ("<<C.real<<" + "<<C.img<<"i)";
        return out;

    }


#endif // MYCOMPLEX_H_INCLUDED
