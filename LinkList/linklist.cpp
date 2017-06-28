#include<iostream>
using namespace std;

struct Node{
    int data;
    Node*next;

    Node(const int&ele=0,Node*temp=0):data(ele),next(temp){}
};
/***************************************************************************************************************************************/
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
/***************************************************************************************************************************************/
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
/****************************************************************************************************************************************/
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
/****************************************************************************************************************************************/

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

/****************************************************************************************************************************************/
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
/****************************************************************************************************************************************/
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
/*****************************************************************************************************************************************/
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
/*****************************************************************************************************************************************/
void reversePrintRecursive(Node*head){
    if(!head){
        cout<<"NULL";
        return;
    }
    reversePrintRecursive(head->next);
    cout<<"<--"<<head->data;
    return;
}
void reversePrint(Node*head){
    cout<<"NULL";
    /*
    for(int i=0;i<length(head);i++){
        Node*temp=head;
        for(int j=0;j<length(head)-i-1;j++){
           temp=temp->next;
        }
        cout<<"<--"<<temp->data;
    }
    */
                        // time complexity is O(n^2)
                      // the way to think is that we go to last item in first iteration, second last in the second iteration and so on ....
                     //number of iterations are n and work done in each iteration is O(n)
    Node*last=0;
    while(head!=last){
        Node*curr=head;
        while(curr->next!=last){
            curr=curr->next;
        }
        cout<<"<--"<<curr->data;
        last=curr;
    }
    return;
}
/*****************************************************************************************************************************************/

Node*findKthNodeFromEnd(Node*head,int K){
   /*
   //Method 1
   int len=length(head);
   for(int i=0;i<len-K-1;i++){
        head=head->next;
    }
    return head;
    */
    //Method 2
    Node*ahead=head;
    while(K--){
        ahead=ahead->next;
    }
    while(ahead->next){
        head=head->next;
        ahead=ahead->next;
    }
    return head;
    
}
/*****************************************************************************************************************************************/

int index(Node*head,Node*temp){
    return head==temp?0:1+index(head->next,temp);
}
/****************************************************************************************************************************************/
int frequency(Node*head,int ele){
   return !head?0:head->data==ele?1+frequency(head->next,ele):frequency(head->next,ele);
}
/****************************************************************************************************************************************/
void reverseList(Node*&head){
    Node*NEXT=0,*prev=0;
    while(head){
        NEXT=head->next;
        head->next=prev;
        prev=head;
        head=NEXT;
    }
    head=prev;
    return;
}
Node*reverseListRecursive(Node*head){  // Note : if here we use Node*&head , there will be problem, if input is 1-->2-->3-->4-->5-->NULL
    if(!head||!head->next)return head; // then after call to this function , if we do printList(head) output will be 5-->1-->NULL
    Node*temp=reverseListRecursive(head->next);// because here we are creating alias of next pointer of each block of memory
    head->next->next=head;
    head->next=0;           
    // head=temp ~ wrong output is we do this , and create an alias to each  next pointer of the block of the memory
    return temp;
}

//Don't create alias to each next pointer of the block of memory, rather creates an extra rest pointer for doing this
void recursiveReverse(Node*&head){
    if(!head)return;
    Node*rest=head->next;
    if(!rest)return;            // time complexity is O(n) and space complexity is also O(n) as rest is made in each iteration
    recursiveReverse(rest);
    head->next->next=head;
    head->next=0;
    head=rest;
    return;
}
/****************************************************************************************************************************************/

Node*findMidElement(Node*head){
    /*
    int len=length(head);
    for(int i=0;i<len/2;i++){       // for even elements , it return second middle element
        head=head->next;
    }
    return head;
    */
    /*
    Node*mid=head;
    while(mid&&mid->next){
                                // returns the second middle element if elements are even
        mid=mid->next->next;
        if(!mid)break;// now it returns the first middle element
        head=head->next;
    }
    return head;
*/
    int Count=0;
    Node*mid=head;
    while(head){
        head=head->next;
        if(!head)break;
        if(Count&1){
            mid=mid->next;
        }
        Count++;
    }
    return mid;
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
    //printList(head);
    //cout<<endl;
    //freeList(head);
    //deleteKthNodeRecursive(head,2);
    //InsertAtKthIndexRecursive(head,0,89);
    //printList(head);
    //cout<<endl;
    //reversePrintRecursive(head);
    //cout<<findKthNodeFromEnd(head,1)->data;
    //reverseList(head);
    //printList(head);
    //printList(reverseListRecursive(head));
    //recursiveReverse(head);
    //printList(head);
    cout<<findMidElement(head)->data<<endl;
    cout<<endl; 
    return 0;
}


