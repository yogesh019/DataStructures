#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
/****************************************************************************************************************************************/
// select and not-select approach
// Pascal's identity=nCr=n-1Cr-1 + n-1Cr
// the no. of ways of selecting r objects from n is equal to the number of ways of selecting r-1 objects from n-1(i.e include current)
// plus no. of ways of selecting r objects from n-1 (i.e exclude current)
void printSubsets(char*str,char*subsets,int index){
    if(!*str){
        subsets[index]='\0';
        cout<<"{"<<subsets<<"}"<<endl;
        return;
    }
    printSubsets(str+1,subsets,index);
    subsets[index]=*str;
    printSubsets(str+1,subsets,index+1);
    return;
}

void printSubsets(char*str){
    static vector<char>subsets;
    if(!str[0]){
        cout<<"{";
        for(vector<char>::iterator it=subsets.begin();it!=subsets.end();it++){
            cout<<*it<<" ";
        }
        cout<<"}"<<endl;
        return;
    }
    printSubsets(str+1);
    subsets.push_back(*str);
    printSubsets(str+1);
    subsets.pop_back();
    return;
}
/*****************************************************************************************************************************************/
//Fix and recur-approach
void printSubsets(char*str,int Start,int End,char*subsets,int index){
    if(Start>End)return;
    subsets[index]='\0';
    cout<<"{"<<subsets<<"}"<<endl;
    for(int i=Start;i<=End;i++){     // DFS ~ Depth First Search
        subsets[index]=str[i];
        printSubsets(str,i+1,End,subsets,index+1);
       /*
        * For handling duplicates , but the string must be sorted
        while(str[i]==str[i+1])
            i++;
       */
    }
    return;
}
/****************************************************************************************************************************************/
// Finding Subsets Or Subsequences by filling a 2-D char array
void stringCopyAndPrePendCharacter(char*src,char*dest,char ch){
    dest[0]=ch;
    int i=0;
    while(src[i]){
        dest[i+1]=src[i];
        i++;
    }
    dest[i+1]='\0';
    return;
}
int returnAllSubsets(char*str,int index,char subset[][100]){
    if(str[index]=='\0'){
        subset[0][0]='\0';
        return 1;
    }                                     // Recursion is going Linearly , not in a form of tree , time complexity may be O(n^2)
    int Count=returnAllSubsets(str,index+1,subset);
    for(int i=Count;i<2*Count;i++){
        stringCopyAndPrePendCharacter(subset[i-Count],subset[i],str[index]);
    }
    return 2*Count;
}
/****************************************************************************************************************************************/

void  printSubsetsIteratively(char*str){
    int subsets=pow(2,strlen(str));
    for(int Count=0;Count<subsets;Count++){
        for(int j=0;j<strlen(str);j++){                         //Time Complexity is O(n2^n)
            if(Count&1<<j)
                cout<<str[j]<<" ";
        }
        cout<<endl;
    }
return;
}
/***************************************************************************************************************************************/
int main(){
    char str[100],subsets[100],subset[100][100];
    cout<<"Enter the string: ";
    cin.getline(str,100);
    cout<<"Subsets are: "<<endl;
    printSubsets(str,subsets,0);
    cout<<endl<<endl;
    printSubsets(str,0,strlen(str),subsets,0);
    cout<<endl<<endl;
    printSubsets(str);
    cout<<endl<<endl;
    int Count=returnAllSubsets(str,0,subset);
    for(int i=0;i<Count;i++){
        cout<<"{"<<subset[i]<<"}"<<endl;
    }   
    cout<<endl<<endl;
    printSubsetsIteratively(str);
    return 0;
}
    
