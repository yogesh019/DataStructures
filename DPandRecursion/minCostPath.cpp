#include<iostream>
#include<vector>
#include<limits>
using namespace std;

// Recursive Solutions : Exponential Time Complexity
int minCostPath(int i,int j,int N,int M,int cost[][100]){
    if(i>N||j>M)return numeric_limits<int>::max();    // in this method ,sourcekeeps on varying as parameters  of the function
    
    return i==N-1&&j==M-1?cost[N-1][M-1]:cost[i][j]+min(minCostPath(i+1,j+1,N,M,cost),min(minCostPath(i,j+1,N,M,cost),minCostPath(i+1,j,N,M,cost)));
}

int minCostPath(int N,int M,int cost[][100]){
    if(N<0||M<0)return numeric_limits<int>::max(); // in this method destination keeps pn varying as parameters of the function

    return N==0&&M==0?cost[N][M]:cost[N][M]+min(minCostPath(N-1,M-1,cost),min(minCostPath(N-1,M,cost),minCostPath(N,M-1,cost)));
}

//Dynamic Programming Solution
int minCostPathTabulation1(int cost[][100],int N,int M){
    vector<vector<int> >dp(N,vector<int>(M,-1)); // here destination keeps on varying filling the upper L first
    dp[0][0]=cost[0][0];
    for(int i=1;i<N;i++)
        dp[i][0]=cost[i][0]+dp[i-1][0];
    for(int j=1;j<M;j++)
        dp[0][j]=cost[0][j]+dp[0][j-1];
    for(int i=1;i<N;i++){
        for(int j=1;j<M;j++){
            dp[i][j]=cost[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[N-1][M-1];
}

int minCostPathTabulation2(int cost[][100],int N,int M){
    vector<vector<int> >dp(N,vector<int>(M,-1)); // here source keeps on varying filling the lower L first
    dp[N-1][M-1]=cost[N-1][M-1];
    for(int i=N-2;i>=0;i--)
        dp[i][M-1]=cost[i][M-1]+dp[i+1][M-1];
    for(int j=M-2;j>=0;j--)
        dp[N-1][j]=cost[N-1][j]+dp[N-1][j+1];
    for(int i=N-2;i>=0;i--){
        for(int j=M-2;j>=0;j--){
            dp[i][j]=cost[i][j]+min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
        }
    }
    return dp[0][0];
}
int main(){
    int N,M, cost[100][100];
    cout<<"Enter matrix dimensions: ";
    cin>>N>>M;
    cout<<"Enter cost matrix: ";

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>cost[i][j];
        }
    }
    cout<<"Min Cost Path is: "<<endl;
    cout<<minCostPath(0,0,N,M,cost)<<endl;
    cout<<minCostPath(N-1,M-1,cost)<<endl;
    cout<<minCostPathTabulation1(cost,N,M)<<endl;
    cout<<minCostPathTabulation2(cost,N,M)<<endl;
    return 0;
}


