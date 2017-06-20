#include<iostream>
using namespace std;

int Replace0With5(int n){
    if(!n)
        return 0;
    return n%10?Replace0With5(n/10)*10+n%10:Replace0With5(n/10)*10+5;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    n?cout<<"New Number is: "<<Replace0With5(n)<<endl:cout<<"New Number is: "<<5<<endl;
    return 0;
}
    
