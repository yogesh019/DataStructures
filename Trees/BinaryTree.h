#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class BinaryTree;

template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode*left,*right;

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
    
    /* Recursive function to construct a Tree ,it is basically like a stack rather than asking for all nodes at a level
     * it goes deep inside the branch and  construct that branch first
     */
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
        //root=DuplicateAs(B.root);         //copy constructor
        root=new BinaryTreeNode<T>(*B.root);
    }
    BinaryTree&operator=(const BinaryTree&B){
        //Clear(root);                      //assignment operator overloaded
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
        char ch;                // create Tree using Breadth First Search Way
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
        T ele;                          //construct Tree Using DFS way
        cout<<"Enter root: ";
        cin>>ele;
        root=new BinaryTreeNode<T>(ele);
        constructTreeRecursiveHelper(root);
        return;
    }
    void printTree(){               //print tree using BFS 
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
    
   void constructTreeUsingStack(){
       stack<BinaryTreeNode<T>*>S;          //construct Tree Using DFS way
       T ele;char ch;
       cout<<"Enter root: ";
       cin>>ele;
       root=new BinaryTreeNode<T>(ele);
       S.push(root);
       while(!S.empty()){
           BinaryTreeNode<T>*temp=S.top();
           S.pop();
           cout<<"Is there any left child of "<<temp->data<<"(y/n): ";
           cin>>ch;
           if(ch=='y'||ch=='Y'){
               cout<<"Enter the left child of "<<temp->data<<": ";
               cin>>ele;
               temp->left=new BinaryTreeNode<T>(ele);
               S.push(temp->left);
           }
           cout<<"Is there any right child of "<<temp->data<<"(y/n): ";
           cin>>ch;
           if(ch=='y'||ch=='Y'){
               cout<<"Enter the right child of "<<temp->data<<": ";
               cin>>ele;
               temp->right=new BinaryTreeNode<T>(ele);
               S.push(temp->right);
           }
       }
       return;
   }
   
   BinaryTreeNode<T>*findElement(const T&ele){
       if(!root)return root;
       return findElementHelper(root,ele);
   }
   int height(){
       return heightOfNode(root);
   }
   
   BinaryTreeNode<T>*findLargestElement(){
       if(!root)return root;
       return findLargestElementHelper(root);
   } 
   void PreOrder(){
       PreOrderHelper(root);
       return;
   }
   void InOrder(){
       InOrderHelper(root);
       return;
   }
   void PostOrder(){
       PostOrderHelper(root);
       return;
   }
   void printPreOrderUsingStack(){
       if(!root)return;
       stack<BinaryTreeNode<T>*>S;
       S.push(root);
       while(!S.empty()){
           BinaryTreeNode<T>*temp=S.top();
           S.pop();
           cout<<temp->data<<" ";
           if(temp->right)S.push(temp->right);
           if(temp->left)S.push(temp->left);
       }
       return;
   }
   T findSumAll(){
       return findSumAllHelper(root);
   }
   
   void InOrderUsingStack(){
       stack<BinaryTreeNode<T>*>S;// Time complexity is O(n) in Binary Tree when traversals(PreOrder,InOrder,PostOrder) are used
       BinaryTreeNode<T>*curr=root;
       while(!(S.empty()&&!curr)){
           while(curr){
               S.push(curr);
               curr=curr->left;
           }
           curr=S.top();
           S.pop();
           cout<<curr->data<<" ";
           curr=curr->right;
       }
       return;
   }
  
   void ReplaceNodesWithDepthValue(){
       ReplaceNodesWithDepthValueHelper(root,0);
   return;
   }

   int CountLeafNodes(){
       return CountLeafNodesHelper(root);
   }
   
   int CountNodes(){
       return CountNodesHelper(root);
   }
   
   void PostOrderUsingStack(){
       stack<BinaryTreeNode<T>*>S;
       BinaryTreeNode<T>*temp=root;
       do{
           while(temp){
               if(temp->right)
                   S.push(temp->right);
               S.push(temp);
               temp=temp->left;
           }
           temp=S.top();
           S.pop();
           if(temp->right&&!S.empty()&&S.top()==temp->right){
               S.pop();
               S.push(temp);
               temp=temp->right;
           }else{
               cout<<temp->data<<" ";
               temp=0;
           }
       }while(!S.empty());
       return;
   }

private:

   static int CountNodesHelper(BinaryTreeNode<T>*root){
       if(!root)return 0;
       return 1+CountNodesHelper(root->left)+CountNodesHelper(root->right);
   }
   static int CountLeafNodesHelper(BinaryTreeNode<T>*root){
       if(!root)return 0;
       if(!root->left&&!root->right)return 1;
       return CountLeafNodesHelper(root->left)+CountLeafNodesHelper(root->right);
   }
   static void ReplaceNodesWithDepthValueHelper(BinaryTreeNode<T>*root,int depth){
      if(!root)return;
      root->data=depth;
      ReplaceNodesWithDepthValueHelper(root->left,depth+1);
      ReplaceNodesWithDepthValueHelper(root->right,depth+1);
      return;
   }   
   static T findSumAllHelper(BinaryTreeNode<T>*root){
       if(!root)return 0;
       return root->data+findSumAllHelper(root->left)+findSumAllHelper(root->right);
   }
   static void PostOrderHelper(BinaryTreeNode<T>*root){
       if(!root)return;
       PostOrderHelper(root->left);
       PostOrderHelper(root->right);
       cout<<root->data<<" ";
       return;
   }
   static void InOrderHelper(BinaryTreeNode<T>*root){
       if(!root)return;
       InOrderHelper(root->left);
       cout<<root->data<<" ";
       InOrderHelper(root->right);
       return;
   }
   static void PreOrderHelper(BinaryTreeNode<T>*root){
       if(!root)return;
       cout<<root->data<<" ";
       PreOrderHelper(root->left);
       PreOrderHelper(root->right);
       return;
   }
   static BinaryTreeNode<T>*findLargestElementHelper(BinaryTreeNode<T>*root){
       //here we make a check before going to recursion
       BinaryTreeNode<T>*large=root;
       if(root->left){
           BinaryTreeNode<T>*leftLargest=findLargestElementHelper(root->left);
           if(leftLargest->data>large->data)
               large=leftLargest;
       }
       if(root->right){
           large=findLargestElementHelper(root->right)->data>large->data?findLargestElementHelper(root->right):large;
       }
       return large;
       /**
       if(!root)return root;
       BinaryTreeNode<T>*large=root;
       BinaryTreeNode<T>*leftLargest=findLargestElementHelper(root->left);
       if(leftLargest&&leftLargest->data>large->data){  //here we first make a recursion call and then apply a check after return
           large=leftLargest;
       }
       BinaryTreeNode<T>*rightLargest=findLargestElementHelper(root->right);
       if(rightLargest&&rightLargest->data>large->data){
           large=rightLargest;
       }
       return large;
       **/
   }
   
   static int heightOfNode(BinaryTreeNode<T>*root){
       if(!root)return -1;
       return max(heightOfNode(root->left),heightOfNode(root->right))+1;
   }
   
   static BinaryTreeNode<T>*findElementHelper(BinaryTreeNode<T>*root,const T&ele){
       if(root->data==ele)
           return root;
       if(root->left&&findElementHelper(root->left,ele))
           return findElementHelper(root->left,ele);
       if(root->right&&findElementHelper(root->right,ele))
           return findElementHelper(root->right,ele);
       return NULL;
       /*
       if(!root||root->data==ele)return root;
       return findElementHelper(root->left,ele)?findElementHelper(root->left,ele):findElementHelper(root->right,ele);
       */
   }
    
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

