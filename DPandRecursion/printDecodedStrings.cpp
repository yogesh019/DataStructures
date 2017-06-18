#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
Lets assume A is 1, B is 2…and Z is 26. Given a number N, print all possible strings based on above. 
E.g: 123 -> ABC, LC, AW
*/

int PrintAndCountDecodings(char*digits,int index,char*decodings,int index2){
    if(index>strlen(digits))
        return 0;
    if(digits[index]=='\0'){
        decodings[index2]='\0';
        cout<<decodings<<endl;
        return 1;
    }
    int Count=0;
    if(digits[index]=='0'){
        Count+=PrintAndCountDecodings(digits,index+1,decodings,index2);
    }
    else if(digits[index]>'0'){
        decodings[index2]=digits[index]+16;
        Count+=PrintAndCountDecodings(digits,index+1,decodings,index2+1);
    }
    if(digits[index]=='1'||digits[index]=='2'&&digits[index+1]<'7'){
        decodings[index2]=digits[index]=='2'?digits[index+1]+36:digits[index+1]+26;
        Count+=PrintAndCountDecodings(digits,index+2,decodings,index2+1);
    }
    return Count;
}

int countDecodingsDP(char*digits){
    vector<int>dp(strlen(digits)+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=strlen(digits);i++){ //lengths
        dp[i]=0;
        
        if(digits[i-1]>='0')
            dp[i]+=dp[i-1];
        if(digits[i-2]=='1'||digits[i-2]=='2'&&digits[i-1]<'7')
            dp[i]+=dp[i-2];
    }
    return dp[strlen(digits)];
}
int main(){
    char digits[100],decodings[100];
    cout<<"Enter the number: ";
    cin.getline(digits,100);
    cout<<"No of Decodings are: "<<PrintAndCountDecodings(digits,0,decodings,0)<<endl;
    cout<<endl<<endl;
    cout<<countDecodingsDP(digits)<<endl;
    return 0;
}
    
