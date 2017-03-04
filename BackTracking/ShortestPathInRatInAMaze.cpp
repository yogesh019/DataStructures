#include<iostream>
#include<queue>
using namespace std;

bool isSafe(int maze[][100],int x,int y,int N,int M, bool visited[][100]){
    if(x>=0&&x<N&&y>=0&&y<M&&maze[x][y]&&!visited[x][y])
        return true;
    return false;
}
int main(){
    queue<pair<pair<int,int>,int> >Q;
    int maze[100][100],N,M;
    bool visited[100][100]={false};
    Q.push(make_pair(make_pair(0,0),0));
    cout<<"Enter the dimensions of maze(N*M): ";
    cin>>N>>M;
    cout<<"Enter the maze: ";
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>maze[i][j];
        }
    }
    while(!Q.empty()){
        pair<pair<int,int>,int>P=Q.front();
        Q.pop();
        if(P.first.first==N-1&&P.first.second==M-1){
            cout<<"shortest path length is: "<<P.second<<endl;
            break;
        }
        if(isSafe(maze,P.first.first+1,P.first.second,N,M,visited)){
            Q.push(make_pair(make_pair(P.first.first+1,P.first.second),P.second+1));
        }
        if(isSafe(maze,P.first.first,P.first.second+1,N,M,visited)){
            Q.push(make_pair(make_pair(P.first.first,P.first.second+1),P.second+1));
        }
        if(isSafe(maze,P.first.first+1,P.first.second+1,N,M,visited)){
            Q.push(make_pair(make_pair(P.first.first+1,P.first.second+1),P.second+1));
        }
    }
    return 0;
}
        

