#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<unordered_map>
#include<limits>
using namespace std;

vector<vector<bool>>dp(100,vector<bool>(100,false));
int findSubstrings(char*str){
	int n=strlen(str);
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j--){
			if(i==j){
				dp[i][j]=true;
				count++;
			}
			else if(str[i]==str[j]){
				dp[j][i]=((i-j==1)?true:dp[j+1][i-1]);
				count=dp[j][i]?++count:count;
			}else{
				dp[j][i]=false;
			}
		}
	}
	return count;
}

int minCut(char*str,int Start,int End){
	static unordered_map<string,int>M;
	if(Start==End||dp[Start][End]==true)
		return 0;
	string s=to_string(Start)+"|"+to_string(End);
	if(M.find(s)==M.end()){
		M[s]=numeric_limits<int>::max();
		for(int i=Start;i<End;i++){
			int value=1+minCut(str,Start,i)+minCut(str,i+1,End);
			M[s]=min(M[s],value);
		}
	}
	return M[s];
}

	
int main(){
	char str[]="bababcbadcd";
	findSubstrings(str);
	cout<<minCut(str,0,strlen(str)-1)<<endl;
	return 0;
}

