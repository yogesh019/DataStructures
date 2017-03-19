#include<iostream>
#include<map>
#include<string>
#include"set.h"
using namespace std;

int main(){
    Set<int>s;
    for(int i=10;i>=0;i--){
       s.Insert(i);
   }
   for(Set<int>::Iterator it=s.Begin();it!=s.End();it++){
       cout<<(*it)<<" ";
   }
   return 0;
}
