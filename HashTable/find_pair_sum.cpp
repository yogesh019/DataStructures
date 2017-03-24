/**
Given an array A[] and a number x, check for pair in A[] with sum as x

METHOD 1 (Use Sorting)

Algorithm:

hasArrayTwoCandidates (A[], ar_size, sum)
1) Sort the array in non-decreasing order.
2) Initialize two index variables to find the candidate
   elements in the sorted array.
       (a) Initialize first to the leftmost index: l = 0
       (b) Initialize second  the rightmost index:  r = ar_size-1
3) Loop while l < r.
       (a) If (A[l] + A[r] == sum)  then return 1
       (b) Else if( A[l] + A[r] <  sum )  then l++
       (c) Else r--
4) No candidates in whole array - return 0

Time Complexity: Depends on what sorting algorithm we use. If we use Merge Sort or Heap Sort then (-)(nlogn) in worst case. If we
use Quick Sort then O(n^2) in worst case.
Auxiliary Space : Again, depends on sorting algorithm. For example auxiliary space is O(n) for merge sort and O(1) for Heap Sort.


Using Hashing
1) Initialize Binary Hash Map M[] = {0, 0, ...}
2) Do following for each element A[i] in A[]
   (a)  If M[x - A[i]] is set then print the pair (A[i], x - A[i])
   (b)  Set M[A[i]]

   **/

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[100],n,sum;
    cout<<"Enter the array size: ";
    cin>>n;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the sum: ";
    cin>>sum;
    unordered_map<int,bool>M;
    for(int i=0;i<n;i++){
        int temp=sum-arr[i];
        if(M[temp])
           cout<<"pair is: ("<<arr[i]<<","<<temp<<")"<<endl;
        M[arr[i]]=true;
    }
    return 0;
}


