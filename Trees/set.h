#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include<iostream>
using namespace std;

template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode*left,*right;
    BinaryTreeNode(const T&ele=0,BinaryTreeNode*l=NULL,BinaryTreeNode*r=NULL):data(ele),left(l),right(r){}
};

template<typename T>
class Set{
    BinaryTreeNode<T>*root;

public:
    
    class Iterator{
        BinaryTreeNode<T>*current;
        public:
            Iterator(BinaryTreeNode<T>*curr=0):current(curr){}
            
            Iterator&operator++(){
                current=InOrderSuccessor(current->data);
                return *this;
             }
            Iterator operator++(int){
                Iterator old=*this;
                ++(*this);
                return old;
            }
            Iterator&operator--(){
                current=InOrderPredecessor(current->data);
                return *this;
            }
            const T&operator*()const{
                return current->data;
            }
            bool operator==(const Iterator&I)const{
               return current==I.current; 
            }
            bool operator!=(const Iterator&I)const{
                return (*this)==I;
            }
    };

    pair<Iterator,bool>Insert(const T&ele){
        
        Iterator it=Find(ele);
        if(it==End())
            return pair<Iterator,bool>(End(),false);
        if(!root){
            root=new BinaryTreeNode<T>(ele);
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

       return pair<Iterator,bool>(Find(ele),true);
    }

    Iterator Find(const T&ele)const{
        
        BinaryTreeNode<T>*curr=root;
        
        while(curr&&curr->data!=ele){
            if(curr->data<ele){
                curr=curr->right;
            }else{
                curr=curr->right;
            }
        }
        return Iterator(curr);
    }
    
     BinaryTreeNode<T>*findMinimum(){
        return findMinimumHelper(root);
    }
    
     BinaryTreeNode<T>*findMaximum(){
        return findMaximumHelper(root);
    }

     BinaryTreeNode<T>*InOrderSuccessor(const T&ele){
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
            }
            else
                temp=temp->right;
        }
        return succ;
    }

     BinaryTreeNode<T>*InOrderPredecessor(const T&ele){

        BinaryTreeNode<T>*it=root,*pre=0,*temp=root;
        while(it&&it->data!=ele){
            if(it->data<ele)
                it=it->right;
            else
                it=it->left;
        }
        if(!it)return NULL;
        if(it->left)
            return findMaximumHelper(it->left);
        while(temp!=it){
            if(temp->data<ele){
                pre=temp;
                temp=temp->right;
            }
            else
                temp=temp->left;
        }
       return pre;
    }


    Iterator Begin(){
        return Iterator(findMinimumHelper(root));
    }
    Iterator End(){
        return Iterator(NULL);
    }


        

private:
    
    static BinaryTreeNode<T>*findMinimumHelper(BinaryTreeNode<T>*root){
        if(!root||!root->left)return root;
        return findMinimumHelper(root->left);
    }
    
    static BinaryTreeNode<T>*findMaximumHelper(BinaryTreeNode<T>*root){
        if(!root||!root->right)return root;
        return findMaximumHelper(root->right);
    }

   

};

 



#endif //SET_H_INCLUDED
