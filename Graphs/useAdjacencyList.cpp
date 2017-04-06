#include"AdjacencyList.h"
int main(){
    try{
    AdjacencyList G(8);
    int edges[][2]={{0,1},{0,2},{0,3},{2,3},{1,4},{2,4},{3,4},{5,6},{6,7},{5,7},{4,5}};
    for(int i=0;i<10;i++){
        G.insertEdge(edges[i][0],edges[i][1]);
    }
    cout<<"DFS Traversal: ";
    G.printDFS();
    cout<<endl;
    
    G.printBFS();
    cout<<endl;
    if(G.isGraphConnected()){
        cout<<"graph is connected"<<endl;
    }else{
        cout<<"graph is not connected"<<endl;
    }
    
    cout<<G.isThereAnyPath(0,1);
    cout<<endl;
    cout<<"paths between 0 and 4: "<<endl;
    G.printAllPaths(0,4);
    cout<<endl<<endl;
    cout<<"Shortest path between 0 and 4: "<<endl;
    G.printShortestPath(0,4);
    cout<<endl<<endl;
    G.deleteEdge(0,2);
    G.deleteEdge(2,3);
    G.deleteEdge(2,4);
    G.deleteEdge(5,6);
    G.deleteEdge(6,7);
    G.deleteEdge(5,7);
    if(G.isBiparatite()){
        cout<<"Graph is Biparatite"<<endl;
    }else{
        cout<<"not biparatite"<<endl;
    }
    cout<<endl;
    G.deleteEdge(0,1);
    if(G.isCyclePresent()){
        cout<<"cycle present"<<endl;
    }
    else{
        cout<<"cycle not present"<<endl;
    }

    }catch(const char*str){
        cout<<str<<endl;
    }
    return 0;
}

