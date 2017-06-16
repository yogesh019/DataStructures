#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int max_price(int*price,int n){
    if(!n)return 0;
    int Max=numeric_limits<int>::min();
    for(int i=0;i<n;i++){
        Max=max(price[i]+max_price(price,n-i-1),Max);
    }
    return Max;
}
// Dynamic Programming Solution ~ Time Complexity is O(n^2) because of 2 loops to find the max ,space complexity is O(n)
int profit(int *price,int n){
    vector<int>dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int Max=numeric_limits<int>::min();
        for(int j=0;j<i;j++){
           Max=max(price[j]+dp[i-j-1],Max);
        }
        dp[i]=Max;
    }
    return dp[n];
}
int main(){
    int price[100],n;
    cout<<"Enter length of rod: ";
    cin>>n;
    cout<<"Enter price of different segments of the rod: ";
    for(int i=0;i<n;i++)
        cin>>price[i];
    cout<<"Profit is:  "<<endl;
    cout<<max_price(price,n)<<endl;
    cout<<profit(price,n)<<endl;
    return 0;
}
