#include"BinarySearchTree.h"
int main(){
    BinarySearchTree<char>B;
    int pre[]={10,5,1,7,40,50};
    int arr[]={1,2,3,4,5,6,7};
    //B.constructBSTfromPreOrder(pre,6);
    //B.buildBalancedBST(arr,7);
    char ch;
    B.insertElementRecursive('F');
    B.insertElementRecursive('B');
    B.insertElementRecursive('G');
    B.insertElementRecursive('A');
    B.insertElementRecursive('D');
    B.insertElementRecursive('I');
    B.insertElementRecursive('C');
    B.insertElementRecursive('E');
    B.insertElementRecursive('H');
    
    cout<<"Enter the node to delete: ";
    cin>>ch;
    B.deleteNodeIteratively(ch);
    
   // BinarySearchTree<char>B1=B;
    //B.~BinarySearchTree();
    //B1.printTree();
    //cout<<endl;
    //B.printTree();
    //cout<<B.findElement('I')->data<<endl;
    //cout<<B.findElementRecursive('K')->data<<endl;
    cout<<"height: "<<B.height();
    cout<<endl;
    cout<<"min element: "<<B.findMinimum()->data<<endl;
    cout<<"max element: "<<B.findMaximum()->data<<endl;
    cout<<"InOrder: ";
    B.printInOrder();
    cout<<endl;
    cout<<"PreOrder: ";
    B.printPreOrder();

    return 0;
}
