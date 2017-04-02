#include<iostream>
using namespace std;
//COUNT NO OF ISLANDS IN A BINARY MATRIX
/*
This is not a graph. Here, we are creating an analogy between connected components concept of graphs, and this matrix.
 We need to find number of groups of connected ones. Hence, this matrix is viewed as a graph and problem is "mapped" to 
connected components. We visit each element of matrix one by one, and check, if it is not already visited, 
perform Depth First Search for this element to find all connected ones to this current element, 
the same concept as Connected Components in graph.
*/

//TIME COMPLEXITY IS O(ROW*COL)

int ROW,COL;

bool isSafe(int matrix[][100],int i,int j,bool visited[][100]){
    
    return i>=0&&i<ROW&&j>=0&&j<COL&&!visited[i][j]&&matrix[i][j]?true:false;
}

void DFS(int matrix[][100],int i,int j,bool visited[][100]){
    static int rowNb[]={-1,-1,-1,0,0,1,1,1};
    static int colNb[]={-1,0,1,-1,1,-1,0,1};
    for(int k=0;k<8;k++){
        if(isSafe(matrix,i+rowNb[k],j+colNb[k],visited)){
            visited[i+rowNb[k]][j+colNb[k]]=true;
            DFS(matrix,i+rowNb[k],j+colNb[k],visited);
        }
    }
    return;
}


int countIslands(int matrix[][100],int ROW,int COL){
    int count=0;
    bool visited[100][100]={false};
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(matrix[i][j]&&!visited[i][j]){
                visited[i][j]=true;
                DFS(matrix,i,j,visited);
                count++;
            }
        }
    }
    return count;
}


int main(){
    int matrix[100][100];
    cout<<"Enter the dimensions of matrix(ROW X COL): ";
    cin>>ROW>>COL;
    cout<<"Enter the boolean matrix: ";
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"No of islands are: "<<countIslands(matrix,ROW,COL);
    return 0;
}

