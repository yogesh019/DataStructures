#include"AdjacencyMatrix.h"
int main(){
    AdjacencyMatrix G(8),G1(5);
    /*
    AdjacencyMatrix G2(9);
    G2.insertEdge(0,1,4);
    G2.insertEdge(0,7,8);
    G2.insertEdge(1,0,4);
    G2.insertEdge(1,7,11);
    G2.insertEdge(2,1,8);
    G2.insertEdge(2,3,7);
    G2.insertEdge(2,5,4);
    G2.insertEdge(2,8,2);
    G2.insertEdge(3,4,9);
    G2.insertEdge(3,5,14);
    G2.insertEdge(4,3,9);
    G2.insertEdge(4,5,10);
    G2.insertEdge(5,2,4);
    G2.insertEdge(5,4,10);
    G2.insertEdge(5,6,2);
    G2.insertEdge(6,3,14);
    G2.insertEdge(6,5,2);
    G2.insertEdge(6,7,1);
    G2.insertEdge(6,8,6);
    G2.insertEdge(7,0,8);
    G2.insertEdge(7,1,11);
    G2.insertEdge(7,6,1);
    G2.insertEdge(7,8,7);
    G2.insertEdge(8,2,2);
    G2.insertEdge(8,6,6);
    G2.insertEdge(8,7,7);
   
    G2.dijikstra(0);
    */
    int edges[][2]={{0,1},{0,2},{0,3},{2,3},{1,4},{2,4},{3,4},{5,6},{6,7},{5,7}};
    for(int i=0;i<10;i++){
        G.insertEdge(edges[i][0],edges[i][1]);
    }
    G.printDFSTraversal();
    cout<<endl;
    G.printDFSUsingStack();
    cout<<endl;
    G.printBFSTraversal();
    cout<<endl;
    
    if(G.isThereAnyPath(0,5)){ 
        cout<<"path exists"<<endl;
    }else{
        cout<<"no path exists"<<endl;
    }
    G.insertEdge(4,5);
    G.printAllPaths(0,4);
    
    cout<<endl;
    cout<<endl;
  
   G1.insertEdge(1,0);
   G1.insertEdge(0,2);
   G1.insertEdge(2,1);
   G1.insertEdge(0,3);
   G1.insertEdge(3,4);
 

    if(G1.isStronglyConnected()){
        cout<<"graph is strongly connected"<<endl;
    }else{
        cout<<"graph is not strongly connected"<<endl;
    }
    cout<<endl<<endl;
    //G.printShortestPath(0,4);
    G1.printComponents();    
    

    return 0;
}
    
