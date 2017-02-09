#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTree;

template<typename T>
class BinaryTreeNode{
    T data;
    BinaryTreeNode*left,*right;
public:
    BinaryTreeNode(const T&ele=0):data(ele),left(0),right(0){}
    BinaryTreeNode(const BinaryTreeNode&B):left(0),right(0){
        data=B.data;
        if(B.left)
            left=new BinaryTreeNode<T>(*B.left);
        if(B.right)
            right=new BinaryTreeNode<T>(*B.right);
    }
    
    BinaryTreeNode&operator=(const BinaryTreeNode&B){
        if(left)delete left;
        if(right)delete right;
        data=B.data;
        if(B.left)
            left=new BinaryTreeNode<T>(*B.left);
        if(B.right)
            right=new BinaryTreeNode<T>(*B.right);
        return (*this);
    }
    ~BinaryTreeNode(){
        if(left)delete left;
        if(right)delete right;
    }
    friend class BinaryTree<T>;
};
template<typename T>
class BinaryTree{
    BinaryTreeNode<T>*root;
    static void Clear(BinaryTreeNode<T>*root){
        if(!root)return;
        Clear(root->left);
        Clear(root->right);
        delete root;
    }
    static BinaryTreeNode<T>*DuplicateAs(BinaryTreeNode<T>*root){
        if(!root)return root;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(root->data);
        temp->left=DuplicateAs(root->left);
        temp->right=DuplicateAs(root->right);
        return temp;
    }
public:
    BinaryTree():root(0){}
    BinaryTree(const BinaryTree&B):root(0){
        //root=DuplicateAs(B.root);
        root=new BinaryTreeNode<T>(*B.root);
    }
    BinaryTree&operator=(const BinaryTree&B){
        //Clear(root);
        //root=DuplicateAs(B.root);
        if(root)delete root;
        root=new BinaryTreeNode<T>(*B.root);
        return (*this);
    }
    ~BinaryTree(){
        //Clear(root);
        delete root;
        root=0;
    }
    void createTree(){
        T ele;
        char ch;
        queue<BinaryTreeNode<T>*>Q;
        cout<<"Enter root: ";
        cin>>ele;
        root=new BinaryTreeNode<T>(ele);
        Q.push(root);
        while(!Q.empty()){
            BinaryTreeNode<T>*temp=Q.front();
            Q.pop();
            cout<<"Is there any left child of "<<temp->data<<"(y/n): ";
            cin>>ch;
            if(ch=='y'||ch=='Y'){
                cout<<"Enter the left child of "<<temp->data<<": ";
                cin>>ele;
                temp->left=new BinaryTreeNode<T>(ele);
                Q.push(temp->left);
            }
            cout<<"Is there any right child of "<<temp->data<<"(y/n): ";
            cin>>ch;
            if(ch=='y'||ch=='Y'){
                cout<<"Enter the right child of "<<temp->data<<": ";
                cin>>ele;
                temp->right=new BinaryTreeNode<T>(ele);
                Q.push(temp->right);
            }
        }
    }
    void printTree(){
        if(!root){
            cout<<"Empty Tree"<<endl;
            return;
        }
        queue<BinaryTreeNode<T>*>Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            BinaryTreeNode<T>*temp=Q.front();
            Q.pop();
            if(!temp){
                if(!Q.empty()){
                    cout<<endl;
                    Q.push(NULL);
                }
                continue;
            }
            cout<<temp->data<<" ";
            if(temp->left)Q.push(temp->left);
            if(temp->right)Q.push(temp->right);
        }
        return;
    }
};

#endif

