/**
 SNAKE AND LADDER PROBLEM
The idea is to consider the given snake and ladder board as a directed graph with number of vertices equal to the number of 
cells in the board. The problem reduces to finding the shortest path in a graph. Every vertex of the graph has an edge to next six 
vertices if next 6 vertices do not have a snake or ladder.If any of the next six vertices has a snake or ladder, then the 
edge from current vertex goes to the top of the ladder or tail of the snake. Since all edges are of equal weight, we can 
efficiently find shortest path using Breadth First Search of the graph.
**/
//Time complexity is O(n)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int MinDiceThrows(int*moves,int N){
    queue<pair<int,int> >Q;
    vector<bool>visited(N,false);
    visited[0]=true;
    Q.push(pair<int,int>(0,0));
    while(!Q.empty()){
        pair<int,int>P=Q.front();
        Q.pop();
        if(P.first==N-1)
            return P.second;
        for(int i=P.first+1;i<=P.first+6;i++){
            if(!visited[i]){
                visited[i]=true;
                if(moves[i]==-1)
                    Q.push(pair<int,int>(i,P.second+1));
                else
                    Q.push(pair<int,int>(moves[i],P.second+1));
            }
        }
    }
}

int main(){
int moves[30];
    for(int i=0;i<30;i++){
        moves[i]=-1;
    }
/// Ladders
    moves[2]=21;
    moves[4]=7;
    moves[10]=25;
    moves[19]=28;

///Snakes

        moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout<<"Minimum DiceThrows are: "<<MinDiceThrows(moves,30);
    cout<<endl;
    return 0;
}
