#include<iostream>
using namespace std;

void method1(int&x,int&y){
    x=x+y;
    y=x-y;
    x=x-y;
    return;
}
void method2(int&x,int&y){
    x=x*y;
    y=x/y;
    x=x/y;
    return;
}
void method3(int&x,int&y){
    x=x^y;
    y=x^y;
    x=x^y;
    return;
}
int main(){
    int x=8,y=9;
    method1(x,y);
    cout<<"x= "<<x<<","<<"y= "<<y<<endl;
    method2(x,y);
    cout<<"x= "<<x<<","<<"y= "<<y<<endl;
    method3(x,y);
    cout<<"x= "<<x<<","<<"y= "<<y<<endl;
    return 0;
}
