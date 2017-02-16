#include"BinarySearchTree.h"
int main(){
    BinarySearchTree<int>B;
    int pre[]={10,5,1,7,40,50};
    int arr[]={1,2,3,4,5,6,7};
    //B.constructBSTfromPreOrder(pre,6);
    //B.buildBalancedBST(arr,7);
    char ch;
    B.insertElementRecursive(20);
    B.insertElementRecursive(8);
    B.insertElementRecursive(22);
    B.insertElementRecursive(4);
    B.insertElementRecursive(12);
    B.insertElementRecursive(10);
    B.insertElementRecursive(14);
    //B.insertElementRecursive('E');
    //B.insertElementRecursive('H');
    
    //cout<<"Enter the node to delete: ";
    //cin>>ch;
    //B.deleteNodeIteratively(ch);
    
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
    cout<<endl;
    
    cout<<"LCA: "<<B.findLCA(10,14)->data<<endl;
    cout<<"LCA: "<<B.findLCA(14,8)->data<<endl;
    cout<<"LCA: "<<B.findLCA(10,22)->data<<endl;
    
    return 0;
}
