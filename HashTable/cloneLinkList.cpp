#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
    Node*next,*random;
    Node(const int&ele=0):data(ele),next(0),random(0){}
};

Node*createList(){
    Node*head=0,*prev=0;
    int value;
    cout<<"Enter the list(-1 to terminate): ";
    cin>>value;
    while(value!=-1){
        Node*curr=new Node(value);
        if(!head){
            head=curr;
        }else{
            prev->next=curr;
        }
        prev=curr;
    cin>>value;
    }
    return head;
}

Node*cloneList(Node*head){
    Node*head2=0,*prev=0;
    Node*temp=head;
        unordered_map<Node*,Node*>M;
    while(temp){
        Node*newNode=new Node(temp->data);
        if(!head2){
            head2=newNode;
        }else{
            prev->next=newNode;
        }
        prev=newNode;
        M[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    prev=head2;
    while(temp){
        prev->random=M[temp->random];
        temp=temp->next;
        prev=prev->next;
    }
    return head2;
}

void printList(Node*head){
    if(!head){
        cout<<"NULL";
        return;
    }
    cout<<head->data<<"-->";
    printList(head->next);
    return;
}

void freeList(Node*&head){
    if(!head)
        return;
    freeList(head->next);
    delete head;
    head=0;
    return ;
}
int main(){
    Node*head=createList();
    printList(head);
    cout<<endl<<endl;
    head->random=head->next->next;
    head->next->random=head->next->next->next;
    head->next->next->random=head->next->next->next->next;
    Node*head2=cloneList(head);
    freeList(head);
    printList(head2);
    cout<<endl<<endl;
    cout<<head2->random->data<<endl;
    return 0;
}
