#ifndef EDGELIST_H_INCLUDED
#define EDGELIST_H_INCLUDED
#include<iostream>
#include<set>
#include<unordered_set>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

/* Undirected Graph Edge-List Representation*/
class EdgeList{
    set<char>Vertices;
    set<pair<char,char> >Edges;

    /*This function cannot be static as it is calling a method getADjacentVertices of a Graph*/
    void DFSHelper(char src,unordered_set<char>&S){
        //cout<<src<<" ";
        vector<char>adj=getAdjacentVertices(src);
        for(int i=0;i<adj.size();i++){
            if(S.find(adj[i])==S.end()){
                S.insert(adj[i]);
                DFSHelper(adj[i],S);
            }
        }
        return;
    }
    static void DFSHelper(char src,unordered_set<char>&S,const EdgeList&G){
        cout<<src<<" ";
        vector<char>adj=G.getAdjacentVertices(src);
        for(int i=0;i<adj.size();i++){
            if(S.find(adj[i])==S.end()){
                S.insert(adj[i]);
                DFSHelper(adj[i],S,G);
            }
        }
    return;
    }

public:
    void insertEdge(char src,char dest){
        Vertices.insert(src);
        Vertices.insert(dest);                          // O(logn) time 
        if(Edges.find(pair<char,char>(dest,src))==Edges.end())
            Edges.insert(pair<char,char>(src,dest));
        return;
    }
    vector<char>getAdjacentVertices(char src)const{
        vector<char>adj;                        // Time complexity is O(|E|)
        for(set<pair<char,char> >::iterator it=Edges.begin();it!=Edges.end();it++){
            if(it->first==src)
                adj.push_back(it->second);
            else if(it->second==src)
                adj.push_back(it->first);
            
        }
        return adj;
    }
    void printAllVertices(){
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    void printDFSTaversal(){
        unordered_set<char>S; // Time complexity is O(|V|*|E|)
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            if(S.find(*it)==S.end()){
                S.insert(*it);
                DFSHelper(*it,S,*this);
            }
        }
        return;
    }
    
    
    void printDFSUsingStack(){
        unordered_set<char>check;
        stack<char>S;
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            if(check.find(*it)==check.end()){
                check.insert(*it);
                S.push(*it);
                while(!S.empty()){
                    char ch=S.top();
                    S.pop();
                    cout<<ch<<" ";
                    vector<char>adj=getAdjacentVertices(ch);
                    for(vector<char>::reverse_iterator it=adj.rbegin();it!=adj.rend();it++){// to get the same result as that of DFS using Recursion
                        if(check.find(*it)==check.end()){
                            S.push(*it);
                            check.insert(*it);
                        }
                    }
                }
            }
        }
        return;
    }

    void printBFSTraversal(){
        unordered_set<char>S;
        queue<char>Q;
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            if(S.find(*it)==S.end()){
                S.insert(*it);
                Q.push(*it);
                while(!Q.empty()){
                    char ch=Q.front();
                    Q.pop();
                    cout<<ch<<" ";
                    vector<char>adj=getAdjacentVertices(ch);
                    for(vector<char>::iterator it=adj.begin();it!=adj.end();it++){
                        if(S.find(*it)==S.end()){
                            S.insert(*it);
                            Q.push(*it);
                        }
                    }
                }
            }
        }
        return;
    }

    /* time complexity is O(|V|*|E|)
     * this approach can be used for directed graph also , we do a DFS  or BFS trversal starting from a src vertex and if the dest
     * vertex is found in the traversal we return true else false
     */
    bool isThereAnyPath( char src,char dest){
        unordered_set<char>S;
        S.insert(src);
        DFSHelper(src,S);
        return S.find(dest)==S.end()?false:true;
    }

    /* It's simple for an undirected graph : we can simply do DFS or BFS starting from any vertex to check the graph is connected or not
     *
     * But if the graph is irected , we have to check that is it strongly connected or not
     */

    bool isGraphConnected(){
        unordered_set<char>check;
        check.insert(*Vertices.begin());
        DFSHelper(*Vertices.begin(),check);
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            if(check.find(*it)==check.end())
                return false;
        }
        return true;
    }

    void shortestPathLength(char src,char dest){
        queue<pair<char,int> >Q;
        unordered_set<char>S;
        S.insert(src);
        Q.push(pair<char,int>(src,0));
        while(!Q.empty()){
            pair<char,int>P=Q.front();
            if(P.first==dest){
                cout<<"shortest path length is: "<<P.second;
                return;
            }
            Q.pop();
            vector<char>adj=getAdjacentVertices(P.first);
            for(vector<char>::iterator it=adj.begin();it!=adj.end();it++){
                if(S.find(*it)==S.end()){
                    S.insert(*it);
                    Q.push(pair<char,int>(*it,P.second+1));
                }
            }
        }
        cout<<"path not found!";
        return;
    
    }

/* Depth First Traversal can be used to detect cycle in a Graph. DFS for a connected graph produces a tree. 
 * There is a cycle in a graph only if there is a back edge present in the graph. 
 * A back edge is an edge that is from a node to itself (selfloop) or one of its ancestor in the tree produced by DFS.


Note : BFS can't be use to detect the cycle in a directed graph
Also if your graph is directed then you have to not just remember if you have visited a node or not, but also how you got there.
Otherwise you might think you have found a cycle but in reality all you have is two separate paths A->B 
but that doesn't mean there is a path B->A.
With a depth first search you can mark nodes as visited as you descend and unmark them as you backtrack.

BFS wont work for a directed graph in finding cycles. Consider A->B and A->C->B as paths from A to B in a graph. 
BFS will say that after going along one of the path that B is visited. When continuing 
to travel the next path it will say that marked node B has been again found,hence, a cycle is there. Clearly there is no cycle here.
*/

// FOR UNDIRECTED GRAPH
/* We do a DFS Traversal of the given graph.For every visited vertex 
'v',if there  is an adjacent 'u',such that u is already visited and
 u is not parent of v,then there is a cycle in a graph.If we don't find
such an adjacent for any vertex, there is no cycle
*/
         
    bool isCyclePresent(){
        unordered_set<char>S;
        for(set<char>::iterator it=Vertices.begin();it!=Vertices.end();it++){
            if(S.find(*it)==S.end()){
                S.insert(*it);
                if(isCycleHelper(*it,'\0',S))
                    return true;
          }
        }
        return false;
    }

/*bool*/void  printAllPaths(char src,char dest){
        unordered_set<char>S;
        S.insert(src);
        //return printAllPathsHelper(src,dest,S)?printAllPathsHelper(src,dest,S):false;
        printAllPathsHelper(src,dest,S);
        return;
    }

    void printShortestPath(char src,char dest){
        unordered_set<char>S;
        unordered_map<char,char>M;
        M[src]='\0';
        S.insert(src);
        queue<char>Q;
        Q.push(src);
        while(!Q.empty()){
            char ch=Q.front();
            Q.pop();
            if(ch==dest){
                printPath(M,ch);
                return;
            }
            vector<char>adj=getAdjacentVertices(ch);
            for(vector<char>::iterator it=adj.begin();it!=adj.end();it++){
                if(S.find(*it)==S.end()){
                    S.insert(*it);
                    M[*it]=ch;
                    Q.push(*it);
                }
            }
        }
        return;
    }




    

private:
    
        static void printPath(unordered_map<char,char>&M,char ch){
           if(ch=='\0'){
               return;
           }
           printPath(M,M[ch]);
           cout<<ch<<" ";
           return;
        }
    
 /*bool*/ void printAllPathsHelper(char src,char dest,unordered_set<char>&S){
        static vector<char>path;
        path.push_back(src);
        if(src==dest){
            for(vector<char>::iterator it=path.begin();it!=path.end();it++){
                cout<<(*it)<<" ";
            }
            cout<<endl;
            return;
            //return true;
        }
        vector<char>adj=getAdjacentVertices(src);
        for(vector<char>::iterator it=adj.begin();it!=adj.end();it++){
            if(S.find(*it)==S.end()){
                S.insert(*it);
                printAllPathsHelper(*it,dest,S);
                /*
                if(printAllPathsHelper(*it,dest,S)){
                    return true;
                }
                */
                path.pop_back();
                S.erase(*it);
            }
        }
        return;
        //return false;
    }
        
    bool isCycleHelper(char src,char parent,unordered_set<char>&S){
        vector<char>adj=getAdjacentVertices(src);
        for(int i=0;i<adj.size();i++){
            if(S.find(adj[i])!=S.end()&&adj[i]!=parent)
                return true;
        }
        for(vector<char>::iterator it=adj.begin();it!=adj.end();it++){
            if(S.find(*it)==S.end()){
                S.insert(*it);
                if(isCycleHelper(*it,src,S))
                    return true;
            }
        }
        return false;
    }




};

#endif
