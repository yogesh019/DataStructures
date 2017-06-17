#include<iostream>
#include<vector>
using namespace std;


int coinChange(int*denom,int n,int amount){
    if(amount<0||amount>0&&n<=0)return 0;
    if(!amount)return 1;
    //if(denom[n-1]>amount)return coinChange(denom,n-1,amount); No need , we handeled amount<0 in the base case
    return coinChange(denom,n-1,amount)+coinChange(denom,n,amount-denom[n-1]);
}

int coinChange(int *denom,int Start,int n,int amount){
    if(amount<0||Start==n)return 0;                            // you can do this by this way , but this does not make proper sense
    if(amount==0)return 1;
    return coinChange(denom,Start+1,n,amount)+coinChange(denom,Start,n,amount-denom[Start]);
}

int coinChangeIterative(int *denom,int n,int amount){
    vector<vector<int> >dp(amount+1,vector<int>(n+1));
    for(int j=0;j<=n;j++)
        dp[0][j]=1;
    for(int i=1;i<=amount;i++)
        dp[i][0]=0;
    for(int i=1;i<=amount;i++){
        for(int j=1;j<=n;j++){
            int x=i-denom[j-1]<0?0:dp[i-denom[j-1]][j];
            int y=dp[i][j-1];
            dp[i][j]=x+y;
        }
    }
    return dp[amount][n];
}
// Note: In Memoization the entire table  is not filled , table is only filled on demand , for ex here if we denom={5} and amount=20
// Then in Memoization method the entire table is not filled while in tabulation entire table is filled
int main(){
    int amount,n,denom[100];
    cout<<"Enter the number  of denominations: ";
    cin>>n;
    cout<<"Enter the denominations: ";
    for(int i=0;i<n;i++)
        cin>>denom[i];
    cout<<"Enter the amount: ";
    cin>>amount;
    cout<<"Number of Ways  To make Change: "<<endl;
    cout<<coinChange(denom,n,amount)<<endl;
    cout<<coinChange(denom,0,n,amount)<<endl;
    cout<<coinChangeIterative(denom,n,amount)<<endl;
    return 0;
}
