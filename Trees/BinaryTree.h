#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
#include<limits>
using namespace std;


template<typename T>
struct info{
T min_value;
T max_value;
bool isBST;
int Size;
int res;

};

template<typename T>
class BinaryTree;

template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode*left,*right,*nextRight,*next;

    BinaryTreeNode(const T&ele=0):data(ele),left(0),right(0),nextRight(0),next(0){}
    BinaryTreeNode(const BinaryTreeNode&B):left(0),right(0),nextRight(0),next(0){
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
void printList(BinaryTreeNode<T>*head){
    while(head){
        cout<<head->data<<"-->";
        head=head->right;
    }
    cout<<"NULL"<<endl;
    return;
}

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
   
    static bool check(BinaryTreeNode<T>*root,BinaryTreeNode<T>*temp){
        if(!root&&!temp)return true;
        if(root&&!temp||!root&&temp)return false;
        if(root->data!=temp->data)return false;
        return check(root->left,temp->left)&&check(root->right,temp->right);
    }
    
    
    static BinaryTreeNode<T>*BTtoLLHelper(BinaryTreeNode<T>*root){
        if(!root)return root;
        if(root->left){
            BinaryTreeNode<T>*Left=BTtoLLHelper(root->left);
            while(Left&&Left->right){
                Left=Left->right;
            }
            Left->right=root;
            root->left=Left;
        }
        if(root->right){
            BinaryTreeNode<T>*Right=BTtoLLHelper(root->right);
            while(Right&&Right->left){
                Right=Right->left;
            }
            Right->left=root;
            root->right=Right;
        }
        return root;
    }



public:
    BinaryTree():root(0){}
    BinaryTree(const BinaryTree&B):root(0){
        //root=DuplicateAs(B.root);         //copy constructor
        root=new BinaryTreeNode<T>(*B.root);
    }
    BinaryTreeNode<T>*BTtoLL(){
        if(!root)return root;
        root=BTtoLLHelper(root);
        while(root->left){
            root=root->left;
        }
        return root;
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
    bool operator==(const BinaryTree&B){
        return check(root,B.root);
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
       /*
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
       */
       stack<BinaryTreeNode<T>*>S;
       BinaryTreeNode<T>*temp=root;
       while(temp){
           S.push(temp);
           temp=temp->left;
       }
       while(!S.empty()){
           temp=S.top();
           S.pop();
           cout<<temp->data<<" ";
           if(temp->right){
               temp=temp->right;
               while(temp){
                   S.push(temp);
                   temp=temp->left;
               }
           }
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

   void PostOrderUsing2Stacks(){
       stack<BinaryTreeNode<T>*>S1,S2;
       S1.push(root);
       while(!S1.empty()){
           BinaryTreeNode<T>*temp=S1.top();
           S1.pop();
           S2.push(temp);
           if(temp->left)S1.push(temp->left);
           if(temp->right)S1.push(temp->right);
       }
   while(!S2.empty()){
       cout<<S2.top()->data<<" ";
       S2.pop();

   }
   return;
   }
   void IterativePostOrder(){
        stack<BinaryTreeNode<T>* >S;
        S.push(root);
        BinaryTreeNode<T>*prev=0;
        while(!S.empty()){
            BinaryTreeNode<T>*curr=S.top();
            if(!prev||prev->left==curr||prev->right==curr){
                if(curr->left)
                    S.push(curr->left);
                else if(curr->right)
                    S.push(curr->right);
                else{
                    cout<<curr->data<<" ";
                    S.pop();
                }
            }
            else if(curr->left==prev){
                if(curr->right)
                    S.push(curr->right);
                else{
                    cout<<curr->data<<" ";
                    S.pop();
                }
            }
            else if(curr->right==prev){
                cout<<curr->data<<" ";
                S.pop();
            }
            prev=curr;
        }
   return;
   }


   int diameter1(){
       return diameterOfNode1(root);
   }
   int diameter2(){
       //return diameterOfNode2(root).first;
       int ans=0;
       diameterOfNode(root,ans);
       return ans;
   }
   
   void printNodesWithNoSiblings(){
      printNodesWithNoSiblingsHelper(root);
     return;
   }
   /**        LCA: LEAST COMMON ANCESTOR
    Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has 
    both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

    The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of 
    lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of 
    nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance 
    from the root to n2, minus twice the distance from the root to their lowest common ancestor.  **/ 
    
    BinaryTreeNode<T>*findLCAUsingStack(const T&ele1,const T&ele2){
      stack<BinaryTreeNode<T>*>S1,S2;
      getAncestorsInStack(root,S1,ele1); // Time complexity is O(n), requires 2 tree traversals and then the arrays are compared
      getAncestorsInStack(root,S2,ele2);
      BinaryTreeNode<T>*LCA=0;
      while(!S1.empty()&&!S2.empty()&&S1.top()==S2.top()){
          LCA=S1.top();
          S1.pop();
          S2.pop();
      }
      return LCA;
    }

    BinaryTreeNode<T>*NextGreater(const T&ele){
       return findNextGreater(root,ele);
    }

    BinaryTreeNode<T>*findNGE(const T&ele){

    return findNGEHelper(root,ele);
}

   
    bool CheckLeavesAtSameLevel(){
        int level=1,K=1;
        return CheckLeavesAtSameLevelHelper(root,level,K);
    }

    void buildTreeFromInOrderPreOrder(T*in,T*pre,int len){
        root=buildTreeFromInOrderPreOrderHelper(in,pre,0,len-1);
        return;
    }
    
    void buildTreeFromInOrderPostOrder(T*in,T*post,int len){
        root=buildTreeFromInOrderPostOrderHelper(in,post,0,len-1);
        return;
    }
    void mirror(){
        root=createMirrorTree(root);
        return;
    }
    void zigzagPrint(){
        queue<BinaryTreeNode<T>*>Q;       //time complexity is O(n)and space complexity is O(n)
        stack<BinaryTreeNode<T>*>S;
        Q.push(root);Q.push(NULL);
        int level=1;
        while(!Q.empty()){
            BinaryTreeNode<T>*temp=Q.front();
            Q.pop();
            if(!temp){
                cout<<endl;
                while(!S.empty()){
                    cout<<S.top()->data<<" ";
                    S.pop();
                }
                if(!Q.empty()){
                    level++;
                    Q.push(NULL);
                }
                continue;
            }
            if(temp->left)Q.push(temp->left);
            if(temp->right)Q.push(temp->right);
            if(level&1){
                cout<<temp->data<<" ";
                if(temp->left)S.push(temp->left);
                if(temp->right)S.push(temp->right);
            }
        }
        return;
    }

    void PopulateNextPointers(){
        PopulateNextPointersHelper(root);
        return;
    }

    void printInOrderUsingNextPointer(){
        if(!root)return;
        BinaryTreeNode<T>*temp=root;
        while(temp->left){
            temp=temp->left;
        }
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        return;
    }

   void connectNodesAtSameLevel(){
       if(!root)return;
       queue<BinaryTreeNode<T>*>Q;    // time complexity is O(n) and space complexity is also O(n)
       Q.push(root);Q.push(NULL);
       while(!Q.empty()){
           BinaryTreeNode<T>*temp=Q.front();
           Q.pop();
           if(!temp){
               if(!Q.empty()){
                   Q.push(NULL);
               }
               continue;
           }
           if(temp->left)Q.push(temp->left);
           if(temp->right)Q.push(temp->right);
           if(temp==root)continue;
           temp->nextRight=Q.front();
           
       }
       return;
   }

   void connectNodes(){
       connectNodesHelper(root);
       return;
   }

   bool checkIfBST(){
       T min_value=numeric_limits<T>::min();
       T max_value=numeric_limits<T>::max();
       return isBSTHelper(root,min_value,max_value);
   }

   bool isBalanced(){
        bool ans=false;
   isBalancedHelper(root,ans);
   return ans;
       //return isBalancedHelper(root).first;
   }

   int largestBST(){
       return largestBSTHelper(root).second;
   }

int largestBST2(){
    return largestBSTHelper2(root).res;
}
 
   void printSpaces(int spaces){
       for(int i=0;i<spaces;i++){
           cout<<" ";
       }
       return;
   }
  void prettyPrint(){
     if(!root)return; 
     queue<BinaryTreeNode<T>*>Q;
     Q.push(root);Q.push(NULL);
     int spaces=pow(2,height());
     while(!Q.empty()){
         BinaryTreeNode<T>*temp=Q.front();
         Q.pop();
         if(!temp){
             if(!Q.empty()){
                 cout<<endl;
                 Q.push(NULL);
                 spaces/=2;
             }
             continue;
         }
         if(temp->data!=-1){
            printSpaces(spaces);
            cout<<temp->data;
            printSpaces(spaces);
         }else{
             printSpaces(spaces);
             cout<<" ";

             printSpaces(spaces);
         }
         
         if(temp->left)Q.push(temp->left);

         if(!temp->left&&temp->data!=-1)Q.push(new BinaryTreeNode<T>(-1));
         if(temp->right)Q.push(temp->right);
         if(!temp->right&&temp->data!=-1)Q.push(new BinaryTreeNode<T>(-1));
     }
     return;
  }

  BinaryTreeNode<T>*findLCARecursive(const T&ele1,const T&ele2){
      pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>P=findLCARecursiveHelper(root,ele1,ele2);
      if(P.first&&P.second)
          return P.first;
      return NULL;

  }
  BinaryTreeNode<T>*SecondLargest(){
      return SecondLargestHelper(root).second;
  }


  void printRootToLeaves(){			//print all paths from root to leafs
    	if(!root)
        	return;
    	printRootToLeavesHelper(root);
    	return;
}


bool hasSum(int K){
    vector<int>path;

    if( hasSumHelper(root,K,path)){
        for(int i=0;i<path.size();i++){
            cout<<path[i];
        if(i!=path.size()-1)
            cout<<"+";
        }
        cout<<"="<<K;
        cout<<endl;
    return true;
    }
return false;
}
                                                    /// root to leaf path sum equal to given no
bool printAllPathsWithGivenSum(int K){
    vector<int>path;
    return printAllPathsWithGivenSumHelper(root,K,path);
}


/// create a binary tree using parent array
void createTreeFromParent(int*parent,int n){
    vector<BinaryTreeNode<T>*>created(n,NULL);
    for(int i=0;i<n;i++){
        createTreeFromParentHelper(parent,i,root,created);
    }
    return;
}
   
           
private:


    static void createTreeFromParentHelper(int*parent,int i,BinaryTreeNode<T>*&root,vector<BinaryTreeNode<T>*>&created){
        if(created[i]!=NULL)return;
        created[i]=new BinaryTreeNode<T>(i);
        if(parent[i]==-1){
            root=created[i];
            return;
        }
        if(!created[parent[i]])
            createTreeFromParentHelper(parent,parent[i],root,created);
        if(created[parent[i]]->left==NULL)
            created[parent[i]]->left=created[i];
        else
            created[parent[i]]->right=created[i];
        return;
    }


static bool printAllPathsWithGivenSumHelper(BinaryTreeNode<T>*root,int K,vector<int>&path){

    if(!root){
        if(K==0){
            cout<<endl;
            return true;
        }
    return false;
    }
    path.push_back(root->data);

    if(!root->left&&!root->right){
        if(root->data==K){
                int sum=0;
                for(int i=0;i<path.size();i++){
                          sum+=path[i];
                            cout<<path[i];
                            if(i!=path.size()-1)
                                    cout<<"+";
            }
        cout<<"="<<sum<<endl;
            return true;
    }

return false;
}

bool ans=root->left&&printAllPathsWithGivenSumHelper(root->left,K-root->data,path);
if(root->left)
    path.pop_back();
ans=root->right&&printAllPathsWithGivenSumHelper(root->right,K-root->data,path)||ans;
if(root->right)
    path.pop_back();
return ans;

}
 
 static bool hasSumHelper(BinaryTreeNode<T>*root,int K,vector<int>&path){
    if(!root)
        return K==0;
       path.push_back(root->data);
        if(!root->left&&!root->right){
            if(root->data==K)
                return true;
        }
        if( root->left&&hasSumHelper(root->left,K-root->data,path)||root->right&&hasSumHelper(root->right,K-root->data,path)){
            return true;
        }
        path.pop_back();
return false;
}
 static void printRootToLeavesHelper(BinaryTreeNode<T>*root){
    static vector<T>path;

    path.push_back(root->data);
    if(!root->left&&!root->right){
        for(typename vector<T>::iterator it=path.begin();it!=path.end();it++){
            cout<<(*it)<<" ";
        }
        cout<<endl;
        return;
    }
    if(root->left){
        printRootToLeavesHelper(root->left);
    path.pop_back();
    }
    if(root->right){
    printRootToLeavesHelper(root->right);
    path.pop_back();
    }
    return;
}  

    static pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>SecondLargestHelper(BinaryTreeNode<T>*root){
       if(!root)
          return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(NULL,NULL);
      pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>Left=SecondLargestHelper(root->left); 
      pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>Right=SecondLargestHelper(root->right);
      pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>P(root,root);
      if(Left.first&&Left.first->data>P.first->data){
          P.first=Left.first;
      }
      if(Right.first&&Right.first->data>P.first->data){
          P.first=Right.first;
      }
      if(Left.first&&Left.first!=P.first&&Left.first->data>P.second->data)
          P.second=Left.first;
      
      if(Left.second&&Left.second!=P.first&&Left.second->data>P.second->data)
         P.second=Left.second; 
      
      if(Right.first&&Right.first!=P.first&&Right.first->data>P.second->data)
          P.second=Right.first;
      
      if(Right.second&&Right.second!=P.first&&Right.second->data>P.second->data)
         P.second=Right.second; 

      
      return P;
    }


  
    static pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>findLCARecursiveHelper(BinaryTreeNode<T>*root,const T&ele1,const T&ele2){
       pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*> Left,Right,P;
       if(!root)
           return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(NULL,NULL);
       Left=findLCARecursiveHelper(root->left,ele1,ele2);
       if(Left.first&&Left.second)return Left;
       Right=findLCARecursiveHelper(root->right,ele1,ele2);
       if(Right.first&&Right.second)return Right;
       P.first=Left.first?Left.first:Right.first;
       P.second=Left.second?Left.second:Right.second;
       if(root->data==ele1){
           P.first=root;
       }else if(root->data==ele2){
           P.second=root;
       }
       if(P.first&&P.second&&P.first!=P.second){
           return make_pair(root,root);
       }
       return P;
   }

  static info<T> largestBSTHelper2(BinaryTreeNode<T>*root){
        if(!root){

            return {numeric_limits<T>::max(),numeric_limits<T>::min(),true,0,0};
        }
        if(!root->left&&!root->right)
            return {root->data,root->data,true,1,1};
        info <T>left=largestBSTHelper2(root->left);
        info <T>right=largestBSTHelper2(root->right);
        info <T>ans;
        ans.Size=1+left.Size+right.Size;

        if(left.isBST&&right.isBST&&root->data>left.max_value&&root->data<right.min_value){
            ans.min_value=min(left.min_value, min(right.min_value, root->data));
            ans.max_value=max(right.max_value, max(left.max_value, root->data));
            ans.isBST=true;
            ans.res=ans.Size;
       return ans;
        }
        ans.res=max(left.res,right.res);
        ans.isBST=false;
        return ans;
    }


   static pair<bool,int>largestBSTHelper(BinaryTreeNode<T>*root){
       if(isBST(root))return pair<bool,int>(true,CountNodesHelper(root));
        pair<bool,int>Left=largestBSTHelper(root->left);      //O(n^2) time complexity
        pair<bool,int>Right=largestBSTHelper(root->right);

        return Left.first||Right.first?pair<bool,int>(true,max(Left.second,Right.second)):pair<bool,int>(false,0);
   }


   static bool isBST(BinaryTreeNode<T>*root){
       T min_value=numeric_limits<T>::min();
       T max_value=numeric_limits<T>::max();
       return isBSTHelper(root,min_value,max_value);
   }
 static int isBalancedHelper(BinaryTreeNode<T>*root,bool&ans){
        if(!root){
            ans=true;
            return -1;
        }
        int Left=isBalancedHelper(root->left,ans);
        int Right=isBalancedHelper(root->right,ans);
        ans=ans&&abs(Left-Right)<=1;
        return 1+max(Left,Right);

    }


   static pair<bool,int> isBalancedHelper(BinaryTreeNode<T>*root){
       if(!root)return pair<bool,int>(true,-1);
       pair<bool,int>Left=isBalancedHelper(root->left);
       pair<bool,int>Right=isBalancedHelper(root->right);
       if(Left.first&&Right.first&&abs(Left.second-Right.second)<=1)return pair<bool,int>(true,1+max(Left.second,Right.second));
       return pair<bool,int>(false,1+max(Left.second,Right.second));
   }

   static bool isBSTHelper(BinaryTreeNode<T>*root,T min_value,T max_value){
       if(!root)return true;
       if(root->data<min_value||root->data>max_value)return false;
       return isBSTHelper(root->left,min_value,root->data)&&isBSTHelper(root->right,root->data,max_value);
   }


  /**This approach works only for Complete Binary Trees. In this method we set nextRight in Pre Order fashion to make sure that 
   * the nextRight of parent is set before its children. When we are at node p, we set the nextRight of its left and right children. 
   * Since the tree is complete tree, nextRight of p’s left child (p->left->nextRight) will always be p’s right child, and nextRight 
   * of p’s right child (p->right->nextRight) will always be left child of p’s nextRight (if p is not the rightmost node at its level).
     If p is the rightmost node, then nextRight of p’s right child will be NULL.
   **/
  
   static void connectNodesHelper(BinaryTreeNode<T>*root){
        if(!root)return;
        if(root->left)
            root->left->nextRight=root->right;
        if(root->right)
            root->right->nextRight=root->nextRight?root->nextRight->left:NULL;
        connectNodesHelper(root->left);
        connectNodesHelper(root->right);
        return;
   }
   static void PopulateNextPointersHelper(BinaryTreeNode<T>*root){
        if(!root)return;
        
        /**
        static BinaryTreeNode<T>*prev=0;
        PopulateNextPointersHelper(root->left);
        if(!prev)
            prev=root;
        else{
            prev->next=root;
            prev=prev->next;
        }
        PopulateNextPointersHelper(root->right);
        **/
        static BinaryTreeNode<T>*NEXT=0;
        PopulateNextPointersHelper(root->right);
        root->next=NEXT;
        NEXT=root;
        PopulateNextPointersHelper(root->left);

        return;
    }


    static BinaryTreeNode<T>*createMirrorTree(BinaryTreeNode<T>*root){
        if(!root)return root;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(root->data);
        temp->left=createMirrorTree(root->right);
        temp->right=createMirrorTree(root->left);
        return temp;
    }
    //Note:we can construct a tree only if one of the traversal is inorder, otherwise if pre-order and post-order are given ,there
    //are multiple trees possible
    static int SearchIndex(T*in,int Start,int End,const T&value){
       int i=0;
      while(in[i]!=value){
         i++;
      }
     return i;
    } 
    //Time complexity is O(n^2), worst case occurs when tree is left skewed
    //ex : pre[]={A,B,C,D},in[]={D,C,B,A}
    static BinaryTreeNode<T>*buildTreeFromInOrderPreOrderHelper(T*in,T*pre,int Start,int End){
        if(Start>End)return NULL;
        static int  preIndex=0;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(pre[preIndex++]);
        //if(Start==End)return temp;
        int index=SearchIndex(in,Start,End,temp->data);
        temp->left=buildTreeFromInOrderPreOrderHelper(in,pre,Start,index-1);
        temp->right=buildTreeFromInOrderPreOrderHelper(in,pre,index+1,End);
        return temp;
    }

    static BinaryTreeNode<T>*buildTreeFromInOrderPostOrderHelper(T*in,T*post,int Start,int End){
        if(Start>End)return NULL;
        static int postIndex=End;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(post[postIndex--]);
        int index=SearchIndex(in,Start,End,temp->data);
        temp->right=buildTreeFromInOrderPostOrderHelper(in,post,index+1,End);
        temp->left=buildTreeFromInOrderPostOrderHelper(in,post,Start,index-1);
        return temp;
    }
    static bool CheckLeavesAtSameLevelHelper(BinaryTreeNode<T>*root,const int&level, int&K){
        if(!root)return true;
        if(!root->left&&!root->right){
            if(K==1){
                K=level;
                return true;
            }
            return level==K;
        }
        return CheckLeavesAtSameLevelHelper(root->left,level+1,K)&&CheckLeavesAtSameLevelHelper(root->right,level+1,K);
    }

    static BinaryTreeNode<T>*findNGEHelper(BinaryTreeNode<T>*root,const T&ele){
            if(!root)return root;
            BinaryTreeNode<T>*left=findNGEHelper(root->left,ele);
            BinaryTreeNode<T>*right=findNGEHelper(root->right,ele);
            if(root->data>ele&&!left&&!right)
                return root;
            if(root->data>ele&&left&&!right)
                return root->data>left->data?left:root;
            if(root->data>ele&&!left&&right)
                return root->data>right->data?right:root;
            if(root->data>ele&&left&&right)
                return  left->data<right->data?left->data<root->data?left:root:right->data<root->data?right:root;
            if(left&&!right)return left;
            if(right&&!left)return right;
            if(left&&right)
                return left->data<right->data?left:right;
            return NULL;
    }



    static bool isThereAnyElement(BinaryTreeNode<T>*root,const T&value,const T&ele){
       if(!root)return false;
      if(root->data>ele&&root->data<value)return true;
     return isThereAnyElement(root->left,value,ele)||isThereAnyElement(root->right,value,ele);
    } 
    static BinaryTreeNode<T>*findNextGreater(BinaryTreeNode<T>*root,const T&ele){
        if(!root)return root;
        if(root->data>ele&&!isThereAnyElement(root->left,root->data,ele)&&!isThereAnyElement(root->right,root->data,ele)){
            return root;
        }
        return findNextGreater(root->left,ele)?findNextGreater(root->left,ele):findNextGreater(root->right,ele);
    }


    static bool getAncestorsInStack(BinaryTreeNode<T>*root,stack<BinaryTreeNode<T>*>&S,const T&ele){
        //if(!root)return false;
        if(root->data==ele){
            S.push(root);
            return true;
        }
        // Note: if we remove root->left&&..  int the below statement then if we have to write the above statement if(!root)return false
        if(root->left&&getAncestorsInStack(root->left,S,ele)||root->right&&getAncestorsInStack(root->right,S,ele)){
            S.push(root);// an element is ancestor of itself ; though we can remove this
            return true;
        }
        return false;
    }

    static void printNodesWithNoSiblingsHelper(BinaryTreeNode<T>*root){
       if(!root)return;
       if(root->left&&!root->right)
           cout<<root->left->data<<" ";
       if(!root->left&&root->right)
           cout<<root->right->data<<" ";
       printNodesWithNoSiblingsHelper(root->left);
       printNodesWithNoSiblingsHelper(root->right);
       return;
   }
   //DIAMETER OF A NODE: TIME COMPLEXITY IS O(n^2)
   /* Diameter of a tree is the number of nodes on the longest path between 2 leaf nodes , 
    * here the boundary 2 leaf nodes are excluded in the calculation , the problem with this algorithm is that it's time complexity
    * is O(n^2) and not O(n).
    * The main culprit here is the height function.As height function is the
    * linear function and it is called for every node so this make the 
    * whole algorithm O(n^2),we can make a better optimization if we return
    * at each node a pair of it;s diameter value and height so that when it
    * returns(when wrapping of functions)height is not calculated again
    * we won't call height for each node again and again */ 
   
   static int diameterOfNode1(BinaryTreeNode<T>*root){
        if(!root)return 0;          
        return max(1+heightOfNode(root->left)+heightOfNode(root->right),max(diameterOfNode1(root->left),diameterOfNode1(root->right)));
   }

   static int diameterOfNode(BinaryTreeNode<T>*root,int&ans){
       if(!root)            // another approach of finding diameter ,time complexity is  O(n)
           return -1;
       int lh=diameterOfNode(root->left,ans);
       int rh=diameterOfNode(root->right,ans);
       ans=max(ans,1+lh+rh);
       return 1+max(lh,rh);
   }
   
   static pair<int,int>diameterOfNode2(BinaryTreeNode<T>*root){
       if(!root)return pair<int,int>(0,-1);              //DIAMETER OF A NODE ; TIME COMPLEXITY IS O(n)
       pair<int,int>Left=diameterOfNode2(root->left);
       pair<int,int>Right=diameterOfNode2(root->right);
       int d=max(1+Left.second+Right.second,max(Left.first,Right.first));
       int h=1+max(Left.second,Right.second);
       return pair<int,int>(d,h);
   }

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

