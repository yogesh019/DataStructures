#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 // Simply a combination problem
/*
Include and Exclude every element
 We one by one consider every element of input array, and recur for two cases:

1 The element is included in current combination (We put the element in data[] and increment next available index in data[])
2 The element is excluded in current combination (We do not put the element and do not change index)

When number of elements in data[] become equal to r (size of a combination), we print it.

This method is mainly based on Pascal’s Identity, i.e. ncr = n-1cr + n-1cr-1

*/

void printSubsetsOfSizeK(int *arr,int n,int *data,int index,int K){
    if(!K){
        cout<<"{";
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    if(K>n)return;
    data[index]=arr[n-1];
    printSubsetsOfSizeK(arr,n-1,data,index+1,K-1);
    while(arr[n-1]==arr[n-2])
       n--; 
    printSubsetsOfSizeK(arr,n-1,data,index,K);
    return;
}

void printSubsetsOfSizeK(int*arr,int n,int index,int K){
    static vector<int>data;
    if(data.size()==K){
        for(int i=0;i<K;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(index==n)return;
    data.push_back(arr[index]);
    printSubsetsOfSizeK(arr,n,index+1,K);
    while(arr[index]==arr[index+1])
        index++;
    data.pop_back();
    printSubsetsOfSizeK(arr,n,index+1,K);
    return;
}
/****************************************************************************************************************************************/
///Note: There is an alternative method of doing these type of questions
/*
The idea is to start from first index (index = 0) in data[], one by one fix elements at this index and recur for remaining indexes. 
Let the input array be {1, 2, 3, 4, 5} and r be 3.
We first fix 1 at index 0 in data[], then recur for remaining indexes, then we fix 2 at index 0 and recur. 
Finally, we fix 3 and recur for remaining indexes.
When number of elements in data[] becomes equal to r (size of a combination), we print data[].
*/

void printSubsetsOfSizeK(int*arr,int Start,int End,int *data,int index,int K){
    if(!K){
        cout<<"{";
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<"}";
        cout<<endl;
        return;
    }
    if(K>(End-Start+1))
        return;
    for(int i=Start;i<=End;i++){
        data[index]=arr[i];
        printSubsetsOfSizeK(arr,i+1,End,data,index+1,K-1);
        while(arr[i]==arr[i+1])
            i++;
    }
    return;
}
/*
How to handle duplicates?
Note that the above method doesn’t handle duplicates. For example, if input array is {1, 2, 1} and r is 2, then the program prints {1, 2} and {2, 1} as two different combinations.
 We can avoid duplicates by adding following two additional things to above code.
1) Add code to sort the array before calling printSubsetsOfSizeK() in printSubsetsOfSizeK()
2) Add following lines at the end of for loop in printSubsetsOfSizeK()

        // Since the elements are sorted, all occurrences of an element
        // must be together
        while (arr[i] == arr[i+1])
             i++;

*/
int main(){
    int arr[100],n,K,data[100];
    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
       }
    cout<<"Enter K: ";
    cin>>K;
    sort(arr,arr+n);
    printSubsetsOfSizeK(arr,n,data,0,K);
    cout<<endl<<endl<<endl;
    printSubsetsOfSizeK(arr,0,n-1,data,0,K);
    cout<<endl<<endl<<endl;
    printSubsetsOfSizeK(arr,n,0,K);
    return 0;
}
