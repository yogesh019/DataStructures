#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;

/***********************************************************************************************************************************************************/
void printReverse(const char*str){

    if(!(*str))return;
                                                                            /// PRINT REVERSE OF A STRING
    printReverse(str+1);
    cout<<(*str);
    return;
}

void reverseString(char*str){

        stack<char>S;
        int i=0;                                            /// REVERSE A STRING USING STACK O(n)
        while(str[i]){
            S.push(str[i]);
            i++;
        }
        i=0;
        while(!S.empty()){
            str[i]=S.top();
            S.pop();
            i++;
        }
}
/*********************************************************************************************************************************************************/
                    /// REVERSING A STACK
template<typename T>
void reverseStack(stack<T>&S){
    stack<T>S1;
    while(!S.empty()){
        S1.push(S.top());
        S.pop();
    }
    S=S1; ///assignment operator gets called
}

template<typename T>
void insertIntoBottom(stack<T>&S,const T&ele){
    if(S.empty()){
        S.push(ele);
        return;
    }
       const T temp=S.top();  /// don't use T&temp here , because it will create a reference to the top element always and we get the wrong result
    S.pop();
    ///cout<<temp<<" ";
    insertIntoBottom(S,ele);
    ///cout<<temp<<" ";
    S.push(temp);
    return;

}
template<typename T>
void reverseStackRecursive(stack<T>&S){
    if(S.empty())return;
    T temp=S.top();
    S.pop();
    reverseStackRecursive(S);
    insertIntoBottom(S,temp);
    return;
}
/********************************************************************************************************************************************************/
                                    ///CHECK IF THE PARANTHESIS ARE BALANCED OR NOT
bool checkParanthesisBalanced(const char*s){
   stack<char>S;
    while(*s){
        if(*s=='('||*s=='['||*s=='{'){
            S.push(*s);
           }
           else if(*s==')'||*s==']'||*s=='}'){
                if(S.empty())return false;
                if((*s-S.top())==1||(*s-S.top())==2){
                    S.pop();
                }

           }
           s++;
    }
    return S.empty()?true:false;
}
/********************************************************************************************************************************************************/
                                                                /// SORT A STACK USING RECURSION
template<typename T>
void insertIntoCorrect(stack<T>&S,const T&ele){
    if(S.empty()||S.top()<=ele){
        S.push(ele);
        return;
    }
    T temp=S.top();S.pop();
    insertIntoCorrect(S,ele);
    S.push(temp);
    return;
}

template<typename T>
void sortStack(stack<T>&S){
    if(S.empty())return;
    T temp=S.top();S.pop();
    sortStack(S);
    insertIntoCorrect(S,temp);
    return;

}
/********************************************************************************************************************************************************/
        ///EVALUATION OF POSTFIX EXPRESSION

                                                                                                 ///POLISH NOTATION IS PEFIX AND REVERSE POLISH IS POSTFIX
int EvaluatePostfix(const char*str){
    stack<int>S;                             /// here we have evaluated for a single digit operand we can extend this function for multi digit operand also , by adding a seperator in the
    while(*str){                             /// input string
        if(*str>='0'&&*str<='9')S.push(*str-'0');
        else{
                int value1=S.top();S.pop();
                int value2=S.top();S.pop();
            switch(*str){
                case '+':S.push(value1+value2);break;
                case '-': S.push(value2-value1);break;
                case '*':S.push(value2*value1);break;
                case '/':S.push(value2/value1);break;
            }
        }
        str++;
    }
return S.top();
}
/*********************************************************************************************************************************************************/

int Precedence(const char ch){

    switch(ch){
        case '+':
        case '-':
                        return 1;
        case '*':
        case '/':
        case '%':
                        return 2;
        case '^':
                        return 3;
    }
return -1; /// for '(' in stack
}

void InfixToPostfix(char*str){

    int i=0,k=0;
    stack<char>S;
    while(str[i]){
    ///cout<<"yogesh"<<endl;
        if( (str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='Z')||(str[i]>='a'&&str[i]<='z') ){
            str[k++]=str[i];
        }
        else if(str[i]=='('){
                    S.push(str[i]);
                }
        else if(str[i]==')'){
            while(S.top()!='('){
                str[k++]=S.top();
                S.pop();
                }
                S.pop();
                }
        else{
            while(!S.empty()&&Precedence(S.top())>=Precedence(str[i])){
                str[k++]=S.top();
                S.pop();
            }
            S.push(str[i]);
        }
    i++;
    }
    while(!S.empty()){
        str[k++]=S.top();
        S.pop();
    }
    str[k]=0;
return;
}
/********************************************************************************************************************************************************/
            /// EXPRESSION TREE NODE
class ETNode{
    char data;
    ETNode*left,*right;
public:
    ETNode(const char&ele=0,ETNode*Left=0,ETNode*Right=0):data(ele),left(Left),right(Right){}
    friend class ET;
};

class ET{
stack<ETNode*>S;
public:
    void constructTree(char*postfix){

            while(*postfix){
                    if(((*postfix)>='0'&&(*postfix)<='9')||((*postfix)>='A'&&(*postfix)<='Z')||((*postfix)>='a'&&(*postfix)<='z') ){
                            S.push(new ETNode(*postfix));
                    }else{
                            ETNode*op1=S.top();S.pop();
                            ETNode*op2=S.top();S.pop();
                            S.push(new ETNode(*postfix,op2,op1));
        }
                    postfix++;
    }

   cout<<S.size()<<endl;
    }

            void printInOrder(){
                                                                                        /// This will print the infix expression
                    if(S.empty())return;
                    printInOrderHelper(S.top());
}
            void printPreOrder(){             /// This will print the prefix expression
                if(S.empty())return;
                printPreOrderHelper(S.top());
            }
private:
    static void printInOrderHelper(ETNode*et){
        if(!et)return;
        printInOrderHelper(et->left);
        cout<<et->data<<" ";
        printInOrderHelper(et->right);
        return;
    }
    static void printPreOrderHelper(ETNode*et){
        if(!et)return;
        cout<<et->data<<" ";
        printPreOrderHelper(et->left);
        printPreOrderHelper(et->right);
        return;
    }

};
/**
Note: I we want to construct an expression tree from prefix then we scan the prefix expression from right to left and if we encounter an operand we  push it on to stack,
and if it is an operator we pop op1, op2 from stack and concatenate in order of (op1,op2,opt) i.e in left goes op1 and in right op2**/
/*********************************************************************************************************************************************************/
/**
Q.  NEXT GREATER ELEMENT
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

*/
template<typename T>
void printNGE2Loops(T*arr,int n){
                                                            /// time complexity is O(n^2)
    for(int i=0;i<n;i++){
            int next=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                next=arr[j];
                break;
            }
        }
        cout<<"("<<arr[i]<<","<<next<<")"<<endl;
    }
return;
}

/// NOW USING STACK , TIME COMPLEXITY IS O(n)
/// space complexity is 0(n) , in worst case when all the elemnts are in decreasing order in the array
/// we have to create the stack of size n to store all the elements and their NGE is -1
template<typename T>
void printNGE(const T*arr,int n){

    stack<T>S;
/**
    for(int i=0;i<n;i++){
        while(!S.empty()&&arr[i]>S.top()){
            cout<<"("<<S.top()<<","<<arr[i]<<")"<<endl;
            S.pop();
        }
        S.push(arr[i]);
    }
    while(!S.empty()){
         cout<<"("<<S.top()<<","<<-1<<")"<<endl;
         S.pop();
    }
**/
    ///LET'S START FROM BACK

    for(int i=n-1;i>=0;i--){
        while(!S.empty()&&arr[i]>=S.top()){
            S.pop();
        }
        if(!S.empty())
            cout<<"("<<arr[i]<<","<<S.top()<<")"<<endl;
        else
            cout<<"("<<arr[i]<<","<<-1<<")"<<endl;
        S.push(arr[i]);
    }
}
/********************************************************************************************************************************************************/

                            /// REVERSE QUEUE
template<typename T>
void reverseQueueRecursive(queue<T>&Q){
    if(Q.empty())return;
    T temp=Q.front();Q.pop();
    reverseQueueRecursive(Q);
    Q.push(temp);
    return;
}
template<typename T>
void reverseQueue(queue<T>&Q){
    stack<T>S;
    while(!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
    while(!S.empty()){
        Q.push(S.top());
        S.pop();
    }
return;
}
/*********************************************************************************************************************************************************/
/// CHECK DUPLICATE PARANTHESIS

/**start pushing each character from input string till you not hit close parenthesis. When you hit close parenthesis, start pop the element till you not hit open parenthesis.
If the immediate pop hit open parenthesis than that is duplicate parenthesis.
Note: this algo will fail, if one put false parenthesis in string like: ()
**/
bool checkDuplicateParanthesis(const char*str){

    stack<char>S;
    while(*str){
        if((*str)!=')'&&(*str)!=' '){
            S.push(*str);
           }else if(*str==')'){
                if(S.empty())continue;
                if(S.top()=='(')return true;
                while(!S.empty()&&S.top()!='('){
                        S.pop();
                      }
                      S.pop();
           }
           str++;
    }
return false;
}
bool DuplicateParanthesis(const char *s){

int i=0;
stack<int>paran_index;
int lastPop=0;                                      /// PARANTHESIS SHOULS NOT CONTAIN SPACES BETWEEN THEM
int prevIndex=-1;
while(s[i]){
    if(s[i]=='('){
        paran_index.push(i);
        lastPop=0;
       }
    else if(s[i]==')'){
        if(prevIndex-paran_index.top()==1&&lastPop==1){
            return true;
        }
        prevIndex=paran_index.top();
        paran_index.pop();
        lastPop=1;
    }
    else{
        lastPop=0;
    }
    i++;
}
return false;
}
/********************************************************************************************************************************************************/
/// STOCK SPAN PROBLEM
/// This is similar to NGE , brute force technique will solve it in O(n^2) by comparing each element by it'sprevious elements
/// we can avoid this by using stack and avoiding the un-necessary comparisons
vector<int>calculateSpan(int *price,int n){
    stack<int>S;
    vector<int>v(n);
    /**
    v[0]=1;
    for(int i=1;i<n;i++){
        v[i]=1;
        for(int j=i-1;j>=0&&price[i]>=price[j];j--){
            v[i]++;
        }
    }
    **/
    for(int i=0;i<n;i++){                                                                   /// it will take O(n) time and O(n) space when wort case is when prices are in decreasing order
        while(!S.empty()&&price[i]>=price[S.top()]){
            S.pop();
        }
        v[i]=S.empty()?i+1:i-S.top();
        S.push(i);
    }
return v;
}
/********************************************************************************************************************************************************/

/// TOWER OF HANOI
/**
You can solve the recurrence and obtain a closed form.

T(n) = 2*T(n-1) + 1

T(n) = 2 * ( 2 * T(n-2) + 1) + 1

T(n) = (2 ^ 2) * T(n-2) + 2^1 + 2^0

T(n) = (2^k) * T(n-k) + 2^(k-1) + 2^(k-2) + ... + 2^0

Solving this the closed from comes out to be

T(n) = (2^n) - 1 with T(0) = 0

Now use exponentiation by squaring.
**/

void TowerOfHanoi(int n,char src,char dest,char path){
    if(!n)return;
    TowerOfHanoi(n-1,src,path,dest);
    cout<<"Move Disc "<<n<<" from "<<src<<" to "<<dest<<endl;
    TowerOfHanoi(n-1,path,dest,src);
    return;
}
/***************************************************************************************************************************************/

// An Interseting Method to Generate Binary Numbers From 1 to N

void GenerateBinaryNumbers(int N){
    queue<string>Q;
    Q.push("1");
    while(N--){
        Q.push(Q.front()+"0");
        Q.push(Q.front()+"1");
        cout<<Q.front()<<endl;
        Q.pop();
    }
    return;
}
int main(){

try{
    ///char str[]="yogesh";
    char str[]="((a+b))";
    char par[]="{}()[]{{}}()[";
   char post[]="231*+9-";
   char exp[]="a+b*(c^d-e)^(f+g*h)-i";
    int arr[]={11,13,21,3};
    int price[]={100,80,60,70,60,75,85};
    int N;
    cout<<"Enter N: ";
    cin>>N;
    GenerateBinaryNumbers(N);
    cout<<endl;   
    //TowerOfHanoi(5,'A','C','B');
    /**
    vector<int>v=calculateSpan(price,7);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    **/
   ///cout<<DuplicateParanthesis(str);
   /**
    queue<int>Q;
    for(int i=0;i<10;i++){
        Q.push(i);
    }
    reverseQueueRecursive(sQ);
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();;
    }**/
    ///ET E;
    ///E.constructTree(post);
    ///E.printInOrder();
    cout<<endl;
    ///E.printPreOrder();
    ///printReverse(str);
    ///reverseString(str);
    ///cout<<str<<endl;
    //printNGE2Loops(arr,4);
    ///printNGE(arr,4);
    /**
    stack<int>S;
    for(int i=0;i<10;i++){
        S.push(i*i);
    }
    reverseStackRecursive(S);
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
    **/
    /**
    stack<c
    har>S;
    S.push('D');
    S.push('B');
    S.push('C');
    S.push('Z');

    sortStack(S);
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
**/
///cout<<EvaluatePostfix(post);
///InfixToPostfix(exp);
///cout<<exp<<endl;
///cout<<checkParanthesisBalanced(par)<<endl;
///cout<<par;

}catch(const char*error){
    cerr<<error;
}
return 0;
}
