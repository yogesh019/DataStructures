#include<iostream>
#include<vector>
#include<limits>
#define INF 1000
using namespace std;

/*Consider i-th coin. Either it will be included or not. If it is included, then the 
   value sum is decreased by the coin value and the number of used coins increases by 1.
   If it is not included, then we need to explore the remaining coins similarly. 
   We take the minimum of two cases.
*/
int getMinCoins(int*denom,int n,int amount){
    if(!amount)return 0;
    if(amount<0||n<=0)return INF;
    return min(1+getMinCoins(denom,n,amount-denom[n-1]),getMinCoins(denom,n-1,amount));
}
/*
int getMinCoins(int*denom,int n,int amount){
    if(!amount)return 0;
    if(amount>0&&n<=0)return INF;
    if(denom[n-1]>amount)
        return getMinCoins(denom,n-1,amount);
    return min(1+getMinCoins(denom,n,amount-denom[n-1]),getMinCoins(denom,n-1,amount));
}
*/

int getMinCoins2(int *denom,int n,int amount){
    if(!amount)return 0;
    int Min=numeric_limits<int>::max();
    for(int i=0;i<n;i++){
        if(denom[i]<=amount){
            Min=min(Min,1+getMinCoins2(denom,n,amount-denom[i]));
        }
    }
    return Min;
}

int getMinCoinsDP(int*denom,int n,int amount){
    vector<vector<int> >dp(amount+1,vector<int>(n+1,-1));
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
    for(int i=1;i<=amount;i++)
        dp[i][0]=INF;
    for(int i=1;i<=amount;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=i<denom[j-1]?dp[i][j-1]:min(1+dp[i-denom[j-1]][j],dp[i][j-1]);
        }
    }
    return dp[amount][n];
}
//Greedy Algorithm to find Minimum number of Coins
/*
The idea is simple Greedy Algorithm. Start from largest possible denomination and keep adding denominations while 
remaining value is greater than 0. Below is complete algorithm.
1) Initialize result as empty.
2) find the largest denomination that is
   smaller than V.
3) Add found denomination to result. Subtract
   value of found denomination from V.
4) If V becomes 0, then print result.
   Else repeat steps 2 and 3 for new value of V

Note that above approach may not work for all denominations. For example, it doesn’t work for denominations {9, 6, 5, 1} and V = 11. 
The above approach would
print 9, 1 and 1. But we can use 2 denominations 5 and 6.

// All denominations of Indian Currency
int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno)/sizeof(deno[0]);

// Driver program
void findMin(int V)
{
    // Initialize result
    vector<int> ans;

    // Traverse through all denomination
    for (int i=n-1; i>=0; i--)
    {
        // Find denominations
        while (V >= deno[i])
        {
           V -= deno[i];
           ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int i = 0; i < ans.size(); i++)
           cout << ans[i] << "  ";
}

**/

int main(){
    int denom[100],n,amount;
    cout<<"Enter the number of denomiations: ";
    cin>>n;
    cout<<"Enter the denominations: ";
    for(int i=0;i<n;i++)
        cin>>denom[i];
    cout<<"Enter the amount: ";
    cin>>amount;
    cout<<"Minimum No.of Coins required to make amount are: "<<endl;
    cout<<getMinCoins(denom,n,amount)<<endl;
    cout<<getMinCoins2(denom,n,amount)<<endl;
    cout<<getMinCoinsDP(denom,n,amount)<<endl;
    return 0;
}


