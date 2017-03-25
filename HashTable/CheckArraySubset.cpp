/**
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not 
in sorted order. It may be assumed that elements in both array are distinct.

Examples:
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4}
Output: arr2[] is a subset of arr1[]

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3}
Output: arr2[] is not a subset of arr1[]

Method 1 (Simple)
Use two loops: The outer loop picks all the elements of arr2[] one by one. The inner loop linearly searches for the element 
picked by outer loop.
If all elements are found then return 1, else return 0.

Time complexity: O(mn)

Method 2:
1) Sort arr1[] O(mLogm)
2) For each element of arr2[], do binary search for it in sorted arr1[].
         a) If the element is not found then return 0.
         3) If all elements are present then return 1.
       Time Complexity: O(mLogm + nLogm). Please note that this will be the complexity if an mLogm algorithm is used 


Method 3 (Use Sorting and Merging )

1) Sort both arrays: arr1[] and arr2[] O(mLogm + nLogn)
2) Use Merge type of process to see if all elements of sorted arr2[] are present in sorted arr1[].

Time Complexity: O(mLogm + nLogn) which is better than method 2. Please note that this will be the complexity if an nLogn algorithm is used for sorting both arrays

Note: we should use merge sort rather than quick sort in method2 and method3 because worst case time complexity of quick sort isO(n^2)

Method 4: Hashing


1) Create a Hash Table for all the elements of arr1[].
2) Traverse arr2[] and search for each element of arr2[] in the Hash Table. If element is not found then return 0.
3) If all elements are found then return 1.

Note that method 1, method 2 and method 4 don’t handle the cases when we have duplicates in arr2[]. For example, {1, 4, 4, 2} is 
not a subset of {1, 4, 2}, but these methods will print it as a subset.
*/

#include<iostream>
#include<unordered_set>
using namespace std;

//Method 3 assuming that both array are alrady sorted

bool isSubset(int arr1[],int M,int arr2[],int N){
    int i=0,j=0;
    if(M<N)return false;
    while(i<N&&j<M){
        if(arr1[j]<arr2[i]){
            j++;
        }else if(arr1[j]==arr2[i]){
            i++;j++;
        }
        else{
            break;
        }
    }
    return i==N;
}

int main(){
    int N,M,arr1[100],arr2[100];
    cout<<"Enter array1 size: ";
    cin>>M;
    cout<<"Enter array1: ";
    for(int i=0;i<M;i++){
        cin>>arr1[i];
    }
    cout<<"Enter array2 size: ";
    cin>>N;
    cout<<"Enter array2: ";
    for(int i=0;i<N;i++){
        cin>>arr2[i];
    }
    if(isSubset(arr1,M,arr2,N)){
        cout<<"array2 is subset of array1";
    }
    else{
        cout<<"not a subset";
    }
    return 0;
}
/**
int main(){
  
   
    int value,N,i;
    unordered_set<int>S;
    cout<<"Enter array1 size: ";
    cin>>N;
    cout<<"Enter array1: ";
    for(int i=0;i<N;i++){
        cin>>value;
        S.insert(value);
    }
    cout<<"Enter array2 size: ";
    cin>>N;
    cout<<"Enter array2: ";
    for( i=0;i<N;i++){
        cin>>value;
        if(S.find(value)==S.end()){
            break;
        }
    }
    if(i==N){
        cout<<"array2 is subset of array1"<<endl;
    }
    else{
        cout<<"not a subset"<<endl;
    }
    
 

    
    return 0;
}

    
**/
