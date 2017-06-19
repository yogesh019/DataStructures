#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<cstring>
using namespace std;

/*Subarray/Substring

A subbarray is a contiguous part of array. An array that is inside another array. For example, consider the array [1, 2, 3, 4], 
There are 10 non-empty sub-arrays. The subbarays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4).
In general, for an array/string of size n, there are n*(n+1)/2 non-empty subarrays/subsrings.
There are  n(n+1)/2  +  1  substrings of a string       
 n is no of characters in string, as we have 1 sub-strings of length n, 2 of length n-1, ... n sub-strings of length 1.

Subsequence/Subsets

A subsequence is a sequence that can be derived from another sequence by zero or more elements, without changing the order 
of the remaining elements.For the same example, there are 15 sub-sequences. They are (1), (2), (3), (4), (1,2), (1,3),(1,4), 
(2,3), (2,4), (3,4), (1,2,3), (1,2,4), (1,3,4), (2,3,4), (1,2,3,4). More generally, we can say that for a sequence of size n, 
we can have (2^n-1) non-empty sub-sequences in total.

A string example to differentiate: Consider strings “geeksforgeeks” and “gks”. “gks” is a subsequence of “geeksforgeeks” 
but not a substring. “geeks” is both a subsequence and subarray. Every subarray is a subsequence. 
More specifically, Subsequence is a generalization of substring.

There are total 2^n(nC0+nC1+nC2+nC3+.....nCn, no. of ways of selecting 0,1,2,...n objects out of n) subsets/subsequences of a set. 
*/
void generateAllSubstrings(string str){
    static set<string>S;
    if(str.empty()){
        for(set<string>::iterator it=S.begin();it!=S.end();it++){
            cout<<*it<<endl;
        }
   return;     
    }
    for(int i=0;i<str.size();i++){
       S.insert(str.substr(0,i+1));
    }
    generateAllSubstrings(str.substr(1));
    return;
}

void printAllSubstrings(char*str){
    for(int i=0;i<strlen(str);i++){
        for(int j=i;j<strlen(str);j++){
            for(int k=i;k<=j;k++){
                cout<<str[k]<<" ";          // Time Complexity ~ O(n^3)
            }
            cout<<endl;
        }
    }
    return;
}


int main(){
    char str[]="yogesh";
    //generateAllSubstrings(str);
    printAllSubstrings(str);
    return 0;
}

