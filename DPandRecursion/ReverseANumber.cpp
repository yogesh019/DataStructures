#include<iostream>
using namespace std;

int reverse(int N){
    int rev=0;
    while(N){             //~Time Complexity is O(logN) base is 10
        rev=rev*10+N%10;
        N=N/10;
    }
    return rev;
}
int reverseRecursive(int N){
    static int reverse=0;
    static int base=1;
    if(!N)return N;         //~ Time Complexity is O(logN) base is 10
    reverseRecursive(N/10);
    reverse=reverse+N%10*base;
    base=base*10;// base set for the parent function
    return reverse;
}
int main(){
    int N;
    cout<<"Enter Number: ";
    cin>>N;
    reverse(N);
    cout<<"Reverse is: "<<reverse(N)<<endl;
    cout<<"Reverse is: "<<reverseRecursive(N)<<endl;
    return 0;
}
