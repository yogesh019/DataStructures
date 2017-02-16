#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class BinarySearchTree;

template<typename T>
class BinaryTreeNode{
  public:
    T data;
    BinaryTreeNode*left,*right;
   
    BinaryTreeNode(const T&ele=0):data(ele),left(0),right(0){}
    friend class BinarySearchTree<T>;
};

template<typename T>
class BinarySearchTree{
    BinaryTreeNode<T>*root;

    void Clear(BinaryTreeNode<T>*root){
        if(!root)return;
        Clear(root->left);
        Clear(root->right);
        delete root;
        root=0;
        
    }

    BinaryTreeNode<T>*DuplicateAs(BinaryTreeNode<T>*root){
        if(!root)return root;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(root->data);
        temp->left=DuplicateAs(root->left);
        temp->right=DuplicateAs(root->right);
        return temp;
    }
public:
    BinarySearchTree():root(0){}
    BinarySearchTree(const BinarySearchTree&B):root(0){
        root=DuplicateAs(B.root);
    }
    BinarySearchTree&operator=(const BinarySearchTree&B){
        Clear(root);
        DuplicateAs(B.root);
        return(*this);
    }
    ~BinarySearchTree(){
        Clear(root);
        
    }
    
    void insertElement(const T&ele){
        if(!root){
            root=new BinaryTreeNode<T>(ele);
            return;
        }
        BinaryTreeNode<T>*curr=root,*prev=0;
        while(curr){
            prev=curr;
            if(curr->data<ele)
                curr=curr->right;
            else
                curr=curr->left;
        }
        if(prev->data<ele)
           prev->right=new BinaryTreeNode<T>(ele);
        else
            prev->left=new BinaryTreeNode<T>(ele);
        return;
    }

    void insertElementRecursive(const T&ele){
        root=insertElementRecursiveHelper(root,ele);
        return;
    }
    void printTree(){
        if(!root){
            cout<<"Empty tree"<<endl;
            return;
        }
        queue<BinaryTreeNode<T>*>Q;
        Q.push(root);Q.push(NULL);
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

    BinaryTreeNode<T>* findElement(const T&ele){
        BinaryTreeNode<T>*it=root;
        while(it){
            if(it->data==ele)return it; 
            else if(it->data<ele)
                it=it->right;
            else
                it=it->left;
        }
        return NULL;
    }

    BinaryTreeNode<T>*findElementRecursive(const T&ele){
        if(!root)return root;
        return findElementRecursiveHelper(root,ele);
    }

    int height(){
        return heightOfNode(root);
    }
    BinaryTreeNode<T>*findMinimum(){
        return findMinimumHelper(root);
    }
    BinaryTreeNode<T>*findMaximum(){
        return findMaximumHelper(root);
    }
    void printInOrder(){
        printInOrderHelper(root);
        return;
    }

    void constructBSTfromPreOrder(T*pre,int len){
        root=constructBSTfromPreOrderHelper(pre,0,len-1);  // time complexity is O(n^2)
    }
    
    void buildBalancedBST(T*arr,int len){
        root=buildBalancedBSTHelper(arr,0,len-1);
    }

    void printPreOrder(){
        printPreOrderHelper(root);
        return;
    }
    void deleteNodeIteratively(const T&ele){
        BinaryTreeNode<T>*it=root,*prev=0;
        while(it&&it->data!=ele){
            prev=it;
            if(it->data<ele)
                it=it->right;
            else
                it=it->left;
        }
        if(!it)return;
        if(it->left&&it->right){
            BinaryTreeNode<T>*temp=it->right,*prev1=0;
            while(temp->left){
                prev1=temp;
                temp=temp->left;
            }
            it->data=temp->data;
            if(!prev1)
                it->right=temp->right;
            else
                prev1->left=temp->right;
            delete temp;
            return;
        }
        BinaryTreeNode<T>*newit=0;
        if(it->left&&!it->right)
            newit=it->left;
        else if(!it->left&&it->right)
            newit=it->right;
        else if(!it->left&&!it->right)
            newit=0;

        if(prev&&prev->data<ele)
            prev->right=newit;
        else if(prev&&prev->data>=ele)
            prev->left=newit;

        if(!prev)
            root=newit;
        delete it;
        return;
    }
    void deleteNode(const T&ele){
        root=deleteNodeHelper(root,ele);
        return;
    }
    
    /*Time complexity of above sol is O(h) where h is the height.Also O(h) 
     * extra space in function call stack for recursive function calls.
     * We can avoid extra space using iterative solution**/

    BinaryTreeNode<T>*findLCA(const T&ele1,const T&ele2){
        return findElementRecursiveHelper(root,ele1)&&findElementRecursiveHelper(root,ele2)?findLCAHelper(root,ele1,ele2):NULL;
    }

    BinaryTreeNode<T>*findLCAIteratively(const T&ele1,const T&ele2){
        if(!root)return NULL;
        BinaryTreeNode<T>*it=root;
        while(it){
  
            if(it->data<ele1&&it->data<ele2)
                it=it->right;
            else  if(it->data>ele1&&it->data>ele2)
                it=it->left;
            else
                return it;
        }
    }

    BinaryTreeNode<T>*InOrderSuccessor(const T&ele){
        return InOrderSuccessorHelper(root,ele);
    }
    
    BinaryTreeNode<T>*InOrderSuccessorIteratively(const T&ele){
        BinaryTreeNode<T>*it=root,*succ=0,*temp=root;
        while(it&&it->data!=ele){
            if(it->data<ele)
                it=it->right;
             else
                it=it->left;
        }
        if(!it)return NULL;
        if(it->right)
            return findMinimumHelper(it->right);
        while(temp!=it){
            if(temp->data>ele){
                succ=temp;
                temp=temp->left;
            }else
                temp=temp->right;
        }
        return succ;
    }
   
   pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>findNodesWithSumToS(const T&S){
      vector<BinaryTreeNode<T>*>v;
      getInOrder(root,v);
      int i=0,j=v.size()-1;
      while(i<=j){
          if(v[i]->data+v[j]->data==S)return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(v[i],v[j]);
          else if(v[i]->data+v[j]->data<S)
              i++;
          else
              j--;
      }
      return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(NULL,NULL);
   }

   pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>findPreSucc(const T&ele){
       return findPreSuccHelper(root,ele);
   }

private:
   static pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>findPreSuccHelper(BinaryTreeNode<T>*root,const T&ele){
       if(!root||!root->left&&!root->right)return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(NULL,NULL);
       if(root->data==ele){
           if(root->left&&!root->right)return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(findMaximumHelper(root->left),NULL);
           else if(!root->left&&root->right)return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(NULL,findMinimumHelper(root->right));
           else return pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>(findMaximumHelper(root->left),findMinimumHelper(root->right));
       }
       if(root->data>ele){
           pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>P=findPreSuccHelper(root->left,ele);
           P.second=P.second?P.second:root;
           return P;
       }
       
           pair<BinaryTreeNode<T>*,BinaryTreeNode<T>*>P=findPreSuccHelper(root->right,ele);
           P.first=P.first?P.first:root;
           return P;
       
   }
   static void getInOrder(BinaryTreeNode<T>*root,vector<BinaryTreeNode<T>*>&v){
      if(!root)return;
      getInOrder(root->left,v); 
      v.push_back(root);
      getInOrder(root->right,v);
      return;
   }
   static BinaryTreeNode<T>*InOrderSuccessorHelper(BinaryTreeNode<T>*root,const T&ele){
        if(!root)return root;
        if(root->data==ele)
            return root->right?findMinimumHelper(root->right):NULL;
        if(root->data>ele)
            return InOrderSuccessorHelper(root->left,ele)?InOrderSuccessorHelper(root->left,ele):root;
        return InOrderSuccessorHelper(root->right,ele);
    }


    static BinaryTreeNode<T>*findLCAHelper(BinaryTreeNode<T>*root,const T&ele1,const T&ele2){
        if(!root)return NULL;
        if(root->data<ele1&&root->data<ele2)
            return findLCAHelper(root->right,ele1,ele2);
        return root->data>ele1&&root->data>ele2?findLCAHelper(root->left,ele1,ele2):root;
    }
    
    static BinaryTreeNode<T>*deleteNodeHelper(BinaryTreeNode<T>*root,const T&ele){
        if(!root)return root;
        if(root->data==ele){
            if(root->left&&!root->right){
                BinaryTreeNode<T>*temp=root->left;
                delete root;
                return temp;
            }
            if(!root->left&&root->right){
                BinaryTreeNode<T>*temp=root->right;
                delete root;
                return temp;
            }
            if(root->left&&root->right){
                BinaryTreeNode<T>*temp=findMinimumHelper(root->right);
                root->data=temp->data;
                root->right=deleteNodeHelper(root->right,temp->data);
                return root;
            }
            if(!root->left&&!root->right){
                delete root;
                root=0;
                return root;
            }
        }
        if(root->data<ele)
            root->right=deleteNodeHelper(root->right,ele);
        else
            root->left=deleteNodeHelper(root->left,ele);
        return root;
    }



    static void printPreOrderHelper(BinaryTreeNode<T>*root){
        if(!root)return;
        cout<<root->data<<" ";
        printPreOrderHelper(root->left);
        printPreOrderHelper(root->right);
        return;
    }

    static BinaryTreeNode<T>* buildBalancedBSTHelper(T*arr,int Start,int End){
        if(Start>End)return NULL;
        int mid=(Start+End)/2;                 //O(n) time complexity
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(arr[mid]);
        temp->left=buildBalancedBSTHelper(arr,Start,mid-1);
        temp->right=buildBalancedBSTHelper(arr,mid+1,End);
        return temp;
    }

    static int splitPreOrder(T*pre,int Start,int End){
        int j=Start+1;
        while(j<=End&&pre[j]<pre[Start]){
            j++;
        }
        return j;
    }
    static BinaryTreeNode<T>*constructBSTfromPreOrderHelper(T*pre,int Start,int End){
        if(Start>End)return NULL;
        BinaryTreeNode<T>*temp=new BinaryTreeNode<T>(pre[Start]);
        int index=splitPreOrder(pre,Start,End);
        temp->left=constructBSTfromPreOrderHelper(pre,Start+1,index-1);
        temp->right=constructBSTfromPreOrderHelper(pre,index,End);
        return temp;
    }
    static void printInOrderHelper(BinaryTreeNode<T>*root){
        if(!root)return;
        printInOrderHelper(root->left);
        cout<<root->data<<" ";
        printInOrderHelper(root->right);
        return;
    }
    static BinaryTreeNode<T>*findMaximumHelper(BinaryTreeNode<T>*root){
        if(!root||!root->right)return root;
        return findMaximumHelper(root->right);
    }
    static BinaryTreeNode<T>*findMinimumHelper(BinaryTreeNode<T>*root){
        if(!root||!root->left)return root;
        return findMinimumHelper(root->left);
    }
    static int heightOfNode(BinaryTreeNode<T>*root){
        if(!root) return -1;
        return 1+max(heightOfNode(root->left),heightOfNode(root->right));
    }
    static BinaryTreeNode<T>*findElementRecursiveHelper(BinaryTreeNode<T>*root,const T&ele){
        if(root->data==ele)return root;
        if(root->right&&root->data<ele)
            return findElementRecursiveHelper(root->right,ele);
        if(root->left&&root->data>ele)
            return findElementRecursiveHelper(root->left,ele);
        return NULL;
    }
    static BinaryTreeNode<T>*insertElementRecursiveHelper(BinaryTreeNode<T>*root,const T&ele){
        if(!root)return new BinaryTreeNode<T>(ele);
        if(root->data<ele){
            root->right=insertElementRecursiveHelper(root->right,ele);
            return root;
        }
        root->left=insertElementRecursiveHelper(root->left,ele);
        return root;
    }
    
};


#endif
