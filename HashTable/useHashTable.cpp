#include<iostream>
#include"hashtable.h"
//#include<tr1/unordered_set>
//using namespace std::tr1;
using namespace std;
int main(){
cout<<"yogesh";
    HashTable<int>s;
//cout<<s.size()<<endl;
cout<<s.Insert(78)<<endl;
cout<<s.Insert(78)<<endl;
cout<<s.Remove(78)<<endl;
cout<<s.contains(78)<<endl;
//for(int i=0;i<10;i++){
  //  s.Insert(i);
//}
/**
for(unordered_set<int>::iterator it=s.begin();it!=s.end();it++){
    cout<<*it<<" ";
}
**/
cout<<endl;
return 0;
}

