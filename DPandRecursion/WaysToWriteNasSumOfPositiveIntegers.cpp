#include<iostream>
using namespace std;

/**
Print all unique integer partitions given an integer as input.
Integer partition is a way of writing n as a sum of positive integers.
for ex: Input=4 then output should be Output=

  1 1 1 1
  1 1 2
  2 2
  1 3
  4
  Note : This is different from problem: print all subsets of N with sum to N, which do not consider distinct combinations
  It considers distinct combinations

 The process is recursive. There is a single partition of 0, the empty set (). There is a single partition of 1, the set (1). 
 There are two partitions of 2, the sets (1 1) and (2).
 There are three partitions of 3, the sets (1 1 1), (1 2) and (3). 
 There are five partitions of 4, the sets (1 1 1 1), (1 1 2), (1 3), (2 2), and (4).
 There are seven partitions of 5, the sets (1 1 1 1 1), (1 1 1 2), (1 2 2), (1 1 3), (1 4), (2 3) and (5). And so on.
 In each case, the next-larger set of partitions is determined by adding each integer x less than or equal to the 
 desired integer n to all the sets formed by the partition of n − x,eliminating any duplicates.
 */

int Count=0;
void printWays(int N,int Max,int *res,int index){
    if(!N){
        Count++;
        cout<<"{";
        for(int i=0;i<index;i++){
            cout<<res[i]<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    for(int i=1;i<=N&&i<=Max;i++){
        res[index]=i;
        printWays(N-i,i,res,index+1);
    }
    return;
}
int main(){
    int N,res[100];
    cout<<"Enter N: ";
    cin>>N;
    printWays(N,N,res,0);
    cout<<"Number of ways are: "<<Count;
    return 0;
}



