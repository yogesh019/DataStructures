#include<iostream>
//#include"hashtable.h"
#include"myunordered_map.h"
//#include<tr1/unordered_set>
//using namespace std::tr1;
using namespace std;

int main(){

cout<<"yogesh"<<endl;
MyUnorderedMap<string,int>m;

cout<<m["yogesh"]<<endl;
m["yogesh"]=78;
cout<<m["yogesh"];
cout<<endl;
m.Insert(pair<string,int>("vakul",789));
cout<<m["vakul"]<<endl;
//cout<<m.contains("yogesh")<<endl
//cout<<m.contains("yogesh")<<endl;
/**
//HashTable<int>s;
//cout<<s.size()<<endl;
cout<<s.Insert(78)<<endl;
cout<<s.Insert(78)<<endl;
cout<<s.Remove(78)<<endl;
cout<<s.contains(78)<<endl;
//for(int i=0;i<10;i++){
  //  s.Insert(i);
//}
*/
/**
for(unordered_set<int>::iterator it=s.begin();it!=s.end();it++){
    cout<<*it<<" ";
}
**/
cout<<endl;
return 0;
}

