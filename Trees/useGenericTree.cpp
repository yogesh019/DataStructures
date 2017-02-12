#include"GenericTree.h"
using namespace std;
/*
Trees, like lists, are "abstract data types" which can be implemented in different ways. Each way has it's advantages and disadvantages.

Fist way is to keep a track of children nodes by create an array of children nodes
the main advantage of this structure is that you can access any child in O(1). 
The disadvantage is that appending a child might sometimes be a little more expensive when the array has to be expanded. 
This cost is relatively small though. It is also one of the simplest implementation.

Second way is to store tree node as FIRST CHILD NEXT  SIBLING REPRESENTATION
In the second example, the main advantage is that you always append a child in O(1). The main disadvantage is that 
random access to a child costs O(n). Also, it may be less interesting for huge trees for two reasons: it has a memory 
overhead of one object header and two pointers per node, and the nodes are randomly spread over memory which may cause a lot of 
swapping between the CPU cache and the memory when the tree is traversed, making this implementation less appealing for them. 
This is not a problem for normal trees and applications though.

Another way is to store the whole tree in a single array. This leads to more complex code, but is sometimes a very advantageous 
implementation in specific cases, especially for huge fixed trees, since you can spare the cost of the object header and 
allocate contiguous memory.



template<typename T>
class GenericTreeNode{
    T data;
    GenericTreeNode*firstChild,nextSibling;
public:
    GenericTreeNode(const T&ele):data(ele),firstChild(0),nextSibling(0){}
};
*/
int main(){
    GenericTree<int>G1;
    G1.createTree();
    G1.printTree();
    cout<<endl;
    cout<<"Pre Order: ";
    G1.printPreOrder();
    cout<<endl;
    cout<<"Post Order: ";
    G1.printPostOrder();
    cout<<endl;
    cout<<"Height Of Tree: "<<G1.height()<<endl;
    G1.printAtDepthK(3);
    cout<<"Largest Node: "<<G1.LargestNode()->data<<endl;
    cout<<"Sum Of All Nodes: "<<G1.SumOfNodes()<<endl;
    cout<<"Nodes with max sum of itself and it's children is: ";
    cout<<G1.findMaxSum()->data<<endl;
    cout<<"Nodes Greater than root: ";
    cout<<G1.NodesGreaterThanRoot();
    /**
    G1.createTree();
    GenericTree<char>G2;
    G2=G1;
    G1.~GenericTree();
    cout<<endl;
    G2.printTree();
    G1.printTree();
    cout<<endl;
    **/
    return 0;
}
