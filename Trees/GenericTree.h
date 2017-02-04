#ifndef GENERICTREE_H_INCLUDED
#define GENERICTREE_H_INCLUDED
#include<iostream>
#include<queue>
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
};








#endif //GENERICTREE_H_INCLUDED
