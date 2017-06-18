#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printSumOfAllSubsetsOfSizeK(int *arr,int n,int *data,int index,int K){
    static int sum=0;
    if(!K){
        for(int i=0;i<index;i++){
            cout<<data[i];
            if(i!=index-1){
                cout<<"+";
            }
        }
        cout<<"="<<sum<<endl;
        return;
    }
    if(K>n)return;
    sum+=arr[n-1];
    data[index]=arr[n-1];
    printSumOfAllSubsetsOfSizeK(arr,n-1,data,index+1,K-1);
    while(arr[n-1]==arr[n-2])
        n--;
    sum-=arr[n-1];
    printSumOfAllSubsetsOfSizeK(arr,n-1,data,index,K);
    return;
}
void printSumOfAllSubsetsOfSizeK(int*arr,int Start,int End,int *data,int index,int K){
    static int sum=0;
    if(!K){
        for(int i=0;i<index;i++){
            cout<<data[i];
            if(i!=index-1){
                cout<<"+";
            }
        }
        cout<<"="<<sum<<endl;
        return;
    }
    if(K>(End-Start+1))
        return;
    for(int i=Start;i<=End;i++){
        sum+=arr[i];
        data[index]=arr[i];
        printSumOfAllSubsetsOfSizeK(arr,i+1,End,data,index+1,K-1);
        sum-=arr[i];
        while(arr[i]==arr[i+1])
            i++;
    }
    return;
}


void printSumOfAllSubsetsOfSizeK(int*arr,int n,int index,int K){
    static vector<int>data;
    static int sum=0;
    if(data.size()==K){
        for(int i=0;i<K;i++){
            cout<<data[i];
            if(i!=K-1)
                cout<<"+";
        }
        cout<<"="<<sum<<endl;
        return;
    }
    if(index==n)return;
    sum+=arr[index];
    data.push_back(arr[index]);
    printSumOfAllSubsetsOfSizeK(arr,n,index+1,K);
    while(arr[index]==arr[index+1])
        index++;
    sum-=arr[index];
    data.pop_back();
    printSumOfAllSubsetsOfSizeK(arr,n,index+1,K);
    return;
}
int main(){
    int arr[100],n,data[100],K;
    cout<<"Enter the array size: ";
    cin>>n;

    cout<<"Enter array: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter K: ";
    cin>>K;
    sort(arr,arr+n);
    printSumOfAllSubsetsOfSizeK(arr,n,data,0,K);
    cout<<endl<<endl<<endl;
    printSumOfAllSubsetsOfSizeK(arr,0,n-1,data,0,K);
    cout<<endl<<endl<<endl;
    printSumOfAllSubsetsOfSizeK(arr,n,0,K);
    return 0;
}

