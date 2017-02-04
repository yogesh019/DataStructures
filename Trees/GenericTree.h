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
    T data;
    GenericTreeNode**children;
    GenericTreeNode*parent;
    unsigned int child_count;
public:
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
private:
    
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
