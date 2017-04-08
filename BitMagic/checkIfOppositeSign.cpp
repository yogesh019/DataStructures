/* check if the two numbers are of opposite sign or not
 *Let the given integers be x and y. The sign bit is 1 in negative numbers, and 0 in positive numbers. 
 The XOR of x and y will have the sign bit as 1 iff they have opposite sign. 
 In other words, XOR of x and y will be negative number number iff x and y have opposite signs. */

#include<iostream>
using namespace std;

bool CheckOppositeSign(int x,int y){
    //if(x<0&&y>0||x>0&&y<0)return true;
    //return false;
    return (x^y)<0;
}
int main(){
    int x,y;
    cout<<"Enter two integers: ";
    cin>>x>>y;
    if(CheckOppositeSign(x,y)){
        cout<<"Integers are of opposite sign"<<endl;
    }else{
        cout<<"Integers are not of opposite sign"<<endl;
    }
    return 0;
}
