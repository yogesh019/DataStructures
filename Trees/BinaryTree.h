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
    static void constructTreeRecursiveHelper(BinaryTreeNode<T>*root){
        char ch;
        T ele;
        cout<<"Is there any left child of "<<root->data<<"(y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            cout<<"Enter the left child of "<<root->data<<": ";
            cin>>ele;
            root->left=new BinaryTreeNode<T>(ele);
        }
        cout<<"Is there any right child of "<<root->data<<"(y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y'){
            cout<<"Enter the right child of "<<root->data<<": ";
            cin>>ele;
            root->right=new BinaryTreeNode<T>(ele);
        }
        if(root->left)constructTreeRecursiveHelper(root->left);
        if(root->right)constructTreeRecursiveHelper(root->right);
    return;
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
    void constructTreeRecursive(){
        T ele;
        cout<<"Enter root: ";
        cin>>ele;
        root=new BinaryTreeNode<T>(ele);
        constructTreeRecursiveHelper(root);
        return;
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
    void printAtDepthK(int K){
        //if(K<0)return;
        if(K<0||!root)return;
        printAtDepthKHelper(root,K);
        return;
    }
private:
    /**Note : we can do the BinaryTree questions by 2 ways ,first by applying a checking before calling a function
     * and the other way is handling the function ,after the call occurs**/

    static void printAtDepthKHelper(BinaryTreeNode<T>*root,int K){
        //if(!root)return;
        if(!K){
            cout<<root->data<<" ";   
            return;
        }
        if(root->left)
            printAtDepthKHelper(root->left,K-1);
        if(root->right)
            printAtDepthKHelper(root->right,K-1);
        return;
    }
            
};

#endif

