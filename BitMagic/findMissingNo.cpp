/* Given a list of n-1 integers and these integers are in the range of 1 to n . There are no duplicates in list/ One of the integers is missing in thelist. We have to find the missing no*/
#include<iostream>
using namespace std;

int getMissingNo(int *arr,int n){
    int res=(n+1)*(n+2)/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return res-sum;
}
int getMissingNoUsingXor(int *arr,int n){
    int res=0;
    for(int i=1;i<=n+1;i++){
        res^=i;
    }
    int temp=0;
    for(int i=0;i<n;i++){
        temp^=i;
    }
    return res^temp;
}
int main(){
    int arr[]={1,2,4,5,6};
    cout<<"Missing Number is: "<<getMissingNoUsingXor(arr,5)<<endl;
    return 0;
}
