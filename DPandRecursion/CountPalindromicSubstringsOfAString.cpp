#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isPalindrome(char*str,int Start,int End){
    int i=Start,j=End;
    for(;i<=j&&str[i]==str[j];i++,j--);
   return i<j?false:true;
}

int CountPS(char*str,int Start,int End){
    if(Start==End)return 1;

    if(Start+1==End)
        return str[Start]==str[End];
    else if(isPalindrome(str,Start,End))
        return 1+CountPS(str,Start+1,End)+CountPS(str,Start,End-1)-CountPS(str,Start+1,End-1);
    else
        return CountPS(str,Start+1,End)+CountPS(str,Start,End-1)-CountPS(str,Start+1,End-1);
}

int main(){
    char str[100];
    cout<<"enter string: ";
    cin.getline(str,100);
    cout<<"No. of Palindromic Substrings of this string are: "<<CountPS(str,0,strlen(str)-1)<<endl;

    return 0;
}
