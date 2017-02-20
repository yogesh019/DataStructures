#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

bool isSafe(char board[][100],int N,int row,int col){
   for(int i=0;i<col;i++){
       if(board[row][i])return false;
   }
   for(int  i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
       if(board[i][j])return false;
   }
   for(int i=row+1,j=col-1;i<N&&j>=0;i++,j--){
       if(board[i][j])return false;
   }
   return true;
}
void printSolution(char board[][100],int N){
    for(int i=0;i<N;i++){
        cout<<"+";
        for(int k=0;k<N;k++){
            cout<<"-----+";
        }
        cout<<endl<<"|";
        for(int j=0;j<N;j++){
            if(!board[i][j])cout<<setw(4)<<" ";
            else cout<<setw(4)<<board[i][j];
            cout<<" |";
        }
        cout<<endl;
    }
    cout<<"+";
    for(int k=0;k<N;k++){
        cout<<"-----+";
    }
    cout<<endl<<endl;
    
    return;
}

bool NQueen(char board[][100],int N,int col){
    if(col==N){
        return true;
    }
    for(int i=0;i<N;i++){
        if(isSafe(board,N,i,col)){
            board[i][col]='Q';
            if(NQueen(board,N,col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}
int main(){
    char board[100][100]={0};
    int testcases,N;
    cout<<setw(38)<<"+----------+"<<endl<<setw(27)<<"|";
    cout<<setw(5)<<"  NQueen!"<<setw(2)<<"|"<<endl;
    cout<<setw(38)<<"+----------+"<<endl<<endl;

    cout<<"Enter the number of testcases: ";
    cin>>testcases;
    while(testcases--){
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                board[i][j]=0;
            }
        }
        cout<<"Enter the board size(N*N): ";
        cin>>N;
        if(NQueen(board,N,0)){
            printSolution(board,N);
        }
        else{
            cout<<"Solution does not exits!"<<endl;
        }
    }
    return 0;
}
