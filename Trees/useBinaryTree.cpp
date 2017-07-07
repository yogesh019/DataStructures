#include<iostream>
#include"BinaryTree.h"
using namespace std;

class something{

public:
    static  int x;
    something(){
        cout<<"constructor"<<endl;
    }

    void show(){
        x=34;
        cout<<"hello"<<endl;
        cout<<"x="<<x<<endl;
    }

    ~something(){
        cout<<"destructor"<<endl;
    }

    static void print(){
        cout<<"print"<<endl;
    }

};
int something::x=89;

int main(){
    //cout<<sizeof(something)<<endl;
    //something s;
    //s.print();
   // something *s=0;
   // s->show();
    //cout<<sizeof(*s)<<endl
    /*
    BinaryTree<char>B1;
    B1.createTree();
    BinaryTree<char>B2;
    B2=B1;
    B2.printTree();
    cout<<endl;
    B1.~BinaryTree();
    B1.printTree();
    */
    BinaryTree<char>B,B1;
    B.createTree();
    /**
    B1.createTree();
    if(B==B1){
        cout<<"Trees are structurally same"<<endl;
    }else{
        cout<<"Trees are not same"<<endl;
    }
    **/
    //B.constructTreeUsingStack();
    //char in[]={'D','B','E','A','F','C'};
    char pre[]={'A','B','D','E','C','F'};
    char in[]={'4','8','2','5','1','6','3','7'};
    char post[]={'8','4','5','2','6','7','3','1'};
    //B.buildTreeFromInOrderPreOrder(in,pre,6);
    //B.buildTreeFromInOrderPostOrder(in,post,8);
    //B.mirror();
   
    B.printTree();
    cout<<endl;
    cout<<"Height of tree: "<<B.height()<<endl;
    cout<<"Largest Element: "<<B.findLargestElement()->data<<endl;
    cout<<"In Order: ";
    B.InOrder();
    cout<<endl;
    cout<<"Pre Order: ";
    B.PreOrder();
    cout<<endl;
    cout<<"Post Order: ";
    B.PostOrder();
    cout<<endl;
    cout<<"Pre Order Using Stack: ";
    B.printPreOrderUsingStack();
    cout<<endl;
    cout<<"In Order Using Stack: ";
    B.InOrderUsingStack();
    cout<<endl;
    cout<<"Post Order Using 2 Stack: ";
    B.PostOrderUsing2Stacks();
    cout<<endl;
    cout<<"Post Order Using  Stack: ";
    B.IterativePostOrder();
    cout<<endl;
    cout<<"No of leaf Nodes: "<<B.CountLeafNodes()<<endl;
    cout<<"Total no. of Nodes: "<<B.CountNodes()<<endl;
    //cout<<"Diameter Of Tree: "<<B.diameter1()<<endl; 
    cout<<"Diameter Of Tree: "<<B.diameter2()<<endl;
    cout<<"Elements with no siblings: ";
    B.printNodesWithNoSiblings();
    cout<<endl;
    cout<<endl;
    if(B.CheckLeavesAtSameLevel()){
        cout<<"Leaves are at the same level";
    }else{
        cout<<"Leaves are not at the same level";
    }
    cout<<"zigzag: "<<endl;
    B.zigzagPrint();
    // cout<<B.NextGreater('F')->data<<endl;
    //cout<<B.NextGreater('B')->data<<endl;
    //cout<<B.NextGreater('G')->data<<endl;
    /**
    cout<<B.findLCARecursive('4','5')->data<<endl;
    cout<<B.findLCARecursive('4','6')->data<<endl;
    cout<<B.findLCARecursive('3','4')->data<<endl;
    cout<<B.findLCARecursive('2','4')->data<<endl;
    **/
    //B.ReplaceNodesWithDepthValue();
    //B.printTree();
    //cout<<"Sum of all nodes is: "<<B.findSumAll()<<endl;
    //cout<<B.findElement('F')->data<<endl;
    //cout<<B.findElement('B')->data<<endl;
    //cout<<B.findElement('G')->data<<endl;
    //cout<<B.findElement('A')->data<<endl;
    //cout<<B.findElement('D')->data<<endl;
    //cout<<B.findElement('C')->data<<endl;
    //cout<<B.findElement('E')->data<<endl;
    //cout<<B.findElement('H')->data<<endl;
    //cout<<B.findElement('I')->data<<endl;
    //B.printAtDepthK(0);
        cout<<endl;
    //B.printAtDepthK(1);
    //cout<<endl;
    //B.printAtDepthK(2);
    //cout<<endl;
    //B.printAtDepthK(3);
    //cout<<endl;
    cout<<endl;
    //B.PopulateNextPointers();
    //cout<<B.root->next->data<<endl;
    //cout<<B.root->next->next->data<<endl;
    //B.connectNodesAtSameLevel();
    //B.connectNodes();
    //cout<<B.root->left->nextRight->data<<endl;
    //cout<<B.root->left->right->left->nextRight->data<<endl;
    //if(B.checkIfBST())
      //  cout<<"Tree is BST"<<endl;
    //else
      //  cout<<"Tree is not BST"<<endl;
    /**
    if(B.isBalanced()){
        cout<<"Tree is Balanced"<<endl;
    }
    else{
        cout<<"Tree not balanced"<<endl;
    }
    cout<<"Largest BST: "<<B.largestBST()<<endl;
    **/
    //B.prettyPrint();
    //printList(B.BTtoLL());
    cout<<"Second Largest Element: "<<B.SecondLargest()->data<<endl;
    return 0;
}

