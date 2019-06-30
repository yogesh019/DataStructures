#include<iostream>
#include<limits>
#include<cstring>
using namespace std;

bool isPalindrome(const char *str,int Start,int End){
	int i=Start,j=End;
	for(;i<j&&str[i]==str[j];i++,j--);
	return i>=j?true:false;
}

int getMinCut(const char*str,int Start,int End){
	if(Start>=End||isPalindrome(str,Start,End))
		return 0;
	int Min=numeric_limits<int>::max();
	for(int i=Start;i<End;i++){
		int value=1+getMinCut(str,Start,i)+getMinCut(str,i+1,End);
		Min=min(Min,value);
	}
	return Min;
}
int main(){
	char str[100];
	cout<<"Enter string: ";
	cin.getline(str,100);
	cout<<getMinCut(str,0,strlen(str)-1)<<endl;
	return 0;
}

