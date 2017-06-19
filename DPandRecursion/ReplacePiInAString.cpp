#include<iostream>
using namespace std;

void replacePi(char*dest,char*src){
    if(!src[0]){
        dest[0]=0;
    }
    else if(src[0]=='p'&&src[1]=='i'){
        dest[0]='3';
        dest[1]='.';
        dest[2]='1';
        dest[3]='4';
        replacePi(dest+4,src+2);
    }
    else{
        dest[0]=src[0];
        replacePi(dest+1,src+1);
    }
    return;
}
int main(){
    char str[100],dest[100];
    cout<<"Enter string: ";
    cin.getline(str,100);
    replacePi(dest,str);
    cout<<"Transformed string is: "<<dest<<endl;
    return 0;
}

