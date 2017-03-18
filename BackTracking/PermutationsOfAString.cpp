#include<iostream>
#include<cstring>
#include<set>
#include<string>
using namespace std;

set<string>distinct;

void Swap(char*src,char*dest){
    char temp=*src;
    *src=*dest;
    *dest=temp;
    return;
}
void permute(char*str,int low,int high){
    if(low==high){
        cout<<str<<endl;
        //distinct.insert(str);
        return;
    }
    bool visited[256]={false};
    for(int i=low;i<=high;i++){
        if(!visited[str[i]]){
            visited[str[i]]=true;
            Swap(str+low,str+i);  
            permute(str,low+1,high);
            Swap(str+low,str+i);
        }
    }
    return;
}
//Permutations of a string with all distinct letters
//Time complexity is 0(n*n!) Total permutations are n!
//and time taken to print one permutation is O(n)

/*if the string contains duplicates than this can be handeled by using
 * 1.using set of strings to store alldistinct permutations
 * 2.By not swapping for repeated characters more than once
 */ 
int main(){
    char  str[]="AAB";
    cout<<"Permutations of a string are: "<<endl;
    permute(str,0,strlen(str)-1);
    //for(set<string>::const_iterator it=distinct.begin();it!=distinct.end();it++){
        //cout<<*it<<endl;
   // }
    return 0;
}

