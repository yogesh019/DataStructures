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

   int diameter1(){
       return diameterOfNode1(root);
   }
   int diameter2(){
       return diameterOfNode2(root).first;
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
   
    bool CheckLeavesAtSameLevel(){
        int level=1,K=1;
        return CheckLeavesAtSameLevelHelper(root,level,K);
    }

    void buildTreeFromInOrderPreOrder(T*in,T*pre,int len){
        root=buildTreeFromInOrderPreOrderHelper(in,pre,0,len-1);
        return;
    }
    
private:
  
    static int SearchIndex(T*in,int Start,int End,const T&value){
       int i=0;
      while(in[i]!=value){
         i++;
      }
     return i;
    } 
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

