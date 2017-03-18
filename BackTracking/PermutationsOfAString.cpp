#include<iostream>
#include<cstring>
using namespace std;

void Swap(char*src,char*dest){
    char temp=*src;
    *src=*dest;
    *dest=temp;
    return;
}
void permute(char*str,int low,int high){
    if(low==high){
        cout<<str<<endl;
        return;
    }
    for(int i=low;i<=high;i++){
        Swap(str+low,str+i);
        permute(str,low+1,high);
        Swap(str+low,str+i);
    }
    return;
}
//Permutations of a string with all distinct letters
//Time complexity is 0(n*n!) Total permutations are n!
//and time taken to print one permutation is O(n)

int main(){
    char  str[]="ABC";
    cout<<"Permutations of a string are: "<<endl;
    permute(str,0,strlen(str)-1);
    return 0;
}

