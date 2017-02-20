#include<iostream>
using namespace std;

bool isSafe(int grid[][9],int row,int col,int num){
    for(int i=0;i<9;i++){
        if(grid[row][i]==num)
            return false;
    }
    for(int i=0;i<9;i++){
        if(grid[i][col]==num)
            return false;
    }
    int boxStartRow=row-row%3;
    int boxStartCol=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(grid[boxStartRow+i][boxStartCol+j]==num)
                return false;
        }
    }
    return true;
}

void printGrid(int grid[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
return;
}

bool findEmptyCells(int grid[][9],int &row,int &col){
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(grid[row][col]==0)
                return true;
        }
    }
    return false;
}

bool solveSudoku(int grid[][9]){
    int row,col;
    if(!findEmptyCells(grid,row,col))
        return true;
    for(int num=1;num<=9;num++){
        if(isSafe(grid,row,col,num)){
            grid[row][col]=num;
            if(solveSudoku(grid))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main(){
  int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  if(solveSudoku(grid)){
      printGrid(grid);
  }else{
      cout<<"Sudoku can't be solved!"<<endl;
  }
  return 0;
}
 
