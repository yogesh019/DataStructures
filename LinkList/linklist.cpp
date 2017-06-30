#include<iostream>
#include<stack>
#include<unordered_set>
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
    while(K--&&ahead){
        ahead=ahead->next;
    }
    while(ahead&&ahead->next){
        head=head->next;
        ahead=ahead->next;
    }
    return ahead?head:ahead;
    
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
        //if(!head)break;
        if(Count&1){
            mid=mid->next;
        }
        Count++;
    }
    return mid;
}
/*****************************************************************************************************************************************/

bool checkPalindrome(Node*head){
    Node*mid=findMidElement(head);
    Node*initial=mid;
    reverseList(mid);
    Node*temp=mid;                                      // time complexity is O(n) and space complexity is O(1)
    while(head!=initial&&head->data==mid->data){
        head=head->next;
        mid=mid->next;
    }
    reverseList(temp);
    return head==temp;
}
bool checkPalindromeUsingStack(Node*head){
    stack<Node*>S;
    Node*temp=head;                 // time complexity is  O(n) and space complexity is also O(n)
    while(temp){
        S.push(temp);
        temp=temp->next;
    }
    while(head&&head->data==S.top()->data){
        head=head->next;
        S.pop();
    }
    return S.empty();
}
/***************************************************************************************************************************************/
void InsertInSortedLinklist(Node*&head,int value){
    static Node*newNode=new Node(value);
    if(!head||head->data>=value){
        newNode->next=head;
        head=newNode;
        return;
    }
    if(head->data<value&&head->next&&head->next->data>=value){
        newNode->next=head->next;
        head->next=newNode;
        return;
    }
    InsertInSortedLinklist(head->next,value);
    return;
}
/****************************************************************************************************************************************/

//Append last n nodes to start
void prepend(Node*&head,int n){
    /*
    //Method 1: create a gap b/w 2 pointers and when the faster recahes at the end , the slower will reach at it's correct position
    Node*curr=head,*ahead=head;
    while(n--&&ahead){
        ahead=ahead->next;
    }
    while(ahead&&ahead->next){
        ahead=ahead->next;
        curr=curr->next;
    }
    if(ahead&&curr){
        ahead->next=head;
        head=curr->next;
        curr->next=0;
    }
    return;
*/
    Node*temp=findKthNodeFromEnd(head,n);
    Node*last=findKthNodeFromEnd(head,0);
    if(temp&&last){
        last->next=head;
        head=temp->next;
        temp->next=0;
    }
    return;
}
/****************************************************************************************************************************************/

void swapIthAndJthNode(Node*&head,int i,int j){
    Node*ith=0,*iprev=0,*inext=0,*jth=0,*jprev=0,*jnext=0;
    if(i>j)return;
    if(i==0){
        ith=head;
        iprev=0;
        inext=ith->next;
    }else{
        iprev=findKthNode(head,i-1);
        if(!iprev)return;
        ith=iprev->next;
        inext=ith->next;
    }
    jprev=findKthNode(head,j-1);
    if(!jprev||jprev==iprev)return;
    jth=jprev->next;
    jnext=jth->next;
    if(i==0){
        head=jth;
    }else{
        iprev->next=jth;
    }
    ith->next=jnext;
    if(j==i+1){
        jth->next=ith;
    }else{
        jth->next=inext;
        jprev->next=ith;
    }
    return;
}
/****************************************************************************************************************************************/
// Reverse a linklist in groups of given  size
//Inputs:   1->2->3->4->5->6->7->8->NULL and k = 5
//Output:  5->4->3->2->1->8->7->6->NULL
Node*kReverse(Node*head,int K){
    int Count=K;
    Node*curr=head,*prev=0;
    while(Count--&&curr){
        Node*NEXT=curr->next;
        curr->next=prev;
        prev=curr;
        curr=NEXT;
    }
    if(curr)head->next=kReverse(curr,K);
    return prev;
}
/***************************************************************************************************************************************/
void removeDuplicatesSorted(Node*head){
    if(!head||!head->next)return ;
    if(head->data==head->next->data){
        Node*temp=head->next;                        // remove Duplicates From A Sorted Linklist ~ Takes O(n) time
        head->next=temp->next;
        delete temp;
    }else{
        head=head->next;
    }
    removeDuplicatesSorted(head);
    return;
}
/// remove Duplicates from an unsorted linklist
/**
METHOD 1 (Using two loops)
This is the simple way where two loops are used. Outer loop is used to pick the elements one by one and inner loop compares 
the picked element with rest of the elements.
It requires O(n^2) complexity

METHOD 2 (Use Sorting)
In general, Merge Sort is the best suited sorting algorithm for sorting linked lists efficiently.
1)  Sort the elements using Merge Sort O(nLogn)
2)  Remove duplicates in linear time using the algorithm for removing duplicates in sorted Linked List. O(n)

This method does not preserve the original order of elements
Time Complexity is O(nlogn)

Method 3(Hashing) : can do the job in linear O(n) time but takes space
**/ 

void removeDuplicatesUnsorted(Node*head){
    unordered_set<int>S;
    Node*prev=0;
    while(head){
        if(S.find(head->data)==S.end()){
            S.insert(head->data);
           
        }else{
            prev->next=head->next;
            delete head;
            head=prev->next;
            continue;
        }
        prev=head;
        head=head->next;
    }
    return;
}
            
/****************************************************************************************************************************************/

Node*merge2sortedLinklist(Node*head1,Node*head2){
    /*
    Node*head3=0;
    if(head1->data<head2->data){
        head3=head1;
        head1=head1->next;
    }else{
        head3=head2;
        head2=head2->next;
    }
    Node*temp=head3;
    while(head1&&head2){
        if(head1->data<head2->data){
            temp->next=head1;
            head1=head1->next;
        }else{
            temp->next=head2;
            head2=head2->next;
        }
        temp=temp->next;
    }
    while(head1){
        temp->next=head1;
        head1=head1->next;
        temp=temp->next;
    }
    while(head2){
        temp->next=head2;
        head2=head2->next;
        temp=temp->next;
    }
    return head3;
*/
    
    if(!head1)return head2;
    else if(!head2)return head1;
    else if(head1->data<head2->data){
        head1->next=merge2sortedLinklist(head1->next,head2);
        return head1;
    }
    
    head2->next=merge2sortedLinklist(head1,head2->next);
    return head2;
    
}
 
void merge_sort(Node*&head){
    if(!head||!head->next)return;//Time Complexity is O(nlogn), Merge Sort is favourible for linklist beacause no extra space is required 
    Node*mid=findMidElement(head);
    Node*prevToMid=findKthNode(head,length(head)/2-1);
    prevToMid->next=0;
    merge_sort(head);
    merge_sort(mid);
    head=merge2sortedLinklist(head,mid);
    return;
}
/***************************************************************************************************************************************/
// sort a linklist which has 2 halves sorted
void sort2halves(Node*&head){
    if(!head||!head->next)return;
    Node*mid=findMidElement(head);
    if(mid->data>mid->next->data){
        mid=mid->next;
    }
    int k=index(head,mid);
    Node*prevToMid=findKthNode(head,k-1);
    prevToMid->next=0;
    head=merge2sortedLinklist(head,mid);
    return;
}
/****************************************************************************************************************************************/
// SELECTION SORT

Node*removeSmallestFromList(Node*&head){
    Node*smallest=head,*smallest_prev=0;
    Node*temp=head->next,*prev=head;
    while(temp){
        if(smallest->data>temp->data){
            smallest=temp;
            smallest_prev=prev;
        }
        prev=temp;
        temp=temp->next;
    }
    if(smallest==head){
        head=head->next;
    }
    else{
        smallest_prev->next=smallest->next;
    }
    return smallest;
}
   
void selection_sort(Node*&head){                                 // proceeds by constructed a sorted as well as an unsorted array
    Node*unsortedHead=head,*sortedHead=0,*prev=0;               // Time Complexity in all cases is O(n^2)
    while(unsortedHead){
        Node*smallest=removeSmallestFromList(unsortedHead);
        if(!sortedHead){
            sortedHead=smallest;
        }else{
            prev->next=smallest;
        }
        prev=smallest;
    }
    head=sortedHead;
    return;
}
/****************************************************************************************************************************************/

void insertSorted(Node*head,Node*&sortedHead){
    if(!sortedHead||sortedHead->data>head->data){
        head->next=sortedHead;
        sortedHead=head;
    }else{
        Node*temp=sortedHead;
        while(temp->next&&temp->next->data<head->data){
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
    }
    return;
}
                                                         // Time Complexity ~ Best Case O(n)
void insertion_sort(Node*&head){                         // Average and Worst Case  O(n^2)
    Node*sortedHead=0;
    while(head){
        Node*NEXT=head->next;
        insertSorted(head,sortedHead);
        head=NEXT;
    }
    head=sortedHead;
    return;
}
/****************************************************************************************************************************************/

/*function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list.
 * Also, keep the order of even and odd numbers same.
 */

void segregateOddEven(Node*&head){
    Node*oddHead=0,*odd_prev=0;
    Node*evenHead=0,*even_prev=0;
    if(!head)return;
    while(head){                            // split the linklist into odd and even list
        if(head->data%2){                   // Time Complexity ~O(n)
            if(!oddHead){
                oddHead=head;
            }else{
                odd_prev->next=head;
            }
            odd_prev=head;
        }else{
            if(!evenHead){
                evenHead=head;
            }else{
                even_prev->next=head;
            }
            even_prev=head;
        }
    head=head->next;
    }
   
    if(evenHead&&!oddHead){
        head=evenHead;
        even_prev->next=0;
    }
    else if(oddHead&&!evenHead){
        head=oddHead;
        odd_prev->next=0;
    }
    else{
        odd_prev->next=0;
        even_prev->next=oddHead;
        head=evenHead;
    }
    return;
}
/***************************************************************************************************************************************/

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
    //cout<<findMidElement(head)->data<<endl;
    /*
    if(checkPalindromeUsingStack(head)){
        cout<<"list is Palindrome "<<endl;
    }else{
        cout<<"Not Palindrome "<<endl;
    }*/
    //InsertInSortedLinklist(head,9);
    //int n;
    //cout<<"Enter number of nodes to prepend: ";
    //cin>>n;
    //prepend(head,n);
    //int i,j;
    //cout<<"Enter the ith and jth node to swap: ";
    //cin>>i>>j;
    //swapIthAndJthNode(head,i,j);
    //printList(kReverse(head,3));
    //printList(head);
    //removeDuplicatesSorted(head);
    //removeDuplicatesUnsorted(head);
    //merge_sort(head);
    //sort2halves(head);
    //selection_sort(head);
    //insertion_sort(head);
    segregateOddEven(head);
    printList(head);
    cout<<endl; 
    return 0;
}


