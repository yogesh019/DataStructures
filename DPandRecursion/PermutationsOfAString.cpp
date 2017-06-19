#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;

void Swap(char*src,char*dest){
    char temp=*src;
    *src=*dest;
    *dest=temp;
    return;
}

void printPermutations(char*str,int Start,int End){
    
    if(Start>End)return;
    if(Start==End){
        cout<<str<<endl;
    }
    unordered_set<char>check; // this should not be static
    for(int i=Start;i<=End;i++){
        if(check.find(str[i])==check.end()){
            check.insert(str[i]);
            Swap(str+i,str+Start);
            printPermutations(str,Start+1,End);
            Swap(str+i,str+Start);
        }
    }
    return;
}

///Permutations of a string with all distinct letters
///Time complexity is 0(n*n!) Total permutations are n!
///and time taken to print one permutation is O(n)

/**if the string contains duplicates than this can be handeled by using
 * 1.using set of strings to store alldistinct permutations
 * 2.By not swapping for repeated characters more than once
 **/
int main(){
    char str[100];
    cout<<"Enter the string: ";
    cin.getline(str,100);
    cout<<"Permutations are: "<<endl;
    printPermutations(str,0,strlen(str)-1);
    
}

