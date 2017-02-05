#include"GenericTree.h"
int main(){
    GenericTree<char>G1;
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
