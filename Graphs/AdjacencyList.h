#ifndef ADJACENCYLIST_H_INCLUDED
#define ADJACENCYLIST_H_INCLUDED
#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

//UNDIRECTED GRAPH ~ADJACENCY LIST REPRESENTATION

    /*********************************************************************************************************************************
    Representing a graph with adjacency lists combines adjacency matrices with edge lists. For each vertex ii, store an array of 
    the vertices adjacent to it. We typically have an array of |V|∣V∣ adjacency lists, one adjacency list per vertex.

    We can get to each vertex's adjacency list in constant time, because we just have to index into an array. To find 
    out whether an edge (i,j)(i,j) is present in the graph,we go to ii's adjacency list in constant time and then look for jj in 
    ii's adjacency list. How long does that take in the worst case? The answer is Theta(d)Θ(d), where
    dd is the degree of vertex ii, because that's how long ii's adjacency list is. The degree of vertex ii could be as 
    high as |V|-1∣V∣−1 (if ii is adjacent to all the other |V|-1∣V∣−1 vertices) or as low as 0 
    (if ii is isolated, with no incident edges). In an undirected graph, vertex jj is in vertex ii's adjacency list if and only 
    if ii is in jj's adjacency list.If the graph is weighted, then each item in each adjacency list is either a two-item array 
    or an object, giving the vertex number and the edge weight.

    How much space do adjacency lists take? We have |V|∣V∣ lists, and although each list could have as many as |V|-1∣V∣−1 vertices, 
    in total the adjacency lists for an undirected graph contain 2|E|2∣E∣ elements. Why 2|E|2∣E∣? Each edge (i,j)(i,j) appears 
    exactly twice in the adjacency lists, once in ii's list and once in jj's list,and there are |E|∣E∣ edges. For a directed graph, 
    the adjacency lists contain a total of |E|∣E∣ elements, one element per directed edge.
    *********************************************************************************************************************************/

class AdjacencyList{
    vector<list<int> >adList;
public:
    AdjacencyList(unsigned int N){
        adList.resize(N);
    }
    bool insertEdge(int src,int dest){
        if(src<0||src>=adList.size()||dest<0||dest>=adList.size())
            throw "Invalid Edge Provided";
        list<int>&temp=adList[src];
        if(find(temp.begin(),temp.end(),dest)==temp.end()){
            temp.push_back(dest);
            adList[dest].push_back(src);//comment this for directed graph
            return  true;
        }
        return false;
    }
    bool deleteEdge(int src,int dest){
        if(src<0||src>=adList.size()||dest<0||dest>=adList.size())
            throw "Invalid Edge Provided";
        list<int>&temp=adList[src];
        if(find(temp.begin(),temp.end(),dest)==temp.end())
            return false;
        temp.remove(dest);
        adList[dest].remove(src);
        return true;
    }
  /*time complexity is O(|V|+|E|) in average, but  in worst case when every node is connected to every other it takes O(|V|*|V|) time*/

    void printDFS(){
        vector<bool>visited(adList.size(),false);
        for(int i=0;i<adList.size();i++){
            if(!visited[i]){
                visited[i]=true;
                DFSHelper(i,visited);
            }
        }
    return;
    }

    void printBFS(){
        queue<int>Q;
        vector<bool>visited(adList.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                Q.push(i);
                while(!Q.empty()){
                    int value=Q.front();
                    Q.pop();
                    cout<<value<<" ";
                    list<int>&temp=adList[value];
                    for(list<int>::iterator it=temp.begin();it!=temp.end();it++){
                        if(!visited[*it]){
                            visited[*it]=true;
                            Q.push(*it);
                        }
                    }
                }
            }
        }
    return;
    }
    bool isThereAnyPath(int src,int dest){
        vector<bool>visited(adList.size(),false);
        visited[src]=true;
        DFSHelper(src,visited);
        return visited[dest];
    }
    bool isGraphConnected(){
        vector<bool>visited(adList.size(),false);
        visited[0]=true;
        DFSHelper(0,visited);
        for(int i=0;i<visited.size();i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
    
    void printAllPaths(int src,int dest){
        vector<bool>visited(adList.size(),false);
        visited[src]=true;
        printPaths(src,dest,visited);
        return;
    }

/**
 Q Given a directed weighted graph. You are also given the shortest path from a source vertex ‘s’ to a destination vertex ‘t’.  If weight of every edge is increased by 10 units,
does the shortest path remain same in the modified graph?

ANS: The shortest path may change. The reason is, there may be different number of edges in different paths from s to t. For example, let shortest path be of weight 15 and has
5 edges. Let there be another path with 2 edges and total weight 25. The weight of the shortest path is increased by 5*10 and becomes 15 + 50. Weight of the other path is
increased by 2*10 and becomes 25 + 20. So the shortest path changes to the other path with weight as 45.



Q Does the shortest path change when weights of all edges are multiplied by 10?
ANS: If we multiply all edge weights by 10, the shortest path doesn’t change. The reason is simple, weights of all paths from s to t get multiplied by same amount.
The number of edges on a path doesn’t matter. It is like changing unit of weights.
   **/


    void printShortestPath(int src,int dest){
        queue<pair<int,int>>Q;
        vector<bool>visited(adList.size(),false);
        vector<int>parent(adList.size(),0);
        parent[src]=-1;
        Q.push(pair<int,int>(src,1));
        visited[src]=true;
        while(!Q.empty()){
            pair<int,int>P=Q.front();
            Q.pop();
            if(P.first==dest){
                cout<<"Shortest path length: "<<P.second<<endl;
                cout<<"Shortest path: ";
                print(parent,dest);
                return;
            }
            for(list<int>::iterator it=adList[P.first].begin();it!=adList[P.first].end();it++){
                if(!visited[*it]){
                    visited[*it]=true;
                    parent[*it]=P.first;

                    Q.push(pair<int,int>(*it,P.second+1));
                }
            }
        }
    return;
    }

     /// CHECK IF A GRAPH IS BIPARATITE OR NOT

//A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V
///or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is
///no edge that connects vertices of same set.

///A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. Note that it is possible
///to color a cycle graph with even cycle using two colors. For example, see the following graph.

///It is not possible to color a cycle graph with odd cycle using two colors

///One approach is to check whether the graph is 2-colorable or not using backtracking algorithm m coloring problem.

/**

Vertex coloring is the most common graph coloring problem. The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are
colored using same color. The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same color) and Face Coloring (Geographical Map Coloring)
can be transformed into vertex coloring.

Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 3 colors.

Suduku: Suduku is also a variation of Graph coloring problem where every cell represents a vertex. There is an edge between two vertices if they are in same row or
same column or same block.
  **/

    bool isBiparatite(){
        vector<int>color(adList.size(),-1);
        queue<int>Q;
        for(int i=0;i<color.size();i++){
            if(color[i]==-1){
                color[i]=1;
                Q.push(i);
                while(!Q.empty()){
                    int temp=Q.front();
                    Q.pop();
                    list<int>&adj=adList[temp];
                    for(list<int>::iterator it=adj.begin();it!=adj.end();it++){
                        if(color[*it]==-1){
                            color[*it]=1-color[temp];
                            Q.push(*it);
                        }
                        else if(color[*it]==color[temp]){
                            return false;
                        }
                    }
                }
            }
            
        }
    return true;
    }
   
    bool isCyclePresent(){
        vector<bool>visited(adList.size(),false);
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i]=true;
                if(isCycleHelper(i,visited,-1))
                    return true;
            }
        }
        return false;
    }

   
private:
    
    bool isCycleHelper(int src,vector<bool>&visited,int parent){
        list<int>&adj=adList[src];
        for(list<int>::iterator it=adj.begin();it!=adj.end();it++){
            if(visited[*it]&&*it!=parent)
                return true;
        }
        for(list<int>::iterator it=adj.begin();it!=adj.end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                if(isCycleHelper(*it,visited,src))
                    return true;
            }
        }
        return false;
    }

    void print(vector<int>parent,int dest){
        if(parent[dest]==-1){
            cout<<dest<<" ";
            return;
        }
        print(parent,parent[dest]);
        cout<<dest<<" ";
    }

    void printPaths(int src,int dest,vector<bool>&visited){
        static vector<int>path;
        path.push_back(src);
        if(src==dest){
            for(vector<int>::iterator it=path.begin();it!=path.end();it++){
                cout<<*it<<" ";
            }
            cout<<endl;
            return;
        }
        for(list<int>::iterator it=adList[src].begin();it!=adList[src].end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                printPaths(*it,dest,visited);
                visited[*it]=false;
                path.pop_back();
            }
        }
        return;
    }
                
    void DFSHelper(int src,vector<bool>&visited){
        cout<<src<<" ";
        list<int>&temp=adList[src];
        for(list<int>::iterator it=temp.begin();it!=temp.end();it++){
            if(!visited[*it]){
                visited[*it]=true;
                DFSHelper(*it,visited);
            }
        }
        return;
    }

};

#endif
