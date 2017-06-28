#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(const int&ele=0,Node*temp=0):data(ele),next(temp){}
};

Node*createList(){
    Node*head=0,*prev=0;
    int value;                                      //O(n) time , O(1) space
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

Node*createList2(){
    Node*prev=0;
    int value;
    cout<<"Enter the list(-1 to terminate): ";
    cin>>value;
    while(value!=-1){
        Node*curr=new Node(value);
        prev?curr->next=prev:curr->next=0;
        prev=curr;
        cin>>value;
    }
    return prev;
}
void printList(Node*head){
    while(head){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
    return;
}

void printListRecursive(Node*head){
    if(!head){
        cout<<"NULL";
        return;
    }
    cout<<head->data<<"-->";
    printListRecursive(head->next);
    return;
}

void print(Node**head){
    /*
    if(!*head){
        cout<<"NULL";
        return;
    }
    cout<<(*head)->data<<"-->";
    print(&(*head)->next);
    return;
    */
    while(*head){
        cout<<(*head)->data<<"-->";
        (*head)=(*head)->next;
    }
    cout<<"NULL";
    return;
}
/*
void print(Node*&head){
   
   // if(!head){
     //   cout<<"NULL";
       // return;
   // }
   // cout<<head->data<<"-->";
   // print(head->next);
   // return;
   
    while(head){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
    return;
}
*/

int length(Node*head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}
int lengthRecursive(Node*head){
    return !head?0:1+lengthRecursive(head->next);
}

Node*findKthNode(Node*head,int K){
    if(K<0)return NULL;
    if(!K)return head;
    //if(K<0||K>length(head)-1)return NULL;
    while(K--&&head){
        head=head->next;        
    }                           
    return head;
}
Node*findKthNodeRecursive(Node*head,int K){              // we are just traversing linearly , just a loop Time Complexity O(n)
    if(K<0)return NULL;
    if(!K||!head)return head;
    return findKthNodeRecursive(head->next,K-1);
}

void InsertAtKthIndex(Node*&head,int K,int value){
    Node*temp=new Node(value);
    if(!K){
       temp->next=head;
       head=temp;
       return;
    }
    Node*prevToK=findKthNode(head,K-1);
    if(prevToK){
        temp->next=prevToK->next;
        prevToK->next=temp;
    }
    return;
}

Node*InsertAtKthIndexRecursive(Node*&head,int K,int value){
    static Node*temp=new Node(value);
    if(K>length(head))return head;
    if(!K){
        temp->next=head;    // here we are setting the next pointer on the call of the function
        head=temp;
        return head;
    }
    head->next=InsertAtKthIndexRecursive(head->next,K-1,value); // here we are setting the next pointer on the return
    return head;
}

void deleteKthNode(Node*&head,int K){
    if(K>=length(head))return;
    if(!K){
        Node*temp=head;
        head=head->next;
        delete temp;
        return;
    }
    Node*prevToK=findKthNode(head,K-1);
    if(prevToK){
        Node*temp=prevToK->next;
        prevToK->next=temp->next;
        delete temp;
    }
    return;
}


Node*deleteKthNodeRecursive(Node*&head,int K){
    if(K>=length(head))return head;
    if(!K){
        Node*temp=head;
        head=head->next;
        return head;
    }
    head->next=deleteKthNodeRecursive(head->next,K-1);
    return head;
}
    

void freeList(Node*&head){
    while(head){
        Node*temp=head;
        head=head->next;
        delete temp;
    }
    return;
}
void freeListRecursive(Node*&head){
    if(!head)return;
    freeListRecursive(head->next);
    delete head;
    head=0;
    return;
}

int main(){
    Node*head=createList();
    printList(head);
    //printListRecursive(head);
    //print(&head);
    //cout<<endl;
    //print(&head);
    cout<<endl;
    //cout<<"length: "<<length(head)<<endl;
    //cout<<"length Recursive: "<<lengthRecursive(head)<<endl;
    //cout<<findKthNode(head,0)->data<<endl;
    //cout<<findKthNodeRecursive(head,0)->data<<endl;
    //InsertAtKthIndex(head,7,78);
    //deleteKthNode(head,0);
    //freeListRecursive(head);
    //freeList(head);
    printList(head);
    cout<<endl;
    //freeList(head);
    //deleteKthNodeRecursive(head,2);
    //InsertAtKthIndexRecursive(head,0,89);
    printList(head);
    cout<<endl;
    return 0;
}


