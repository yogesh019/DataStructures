#include<iostream>
using namespace std;

void printSubsets(int*data,int index,int N){
    if(!N){
        cout<<"{";
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    for(int i=1;i<=N;i++){
        data[index]=i;
        printSubsets(data,index+1,N-i);
    }
    
    return;
}
int main(){
    int data[100],N;
    cout<<"Enter N: ";
    cin>>N;
    cout<<"Subsets are: "<<endl;
    printSubsets(data,0,N);
    return 0;
}
