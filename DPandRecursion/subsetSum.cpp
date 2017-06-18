#include<iostream>
#include<vector>
using namespace std;

/***************************************************************************************************************************************/
bool subsetSum(int*arr,int n,int sum,int *data,int index){
   if(!sum){
       for(int i=0;i<index;i++){
           cout<<data[i]<<" ";
       }
       cout<<endl;
       return true;
   }
   if(!n)
       return false;
   

   data[index]=arr[n-1];
   /* To print only 1 subset
   if(subsetSum(arr,n-1,sum-arr[n-1],data,index+1))
       return true;
   return subsetSum(arr,n-1,sum,data,index);
   */
   // To print All Subsets with given sum
  bool res1= subsetSum(arr,n-1,sum-arr[n-1],data,index+1);
  bool res2= subsetSum(arr,n-1,sum,data,index);
  return res1||res2;

}


bool isSubsetSum(int*arr,int n,int sum){
    if(sum==0)return true;
    if(sum!=0&&n==0)return false;


    return isSubsetSum(arr,n-1,sum-arr[n-1])||isSubsetSum(arr,n-1,sum);
}

bool subsetSum(int*arr,int n,int sum){
    static vector<int>data;
    if(!sum){
        for(int i=0;i<data.size();i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        
    return true;
    }
    if(!n)return false;
    data.push_back(arr[n-1]);
    bool res1=subsetSum(arr,n-1,sum-arr[n-1]);
    data.pop_back();
    bool res2=subsetSum(arr,n-1,sum);
    return res1||res2;
}
/****************************************************************************************************************************************/

//There is another approach  of doing this type of questions
//Fix And Recur

bool printSubsets(int*arr,int Start,int End,int*data,int index,int sum){
    if(!sum){
        for(int i=0;i<index;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    if(Start>End)return false;
    bool res=false;
    for(int i=Start;i<=End;i++){        // This is nothing but a DFS~ Depth First Search
        data[index]=arr[i];
        res=res||printSubsets(arr,i+1,End,data,index+1,sum-arr[i]);
    }
    return res;
}
/***************************************************************************************************************************************/
/// condition should be sum is not negative
bool isSubsetDP(int*arr,int n,int sum){
    vector<vector<bool> >dp(sum+1,vector<bool>(n+1,false));
    for(int j=0;j<=n;j++)
        dp[0][j]=true;
    for(int i=1;i<=sum;i++)
        dp[i][0]=false;
    for(int i=1;i<=sum;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=i<arr[j-1]?dp[i][j-1]:dp[i][j-1]||dp[i-arr[j-1]][j-1];
        }
    }
    return dp[sum][n];
}
int main(){
    int arr[100],n,sum,data[100];
    /*
     * int arr[]={1,-2,1,4} ,sum=3;
     * If we use this example than there are 2 subsets exits
     * {4,-2,1} and {4,1,-2} , these are 2 subsets not permutation of each other 
     * subsets are combinations, number of ways  of selecting r objects from n
     * this occurs because there are duplicate elements in the array 
     * {-2,1} and {1,-2}  are 2 different subsets
     */
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter sum:";
    cin>>sum;
    if(subsetSum(arr,n,sum,data,0)){
        cout<<"subset exists "<<endl;
    }
    else{
        cout<<"subset does not exits"<<endl;
    }
    if(isSubsetSum(arr,n,sum)){
        cout<<"subset exists "<<endl;
    }
    else{
        cout<<"subset does not exits"<<endl;
    }
    subsetSum(arr,n,sum);
    cout<<endl<<endl<<endl;
    if(printSubsets(arr,0,n-1,data,0,sum)){
        cout<<"Subset Exits!!"<<endl;
    }else{
        cout<<"Subset does not exits!"<<endl;
    }
    cout<<endl<<endl<<endl;
    if(isSubsetDP(arr,n,sum)){
        cout<<"Subsets exits!"<<endl;
    }else{
        cout<<"subset does not exits"<<endl;
    }
    return 0;
}
