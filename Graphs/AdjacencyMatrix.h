#ifndef ADJACENCYMATRIX_H_INCLUDED
#define ADJACENCYMATRIX_H_INCLUDED
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<limits>

using namespace std;

//DIRECTED GRAPH ADJACENCY MATRIX REPRESENTATION
class AdjacencyMatrix{
    vector<vector<int> >Matrix;
    
    void DFSHelper(int src,vector<bool>&visited){
        //cout<<src<<" ";
        for(int i=0;i<Matrix.size();i++){
            if(Matrix[src][i]&&!visited[i]){
                visited[i]=true;
                DFSHelper(i,visited);
            }
        }
        return;
    }
    static void DFSHelper(int src,vector<bool>&visited,AdjacencyMatrix&G){
        cout<<src<<" ";
        for(int i=0;i<G.Matrix.size();i++){
            if(G.Matrix[src][i]&&!visited[i]){
                visited[i]=true;
                DFSHelper(i,visited,G);
            }
        }
        return;
    }
public:
    AdjacencyMatrix(unsigned int N){
        Matrix.resize(N);
        for(int i=0;i<N;i++){
            Matrix[i].resize(N,0);
        }
        return;
    }
    void insertEdge(int src,int dest,int value=1){
        if(src<0||src>Matrix.size()||dest<0||dest>Matrix.size())
            throw "Invalid Edge Provided!";
        Matrix[src][dest]=value;
    }

/* DFS takes O(|V|*|V|) time,better than Edge-List but not better than adjacency list which takes O(|V|*|V|) in worst case, 
where every node is connected to every other bode ,but in average adjacency list takes O(|V|+|E|) time
*/
    void printDFSTraversal(){
        vector<bool>visited(Matrix.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                DFSHelper(i,visited,*this);
            }
        }
        return;
    }

    void printDFSUsingStack(){
        stack<int>S;
        vector<bool>visited(Matrix.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                S.push(i);
                while(!S.empty()){
                    int temp=S.top();
                    S.pop();
                    cout<<temp<<" ";
                    for(int i=Matrix.size()-1;i>=0;i--){
                        if(Matrix[temp][i]&&!visited[i]){
                            visited[i]=true;
                            S.push(i);
                        }
                    }
                }
            }
        }
        return;
    }

/* BFS Time Complexity is O(|V|*|V|)
Breadth-first search is a traversal through a graph that touches all of the vertices reachable from a particular source vertex. 
In addition, the order of the traversal is such that the algorithm will explore all of the neighbors of a vertex before 
proceeding on to the neighbors of its neighbors. One way to think of breadth-first search is that it expands like a 
wave emanating from a stone dropped into a pool of water. Vertices in the same ``wave'' are the same distance from
the source vertex. A vertex is discovered the first time it is encountered by the algorithm. 
A vertex is finished after all of its neighbors are explored.
*/

    void printBFSTraversal(){
        queue<int>Q;
        vector<bool>visited(Matrix.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                Q.push(i);
                while(!Q.empty()){
                    int temp=Q.front();
                    Q.pop();
                    cout<<temp<<" ";
                    for(int i=0;i<Matrix.size();i++){
                        if(Matrix[temp][i]&&!visited[i]){
                            visited[i]=true;
                            Q.push(i);
                        }
                    }
                }
            }
        }
    return;
    }

/**For any possible path, DFS would be enough. But, BFS gives you the shortest path between the two vertices. 
 * In either of these algorithms, you need to just make aminor addition to the code to make it suitable to 
 * help you print the path between two vertices. You need to maintain an array prev[n] (n=number of vertices in the graph),
which will record the vertex that was previously visited to reach vertex i (1<=i<=n).
The purpose of this array is that, every time a new vertex j is visited, prev[j] is updated to i (where i is the vertex visited before j).

After the traversal is done, you can write a simple while loop to print the path. Here is a pseudocode to print the
path from vertex i to j :

//after traversal is done
x = j
while (x!=i)
    print x->
    x = prev[x]
print x

If you need to find the path between only two vertices for your problem, then you could optimize the code by calling 
DFS(x) or BFS(x), where x is your source vertex and
stop the execution of the traversal once your destination, say y, is reached.
**/



    void printAllPaths(int src,int dest){
        vector<bool>visited(Matrix.size(),false);
        visited[src]=true;
        printPathHelper(src,dest,visited);
        return;
    }

    bool isThereAnyPath(int src,int dest){
        vector<bool>visited(Matrix.size(),false);
        visited[src]=true;
        DFSHelper(src,visited);
       return visited[dest]?true:false;
    }

// Check if the given directed graph is strongly connected or not
/*
We can also do DFS V times starting from every vertex. If any DFS, doesn’t visit all vertices, then graph is not strongly connected. 
This algorithm takes O(V*(V+E)) time which can be same as transitive closure for a dense graph.

A better idea can be Strongly Connected Components (SCC) algorithm. We can find all SCCs in O(V+E) time. 
If number of SCCs is one, then graph is strongly connected. The algorithm for SCC does extra work as it finds all SCCs.

Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph:
1) Initialize all vertices as not visited.

2) Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.

3) Reverse all arcs (or find transpose or reverse of graph)

4) Mark all vertices as not-visited in reversed graph.

5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). If DFS traversal doesn’t visit all vertices, 
then return false. Otherwise return true.

The idea is, if every node can be reached from a vertex v, and every node can reach v, then the graph is strongly connected. 
In step 2, we check if all vertices are reachable from v. In step 4, we check if all vertices can reach v 
(In reversed graph, if all vertices are reachable from v, then all vertices can reach v in original graph).
*/
    
// In the undirected graph we simply have to do DFS or BFS to check if the graph is connected or not

    bool isStronglyConnected(){
        vector<bool>visited(Matrix.size(),false);
        visited[0]=true;
        DFSHelper(0,visited);
        for(int i=1;i<Matrix.size();i++){
            if(!visited[i])
                return false;
        }
        AdjacencyMatrix G=reverseGraph();
        for(int i=0;i<Matrix.size();i++){
           visited[i]=false;
        }
        visited[0]=true;
        DFSHelper(0,visited,G);
        for(int i=1;i<Matrix.size();i++){
            if(!visited[i])
                return false;
        }
        return true;

    }
                                                        //if the graph is not weighted , all the edges are of same weight
                                                        //simply apply BFS
    void printShortestPath(int src,int dest){
        vector<bool>visited(Matrix.size(),false);
        visited[src]=true;
        vector<int>parent(Matrix.size(),0);
        parent[src]=-1;
        queue<pair<int,int> >Q;
        Q.push(pair<int,int>(src,0));
        while(!Q.empty()){
            pair<int,int> temp=Q.front();
            Q.pop();
            if(temp.first==dest){
                cout<"shortest path : ";
                printPath(dest,parent);
                cout<<endl;
                cout<<"shortest path length is: "<<temp.second<<endl;
                return;
            }

            for(int i=0;i<Matrix.size();i++){
                if(Matrix[temp.first][i]&&!visited[i]){
                    parent[i]=temp.first;
                    visited[i]=true;
                    Q.push(pair<int,int>(i,temp.second+1));
                }
            }
        }
        return;
    }


  //Prim's minimum spanning tree ~ Greedy Algorithm

    int min_index(vector<int>&key,vector<bool>&visited){
        int temp=numeric_limits<int>::max();
        int index;
        for(int i=0;i<key.size();i++){
            if(!visited[i]&&key[i]<temp){
                temp=key[i];
                index=i;
            }
        }
        return index;
    }

    void printMST(){
        vector<bool>visited(Matrix.size(),false);
        vector<int>key(Matrix.size(),numeric_limits<int>::max());
        vector<int>parent(Matrix.size());
        key[0]=0;
        parent[0]=-1;
        int count=0;
        while(count<=Matrix.size()-1){
            int index=min_index(key,visited);
            visited[index]=true;
            for(int i=0;i<Matrix[index].size();i++){
                if(Matrix[index][i]&&Matrix[index][i]<key[i]&&!visited[i]){
                    parent[i]=index;
                    key[i]=Matrix[index][i];
                }
            }
            count++;
        }
        cout<<endl;
        cout<<"Edge Weight"<<endl;
        for(int i=1;i<parent.size();i++){
            cout<<parent[i]<<"-"<<i<<" "<<Matrix[parent[i]][i]<<endl;
        }
    return;
    }

    void dijikstra(int src){
        vector<int>key(Matrix.size(),numeric_limits<int>::max());
        vector<bool>visited(Matrix.size(),false);
        vector<int>parent(Matrix.size());
        key[src]=0;
        parent[src]=-1;
        int count=0;
        while(count<=Matrix.size()-1){
            int index=min_index(key,visited);
            visited[index]=true;
            vector<int>adj=Matrix[index];
            for(int i=0;i<adj.size();i++){
                if(adj[i]&&key[index]+adj[i]<key[i]){
                    key[i]=key[index]+adj[i];
                    parent[i]=index;
                }
            }
            count++;
        }
        cout<<endl;
        cout<<"Vertex Distance Path"<<endl;
        for(int i=0;i<Matrix.size();i++){
            cout<<src<<"-->"<<i<<" "<<key[i]<<"  ";
            printPath(i,parent);
            cout<<endl;
        }
return;
    }

//print strongly connected components

    void printComponents(){
        stack<int>S;
        vector<bool>visited(Matrix.size(),false);
        for(int i=0;i<Matrix.size();i++){
            if(!visited[i]){
                visited[i]=true;
                fillStack(i,visited,S);
            }
        }
        for(int i=0;i<Matrix.size();i++){
            visited[i]=false;
        }
        AdjacencyMatrix G=reverseGraph();
        while(!S.empty()){
            int temp=S.top();
            S.pop();
            if(!visited[temp]){
                visited[temp]=true;
                DFSHelper(temp,visited,G);
                cout<<endl;
            }
            
        }
    }

    bool checkCycle(){
        vector<bool>visited(Matrix.size(),false),recStack(Matrix.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                if(checkCycleHelper(i,visited,recStack))
                    return true;
            }
        }
    return false;
    }

private:
    
    
    bool checkCycleHelper(int src,vector<bool>&visited,vector<bool>&recStack){
        recStack[src]=true;
        for(int i=0;i<Matrix.size();i++){
            if(Matrix[src][i]&&recStack[i])
                return true;
        }

        for(int i=0;i<Matrix.size();i++){
            if(Matrix[src][i]&&!visited[i]){
                    visited[i]=true;
                    if(checkCycleHelper(i,visited,recStack))
                        return true;
            }
        }
        recStack[src]=false;
    return false;
    }
    
     void fillStack(int src,vector<bool>&visited,stack<int>&S){
        for(int i=0;i<Matrix.size();i++){
            if(Matrix[src][i]&&!visited[i]){
                visited[i]=true;
                fillStack(i,visited,S);
            }
        }
        S.push(src);
        return;
    }
    static void printPath(int vertex,vector<int>&parent){
        if(parent[vertex]==-1){
            cout<<vertex;
            return;
        }
        printPath(parent[vertex],parent);
        cout<<" "<<vertex;
    }

    AdjacencyMatrix reverseGraph(){
          AdjacencyMatrix G(Matrix.size());
          for(int i=0;i<Matrix.size();i++){
              for(int j=0;j<Matrix.size();j++){
                  G.Matrix[j][i]=Matrix[i][j];
              }
          }
          return G;
    }

    void printPathHelper(int src,int dest,vector<bool>&visited){
        static vector<int>path;
        path.push_back(src);
        if(src==dest){
            for(vector<int>::iterator it=path.begin();it!=path.end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
        return;
        }
        for(int i=0;i<Matrix.size();i++){
            if(Matrix[src][i]&&!visited[i]){
                visited[i]=true;
                printPathHelper(i,dest,visited);
                visited[i]=false;
                path.pop_back();
            }
        }
    return;
    }


    


};

#endif
