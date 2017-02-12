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
    BinaryTree<char>B;
    //B.createTree();
    //B.constructTreeUsingStack();
    char in[]={'D','B','E','A','F','C'};
    char pre[]={'A','B','D','E','C','F'};
    B.buildTreeFromInOrderPreOrder(in,pre,6);
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
    cout<<"Post Order Using Stack: ";
    B.PostOrderUsingStack();
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
    // cout<<B.NextGreater('F')->data<<endl;
    //cout<<B.NextGreater('B')->data<<endl;
    //cout<<B.NextGreater('G')->data<<endl;
    /**
    cout<<B.findLCAUsingStack('4','5')->data<<endl;
    cout<<B.findLCAUsingStack('4','6')->data<<endl;
    cout<<B.findLCAUsingStack('3','4')->data<<endl;
    cout<<B.findLCAUsingStack('2','4')->data<<endl;
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
    return 0;
}

