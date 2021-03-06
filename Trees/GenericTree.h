#ifndef GENERICTREE_H_INCLUDED
#define GENERICTREE_H_INCLUDED
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class GenericTree;

template<typename T>
class GenericTreeNode{
public:
    T data;
    GenericTreeNode**children;
    GenericTreeNode*parent;
    unsigned int child_count;

    GenericTreeNode(const T&ele=0):data(ele),parent(0),child_count(0),children(0){}
    GenericTreeNode(const GenericTreeNode&G){
        data=G.data;
        child_count=G.child_count;
        parent=0;
        children=new GenericTreeNode<T>*[child_count];
        for(int i=0;i<child_count;i++){
            children[i]=new GenericTreeNode<T>(*G.children[i]);
            children[i]->parent=this;
        }
    }
    GenericTreeNode&operator=(const GenericTreeNode&G){
        for(int i=0;i<child_count;i++){
            delete children[i];
        }
        if(children)
            delete children;
        data=G.data;
        child_count=G.child_count;
        parent=0;
        children=new GenericTreeNode<T>[child_count];
        for(int i=0;i<child_count;i++){
            children[i]=new GenericTreeNode<T>(*G.children[i]);
            children[i]->parent=this;
        }
        return (*this);
    }
    
    ~GenericTreeNode(){
        for(int i=0;i<child_count;i++){
            delete children[i];
        }
        if(children)
            delete [] children;
        children=0;
    }
    
    friend class GenericTree<T>;
};

template<typename T>
class GenericTree{
    GenericTreeNode<T>*root;
    
    static void Clear(GenericTreeNode<T>*root){
        if(!root)return;
        for(int i=0;i<root->child_count;i++){
            Clear(root->children[i]);
        }
        delete [] root->children;
        delete root;
    }
    static GenericTreeNode<T>*DuplicateAs(GenericTreeNode<T>*root){
        GenericTreeNode<T>*temp=new GenericTreeNode<T>(root->data);
        temp->child_count=root->child_count;
        temp->children=new GenericTreeNode<T>*[temp->child_count];
        for(int i=0;i<temp->child_count;i++){
            temp->children[i]=DuplicateAs(root->children[i]);
        }
        return temp;
    }

public:
    GenericTree():root(0){}
    GenericTree(const GenericTree&G):root(0){
        root=new GenericTreeNode<T>(*G.root);
        //root=DuplicatAs(G.root);
    }
    GenericTree&operator=(const GenericTree&G){
        if(root)delete root;
        root=new GenericTreeNode<T>(*G.root);
        //if(root)Clear(root);
        //root=DuplicateAs(G.root);
    return(*this);
    }
    ~GenericTree(){
        if(root)
            delete root;
            //Clear(root);
        root=0;
    }

    void createTree(){
        T ele;                                  //taking input level wise
        cout<<"Enter root: ";
        cin>>ele;
        root=new GenericTreeNode<T>(ele);
        queue<GenericTreeNode<T>*>Q;
        Q.push(root);
        while(!Q.empty()){
            GenericTreeNode<T>*temp=Q.front();
            Q.pop();
            cout<<"Enter the child count of "<<temp->data<<": ";
            cin>>temp->child_count;
            temp->children=new GenericTreeNode<T>*[temp->child_count];
            for(int i=0;i<temp->child_count;i++){
                cout<<"Enter the "<<i+1<<" child of "<<temp->data<<": ";
                cin>>ele;
                temp->children[i]=new GenericTreeNode<T>(ele);
                temp->children[i]->parent=temp;
                Q.push(temp->children[i]);
            }
        }
    }

    void printTree(){                                //level wise printing , bfs     
        if(!root)return;
        queue<GenericTreeNode<T>*>Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            GenericTreeNode<T>*temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    cout<<endl;
                    Q.push(NULL);
                }
                continue;
            }
            cout<<temp->data<<" ";
            for(int i=0;i<temp->child_count;i++){
                Q.push(temp->children[i]);
            }
        }
    }
    
    // constructing tree in a depth first search way
    void constructTreeRecursive(){
        T ele;
        cout<<"Enter root: ";
        cin>>ele;
        root=new GenericTreeNode<T>(ele);
        constructTreeRecursiveHelper(root);
     return;
    }


    void constructTree(){
        T ele;                                
        cout<<"Enter root: ";
        cin>>ele;
        root=new GenericTreeNode<T>(ele);
        stack<GenericTreeNode<T>*>S;
        S.push(root);
        while(!S.empty()){
            GenericTreeNode<T>*temp=S.top();
            S.pop();
            cout<<"Enter the child count of "<<temp->data<<": ";
            cin>>temp->child_count;
            temp->children=new GenericTreeNode<T>*[temp->child_count];
            for(int i=0;i<temp->child_count;i++){
                cout<<"Enter the "<<i+1<<" child of "<<temp->data<<": ";
                cin>>ele;
                temp->children[i]=new GenericTreeNode<T>(ele);
                temp->children[i]->parent=temp;
                S.push(temp->children[i]);
            }
        }
    }
   void printPreOrder(){
       if(!root)
           return;
       printPreOrderHelper(root);
   } 
   void printPostOrder(){
       if(!root)
           return;
       printPostOrderHelper(root);
   }

   int height(){
       if(!root)return -1;
       return heightOfNode(root);
   }

   void printAtDepthK(int K){
       if(K<0||!root)return;
       printAtDepthKHelper(root,K);
      return;
   }
   GenericTreeNode<T>*LargestNode(){
       if(!root)return root;
       return LargestNodeHelper(root);
   }
   int NodesGreaterThanRootRecursive(){
       if(!root)return 0;
       return NodesGreaterThanNode(root,root->data);
   }

   T SumOfNodes(){
        if(!root)return 0;
        return SumOfNodesHelper(root);
    }

    void preOrderUsingStack(){
        if(!root)return;
        stack<GenericTreeNode<T>*>S;
        S.push(root);
        while(!S.empty()){
            GenericTreeNode<T>*temp=S.top();
            S.pop();
            cout<<temp->data<<" ";
            for(int i=temp->child_count-1;i>=0;i--){
                S.push(temp->children[i]);
            }
        }
        return;
    }
    GenericTreeNode<T>*findMaxSum(){
        if(!root)return root;
        return findMaxSumHelper(root);
    }
   
    int NodesGreaterThanRoot(){
        queue<GenericTreeNode<T>*>Q;
        Q.push(root);
        int count=0;
        while(!Q.empty()){
            GenericTreeNode<T>*temp=Q.front();
            Q.pop();
            if(temp->data>root->data){
                count++;
            }
            for(int i=0;i<temp->child_count;i++){
                Q.push(temp->children[i]);
            }
        }
        return count;
    }



private:
    
   static GenericTreeNode<T>*findMaxSumHelper(GenericTreeNode<T>*root){
       GenericTreeNode<T>*max=root;
       T max_sum=root->data;
       for(int i=0;i<root->child_count;i++){
            max_sum+=root->children[i]->data;
     }
       for(int i=0;i<root->child_count;i++){
           GenericTreeNode<T>*temp=findMaxSumHelper(root->children[i]);
           T sum=temp->data;
           for(int i=0;i<temp->child_count;i++){
               sum+=temp->children[i]->data;
           }
           max=max_sum>sum?max:temp;
           max_sum=max_sum>sum?max_sum:sum;
       }
       return max;
   }

   static T SumOfNodesHelper(GenericTreeNode<T>*root){
       T sum=root->data;
       for(int i=0;i<root->child_count;i++){
           sum+=SumOfNodesHelper(root->children[i]);
       }
       return sum;
   }

   static int NodesGreaterThanNode(GenericTreeNode<T>*root,int K){
       int count=0;
       if(root->data>K){
           count++;
       }
       for(int i=0;i<root->child_count;i++){
           count+=NodesGreaterThanNode(root->children[i],K);
       }
       return count;
   }
      

   static GenericTreeNode<T>*LargestNodeHelper(GenericTreeNode<T>*root){
       GenericTreeNode<T>*large=root;
       for(int i=0;i<root->child_count;i++){
           large=large->data>LargestNodeHelper(root->children[i])->data?large:LargestNodeHelper(root->children[i]);
       }
       return large;
   }
   static void printAtDepthKHelper(GenericTreeNode<T>*root,int K){
       if(!K)cout<<root->data<<" ";
       for(int i=0;i<root->child_count;i++){
           printAtDepthKHelper(root->children[i],K-1);
       }
   }

   static int heightOfNode(GenericTreeNode<T>*root){
       int h=-1;
       for(int i=0;i<root->child_count;i++){
           h=h>heightOfNode(root->children[i])?h:heightOfNode(root->children[i]);
       }
       return h+1;
   }

   static void printPostOrderHelper(GenericTreeNode<T>*root){
        for(int i=0;i<root->child_count;i++){
            printPostOrderHelper(root->children[i]);
        }
        cout<<root->data<<" ";
     return;
   }
       
   static void printPreOrderHelper(GenericTreeNode<T>*root){
       cout<<root->data<<" ";
       for(int i=0;i<root->child_count;i++){
           printPreOrderHelper(root->children[i]);
       }
     return;
   }
   static void constructTreeRecursiveHelper(GenericTreeNode<T>*root){
        cout<<"Enter the child count of "<<root->data<<": ";
        cin>>root->child_count;
        root->children=new GenericTreeNode<T>*[root->child_count];
        for(int i=0;i<root->child_count;i++){
            cout<<"Enter the "<<i+1<<"child of "<<root->data<<": ";
            T ele;
            cin>>ele;
            root->children[i]=new GenericTreeNode<T>(ele);
            root->children[i]->parent=root;
           // constructTreeRecursiveHelper(root->children[i]);
        }
        for(int i=0;i<root->child_count;i++){
            constructTreeRecursiveHelper(root->children[i]);
        }
       

    }



};








#endif //GENERICTREE_H_INCLUDED
