/*
Method 1 (Simple)
A simple approach is to check each row with all processed rows. Print the first row. Now, starting from the second row, for each row, compare the row with already processed rows. If the row matches 
with any of the processed rows, don’t print it. If the current row doesn’t match with any row, print it.

Time complexity: O( ROW^2 x COL )
Auxiliary Space: O( 1 )

Method 2 (Use Binary Search Tree)
Find the decimal equivalent of each row and insert it into BST. Each node of the BST will contain two fields, one field for the decimal value, other for row number. Do not insert a node if it is 
duplicated. Finally, traverse the BST and print the corresponding rows.

Time complexity: O( ROW x COL + ROW x log( ROW ) )
Auxiliary Space: O( ROW )
**/

//Method1
#include<iostream>
#include<map>
#include<cmath>
using namespace std;
void simple(bool matrix[][100],int ROW,int COL){
    for(int i=0;i<ROW;i++){
        int j;
        for( j=0;j<i;j++){
           int k;
            for( k=0;k<COL;k++){
                if(matrix[i][k]!=matrix[j][k])
                    break;
            }
            if(k==COL)
                break;
           
        }
        if(j==i){
            for(int k=0;k<COL;k++){
                cout<<matrix[i][k]<<" ";
            }
       cout<<endl;
        }
        
    }
    return;
}

void usingBST(bool matrix[][100],int ROW,int COL){
    map<int,int>M;
    for(int i=0;i<ROW;i++){
        int temp=0;
        for(int j=0;j<COL;j++){
            temp=temp+matrix[i][j]*pow(2,COL-1-j);
        }
        M[temp]=i;
    }
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++){
        cout<<"("<<it->second<<","<<it->first<<")"<<endl;
    }
    cout<<endl<<endl;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++){
        for(int i=0;i<COL;i++){
            cout<<matrix[it->second][i]<<" ";
        }
        cout<<endl;
    }
    return;
}
   
int main(){
    bool matrix[100][100];
    int N,M;
    cout<<"Enter the dimensions(N*M): ";
    cin>>N>>M;
    cout<<"Enter the boolean matrix:  ";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"unique rows are: "<<endl;
    //simple(matrix,N,M);
    usingBST(matrix,N,M);
    return 0;
}
