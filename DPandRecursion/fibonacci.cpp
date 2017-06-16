#include<iostream>
#include<vector>
using namespace std;

void printFibonacci(int N){
    int x=0,y=1;
    while(x<=N){
       int z=x+y;
       cout<<x<<" ";
       x=y;
       y=z;
    }
    return;
}
void printFibonacciRecursive(int  x,int y,int N){
    if(x>N)return;
    cout<<x<<" ";
    printFibonacciRecursive(y,x+y,N);
    return;
}

int fibo(int N){    
    return N<=1?N:fibo(N-1)+fibo(N-2);
}   // Time Complexity is Exponential

int fiboDP(int N){
    static vector<int>dp(N+1,0);          
    if(N<=1)return N;
    if(dp[N])return dp[N];

    return dp[N]=fibo(N-1)+fibo(N-2);
}// Memoization:- Top Down Approach , Time Complexity is O(n) but compromises space

int fiboTabulation(int N){
    vector<int>dp(N+1);
    dp[0]=0;                    // Filling the table ,Bottom Up Approach
    dp[1]=1;
    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[N];
}

int computeFibo(int N){
    int x=0,y=1;
    while(N--){
        int z=x+y;
        x=y;
        y=z;
    }
    return x;
}

int main(){
    int N;
    cout<<"Enter the number up to which you want to print fibonacci series:";
    cin>>N;
    printFibonacci(N);
    cout<<endl;
    printFibonacciRecursive(0,1,N);
    cout<<endl;
    cout<<"Nth fibonacci number is: ";
    cout<<fibo(N);

    cout<<endl;
    cout<<fiboDP(N);
    cout<<endl;
    cout<<fiboTabulation(N);
    cout<<endl;
    cout<<computeFibo(N);
    cout<<endl;
    return 0;
}
    
