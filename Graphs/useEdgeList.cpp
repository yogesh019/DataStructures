#include"EdgeList.h"
int main(){
    char edges[][2]={{'A','D'},{'A','C'},{'A','B'},{'B','E'},{'C','D'},{'D','E'},{'F','G'},{'G','H'},{'F','H'},{'C','E'},{'E','H'}};
    //char Edges[][2]={{'F','G'},{'G','H'},{'F','H'},{'D','E'}};
    EdgeList G;
    for(int i=0;i<11;i++){
        G.insertEdge(edges[i][0],edges[i][1]);
    }
    cout<<"Vertices: ";
    G.printAllVertices();
    cout<<endl;
    cout<<"BFS Traversal: ";
    G.printBFSTraversal();
    cout<<endl;
    cout<<"DFS Traversal using recursion: ";
    G.printDFSTaversal();
    cout<<endl;
    cout<<"DFS Traversal using stack: ";
    G.printDFSUsingStack();
    cout<<endl;
    if(G.isThereAnyPath('A','F')){
            cout<<"there exists a path!";
    }else{
        cout<<"no path exists ";
    }
    cout<<endl<<endl;
    if(G.isGraphConnected()){
        cout<<"graph is connected";
    }else{
        cout<<"graph is not connected!";
    }   

    cout<<endl;
    G.shortestPathLength('A','B');
    cout<<endl;
    if(G.isCyclePresent()){
        cout<<"cycle is present";
    }else{
        cout<<"Graphs does not contains any cycle";
    }
    cout<<endl;
    //G.printAllPaths('A','F');
    G.printShortestPath('A','E');
    cout<<endl;
    G.printShortestPath('A','D');
    cout<<endl;

    G.printShortestPath('A','G');

    return 0;
}


