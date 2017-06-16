#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<string>
using namespace std;

vector<vector<int> >dp(100,vector<int>(100,-1));
/*
LCS Problem Statement: 

Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the
same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are 
subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences.
*/

// Recursive Solutions : Time Complexity is Exponential
int LCS(char*str1,char*str2){
    if(!*str1||!*str2)return 0;
    
    return *str1==*str2?1+LCS(str1+1,str2+1):max(LCS(str1+1,str2),LCS(str1,str2+1));
}

int LCS(char*str1,char*str2,int len1,int len2){
    if(!len1||!len2)return 0;
    return str1[len1-1]==str2[len2-1]?1+LCS(str1,str2,len1-1,len2-1):max(LCS(str1,str2,len1-1,len2),LCS(str1,str2,len1,len2-1));
}
// only 2 parameters changes therefor time complelxity should be O(len1*len2) 
// Dynamic Programming Solutions
// Memoization
int lcs_length1(char*str1,char*str2,int i,int j){
    static vector<vector<int> >dp(strlen(str1)+1,vector<int>(strlen(str2)+1,-1));
    
    if(dp[i][j]<0){
        if(!str1[i]||!str2[j])
            dp[i][j]=0;
        else if(str1[i]==str2[j]){
            dp[i][j]=1+lcs_length1(str1,str2,i+1,j+1);
        }
        else
            dp[i][j]=max(lcs_length1(str1,str2,i+1,j),lcs_length1(str1,str2,i,j+1));
    }
    return dp[i][j];
}
int lcs_length2(char*str1,char*str2,int len1,int len2){
    static vector<vector<int> >dp(strlen(str1)+1,vector<int>(strlen(str2)+1,-1));
    if(dp[len1][len2]<0){
        if(!len1||!len2)
            dp[len1][len2]=0;
        else if(str1[len1-1]==str2[len2-1])
                dp[len1][len2]=1+lcs_length2(str1,str2,len1-1,len2-1);
        else
            dp[len1][len2]=max(lcs_length2(str1,str2,len1-1,len2),lcs_length2(str1,str2,len1,len2-1));
    }
    return dp[len1][len2];
}

// Tabulation: Table Filling from Bottom to Up
// filling the upper L with zeroes -----
//                                 |
int lcs_iterative1(char*str1,char*str2){
    for(int i=0;i<=strlen(str1);i++)
        dp[i][0]=0;
    for(int j=0;j<=strlen(str2);j++)
        dp[0][j]=0;
    for(int i=1;i<=strlen(str1);i++){
        for(int j=1;j<=strlen(str2);j++){
            dp[i][j]=str1[i-1]==str2[j-1]?1+dp[i-1][j-1]:max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[strlen(str1)][strlen(str2)];
}

// filling the lower L with zeroes
int lcs_iterative2(char*str1,char*str2){
    vector<vector<int> >dp(strlen(str1)+1,vector<int>(strlen(str2)+1,-1));
    for(int i=strlen(str1);i>=0;i--){
        for(int j=strlen(str2);j>=0;j--){
            if(!str1[i]||!str2[j])
                dp[i][j]=0;
            else if(str1[i]==str2[j])
                dp[i][j]=1+dp[i+1][j+1];
            else
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}

//Printing the LCS , there could be more than 1 LCS
set<string>getLCS(string s1,string s2,int len1,int len2){
   set<string>s;
    if(!len1||!len2){
      
        s.insert("");
        return s;
    }
    if(s1[len1-1]==s2[len2-1]){
        set<string>temp=getLCS(s1,s2,len1-1,len2-1);
        for(set<string>::iterator it=temp.begin();it!=temp.end();it++){
           s.insert((*it)+s1[len1-1]);  
        }
        return s;
    }
    if(dp[len1-1][len2]>dp[len1][len2-1]){
        return getLCS(s1,s2,len1-1,len2);
    }
    else if(dp[len1-1][len2]==dp[len1][len2-1]){
        s=getLCS(s1,s2,len1-1,len2);
        set<string>temp=getLCS(s1,s2,len1,len2-1);
        s.insert(temp.begin(),temp.end());
        return s;
    }
    else
        return getLCS(s1,s2,len1,len2-1);
}

int main(){
    char str1[100],str2[100];
    cout<<"Enter string1: ";
    cin.getline(str1,100);
    cout<<"Enter string2: ";
    cin.getline(str2,100);
    cout<<"LCS length: "<<endl;
    cout<<LCS(str1,str2)<<endl;
    cout<<LCS(str1,str2,strlen(str1),strlen(str2))<<endl;
    cout<<lcs_length1(str1,str2,0,0)<<endl;
    cout<<lcs_length2(str1,str2,strlen(str1),strlen(str2))<<endl;
    cout<<lcs_iterative1(str1,str2)<<endl;
    cout<<lcs_iterative2(str1,str2)<<endl;
    cout<<"LCS: "<<endl;
    set<string>s=getLCS(str1,str2,strlen(str1),strlen(str2));
    for(set<string>::iterator it=s.begin();it!=s.end();it++){
        cout<<*it<<endl;
    }

    return 0;
}


