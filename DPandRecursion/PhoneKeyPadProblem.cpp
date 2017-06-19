#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
Q. Using the phone keypad return all possible words that can be produced
given input digits. e.g. 23 > “ad, ae, af, bd, be, bf, cd, ce, cf”
*/
/*
map<char,vector<char> >LetterCombination(){
    map<char,vector<char> >M;
    int n=2;
    vector<char>v;
    for(char i='a';i<='z';i++){
        v.push_back(i);
        if(i=='c'||i=='f'||i=='i'||i=='l'||i=='o'||i=='s'||i=='v'||i=='z'){
            M[n+'0']=v;
            n++;
            v.clear();
        }
        
    }
    return M;
}
void dfs(char*digits,char*res,int  index){
    static map<char,vector<char> >M=LetterCombination();
    if(!digits[0]){
        res[index]=0;
        cout<<res<<endl;
        return;
    }
    vector<char>v=M[digits[0]];
    for(int  i=0;i<v.size();i++){
        res[index]=v[i];
        dfs(digits+1,res,index+1);
    }
    return;
}
*/
    /// A simple DFS Problem
class Solution {
public:
    void dfs(string digits, string r, map<char,vector<char> > &mp, vector<string> &res){
        if (digits.empty()){
            res.push_back(r);
        }else{
            vector<char> vec = mp[digits[0]];
            for(int i=0;i<vec.size();i++){
                dfs(digits.substr(1),r+vec[i],mp,res);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char> > mp;
        vector<char> v;
        int n=2;
        for (char i='a';i<='z';i++){
            v.push_back(i);
            if (i=='c' || i=='f'|| i=='i'|| i=='l'|| i=='o'|| i=='s'|| i=='v'|| i=='z'){
                mp[char(n+'0')]=v;
                n++;
                v.clear();
            }
        }

        vector<string> res;
        dfs(digits,"",mp,res);
        return res;
    }
};




int main(){
    char digits[100],res[100];
    cout<<"Enter the number: ";
    cin.getline(digits,100);
    cout<<"strings formed are:  "<<endl;
    //dfs(digits,res,0);
    Solution S;
    vector<string>result=S.letterCombinations(digits);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}
