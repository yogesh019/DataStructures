#include<iostream>
#include<vector>
using namespace std;

void printAllSubsets(int*arr,int Start,int End,int *data,int index,int Sum){
    if(!Sum){
        cout<<"{";
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    for(int i=Start;i<=End;i++){
        data[index]=arr[i];
        printAllSubsets(arr,i+1,End,data,index+1,Sum-arr[i]);
    }
    return;
}

void printSubsets(int*arr,int n,int Sum){
    static vector<int>data;
    if(!Sum){
        cout<<"{";
        for(vector<int>::iterator it=data.begin();it!=data.end();it++){
            cout<<*it<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    if(!n)return;
    printSubsets(arr,n-1,Sum);
    data.push_back(arr[n-1]);
    printSubsets(arr,n-1,Sum-arr[n-1]);
    data.pop_back();
    return;
}
int main(){
    int arr[100],data[100],n,Sum;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter sum: ";
    cin>>Sum;
    printAllSubsets(arr,0,n-1,data,0,Sum);
    cout<<endl<<endl<<endl;
    printSubsets(arr,n,Sum);
    return 0;
}
