#include<iostream>
#include<vector>
using namespace std;

int count_ways(int n){
    if(n<0)return 0;
    if(!n)return 1;
    return count_ways(n-1)+count_ways(n-2);
}
int count_waysDP(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=i-2>=0?dp[i-1]+dp[i-2]:dp[i-1];
    }
    return dp[n];
}
// for generic m, let's say person can hop up to m stairs at a time

int count_waysDP(int n,int m){
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=min(m,i);j++){
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}
int main(){
    int n,m;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter m: ";
    cin>>m;
    cout<<"No of ways: "<<endl;
    cout<<count_ways(n)<<endl;
    cout<<count_waysDP(n)<<endl;
    cout<<count_waysDP(n,m)<<endl;
    return 0;
}
