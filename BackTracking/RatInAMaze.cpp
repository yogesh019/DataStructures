/** RAT IN A MAZE: **/

/** when rat can move in only 2 directions that is either right or down then this problem is some what similar to a binary tree
where each node has 2 children and the children of the 2 nodes can also be common, time complexity of this program is optimized
by not going over and over again on the visited node, when we are at maze[x][y] and if both the recursive calls of the function
solveMaze return false , then there doesn't exist any path leading to destination from this node, so we set a flag[x][y] to true,
so when maze[x][y] is hit again during another recursive call(arriving from different path because children of the nodes are common
there is not a unique path from to a any node like binary tree), so we can altogether ignore the subsequent recursive calls
if maze[x][y] turns out to be true . here if we don't use this approach we will not get any problem but when rat can move  in all
possible directions we will get segmentation fault error because call stack becomes too big due to many levels of recursion
suppose this is a matrix
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
in the is safe function we first move down then up then right an then left
(0,0) is safe, move down (1,0), is safe the move up (0,0) is safe we revisited it again
and this goes on leading to segmentation fault , we will not get this problem when mice can move only right and down
if we don not inclue array for visited node because in this problem we have no path to go backword to a safer node from which we
have come and we wil not get segmentation fault**/


/** Backtracking approach : some what similar to depth first search , here we go deep  and then a node return false then we go along
the breadth i.e we check all it's brothers i.e all the chil dren of the same parent and then if it return false, we return false to parent
**/
/**when rat can move in all possible direction , then this problem is similar to solving a graph**/

#include<iostream>
using namespace std;

int Count=0;
bool isSafe(int maze[][100],int N,int M,int x,int y,bool visited[][100]){
    if(x>=0&&x<N&&y>=0&&y<M&&maze[x][y]==1&&visited[x][y]==false)
        return true;
    return false;
}


void printMaze(int maze[][100],int N,int M){
    cout<<endl<<endl;
    for(int  i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return;
}

bool solveMaze(int maze[][100],int N,int M,int x,int y,int sol[][100]){
    if(x==N-1&&y==M-1){
        Count++;
        sol[x][y]=1;
        printMaze(sol,N,M);
        return true;
    }
    static bool visited[100][100]={false};
    if(isSafe(maze,N,M,x,y,visited)){
        sol[x][y]=1;
        visited[x][y]=true;
        solveMaze(maze,N,M,x+1,y,sol);
        solveMaze(maze,N,M,x,y+1,sol);
        solveMaze(maze,N,M,x-1,y,sol);
        solveMaze(maze,N,M,x,y-1,sol);
        solveMaze(maze,N,M,x+1,y+1,sol);
        solveMaze(maze,N,M,x-1,y-1,sol);
        solveMaze(maze,N,M,x-1,y+1,sol);
        solveMaze(maze,N,M,x+1,y-1,sol);
        
        sol[x][y]=0;
        visited[x][y]=false;
    }
    return false;
}
int main(){
    int maze[100][100],testcases,N,M;
    cout<<"Enter the numberof testcases: ";
    cin>>testcases;
    while(testcases--){
        cout<<"Enter the dimensons of maze(N*M): ";
        cin>>N>>M;
        cout<<"Enter the maze: ";
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>maze[i][j];
            }
        }
        Count=0;
        int sol[100][100]={0};
        solveMaze(maze,N,M,0,0,sol);
        cout<<"Number of Solutions: "<<Count<<endl;
    }
    return 0;
}
       

        

