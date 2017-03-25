#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

bool CheckCount(const string&s,int N){
    unordered_set<char>check;
    int i=0;
    while(s[i]){
        check.insert(s[i]);
        i++;
    }
    return check.size()<=N;
}
int main(){
    string s;
    int N;
    cout<<"Enter string: ";
    getline(cin,s);
    cout<<"Enter N: ";
    cin>>N;
    if(CheckCount(s,N)){
        cout<<"string contains at most "<<N<<"different characters"<<endl;
    }
    else{
        cout<<"string contains more no. of characters than required";
    }
    return 0;
}



