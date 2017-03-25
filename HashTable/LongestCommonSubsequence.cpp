/*
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive 
integers, the consecutive numbers can be in any order. 

One Solution is to first sort the array and find the longest subarray with consecutive elements. Time complexity of this 
solution is O(nLogn). Thanks to Hao.W for suggesting this solution here.
*/
#include<iostream>
#include<unordered_set>
using namespace std;

int findLongestConsecutiveSubsequence(int *arr,int N){
    unordered_set<int>check;
    for(int i=0;i<N;i++){
        check.insert(arr[i]);
    }
    int res=0;
    for(int i=0;i<N;i++){
        if(check.find(arr[i]-1)==check.end()){
            int j=arr[i];
            while(check.find(j)!=check.end()){
                j++;
            }
            res=max(res,j-arr[i]);
        }
    }
    return res;
}

int main(){
    int arr[100],N;
    cout<<"Enter the array size: ";
    cin>>N;
    cout<<"Enter the array elements: ";
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    cout<<"length of longest Consecutive Subsequence is: "<<findLongestConsecutiveSubsequence(arr,N)<<endl<<endl;
      return 0;
} 

/*Note
 Time Complexity: At first look, time complexity looks more than O(n). If we take a closer look, we can notice that it is O(n) 
 under the assumption that hash insert and search take O(1) time. The function S.find() inside the while loop is called at 
 most twice for every element. For example, consider the case when all array elements are consecutive. 
 In this case, the outer find is called for every element, but we go inside the if condition only 
 for the smallest element. Once we are inside the if condition, we call find() one more time for every other element.*/


