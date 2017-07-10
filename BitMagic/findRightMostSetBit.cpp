#include<iostream>
using namespace std;

unsigned int getFirstSetBitPosition(unsigned int n){
    if(!n)return 0;
	unsigned int pos=1;
	while(n){
	   if(n&1)          /// Time Complexity is 0(logn)
		return pos;
	   n=n>>1;
	   pos++;
	}
}
unsigned int getFirstSetBitPosition2Approach(unsigned  int n){
    if(!n)return 0;                                                                                                 /// Time Complexityy is 0(logn)
return n%2?1:1+getFirstSetBitPosition2Approach(n/2);
}


void decimalToBinary(unsigned int n){
    if(!n)return;
    decimalToBinary(n/2);                                                         /// Time Complexityy is 0(logn)
    cout<<n%2;
    return;
}
void decimalToBinary2Approach(int n){
    unsigned int i=1<<31;                                                                         /// Time Complexityy is 0(logn)
    for(;i>0;i=i/2){
        n&i?cout<<"1":cout<<"0";
    }
return;
}
int main(){
	int n;
	cout<<"Enter n: ";
	cin>>n;

	decimalToBinary(n);
	cout<<endl;
	decimalToBinary2Approach(n);
	cout<<endl;
    cout<<"Position of right most set bit is: "<<getFirstSetBitPosition(n);
    cout<<endl;
    cout<<"Position of the right most set bit is:   "<<getFirstSetBitPosition2Approach(n);
    cout<<endl;
	return 0;
}

