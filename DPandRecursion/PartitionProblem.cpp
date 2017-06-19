#include<iostream>
#include<vector>
using namespace std;
/*
Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements 
in both subsets is same
*/
/****************************************************************************************************************************************/
bool isPartitionPossible(int *arr,int n,int *data,int index,int sum){
   if(!sum){
       for(int i=0;i<index;i++){
           cout<<data[i]<<" ";
       }
       cout<<endl;
       return true;
   }
   if(!n)return false;
   bool res1=isPartitionPossible(arr,n-1,data,index,sum);
   data[index]=arr[n-1];
   bool res2=isPartitionPossible(arr,n-1,data,index+1,sum-arr[n-1]);
   return res1||res2;
}

bool isPartitionPossible(int*arr,int Start,int End,int*data,int index,int sum){
    if(!sum){
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    bool res=false;
    for(int i=Start;i<=End;i++){
        data[index]=arr[i];
        res=isPartitionPossible(arr,i+1,End,data,index+1,sum-arr[i])||res;
    }
    return res;
}
bool isPartitionPossible(int *arr,int n,int sum,vector<int>&res){
    if(!sum)return true;
    if(!n&&sum)return false;

    if(arr[n-1]>sum) // if negative numbers are not allowed and sum cannot be negative , in the above two I didn't put this condition
        return isPartitionPossible(arr,n-1,sum,res); // it means numbers and sum can be negative in above two , try for 1 2 -1 2
    res.push_back(arr[n-1]);
    bool check=isPartitionPossible(arr,n-1,sum-arr[n-1],res);
    if(check)return check;
    res.pop_back();
    return   isPartitionPossible(arr,n-1,sum,res);

}
/****************************************************************************************************************************************/

bool isPartitionPossibleDP(int*arr,int  n,int sum){
    vector<vector<bool> >dp(sum+1,vector<bool>(n+1,false));
    for(int j=0;j<=n;j++)
        dp[0][j]=true;
    for(int i=1;i<=sum;i++)
        dp[i][0]=false;
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=i<arr[j-1]?dp[i][j-1]:dp[i][j-1]||dp[i-arr[j-1]][j-1];
        }
    }
    return dp[sum][n];
}
/****************************************************************************************************************************************/
int main(){
    int arr[100],n,data[100],sum=0;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter  array: ";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    if(sum&1)
        cout<<"Partition not possible"<<endl;

    else if(isPartitionPossibleDP(arr,n,sum/2)){
            cout<<"Partition Possible "<<endl;
    }
    else{
        cout<<"Parition not possible"<<endl;
    }
    return 0;
}
    
