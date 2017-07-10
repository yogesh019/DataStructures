#include<iostream>
using namespace std;

unsigned int countSetBits(unsigned int n){
    if(!n)return 0;
    return n%2==0?countSetBits(n/2):1+countSetBits(n/2);
}

unsigned int countSetBits2Approach(unsigned int n){
    unsigned int Count=0;
    while(n){
        Count+=n&1;
        n=n>>1;
    }
return Count;
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<countSetBits2Approach(-8)<<endl;

    unsigned int Count=0;
    for(int i=1;i<=n;i++){
        Count+=countSetBits(i);                         /// Time complexity O(nlogn)
    }
    cout<<Count<<endl;
    return 0;
}
