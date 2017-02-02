#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include"MyString.h"
#include"MyVector.h"
#include"MyComplex.h"
#include<complex>
#include<set>
using namespace std;



int main(){
    set<int>s;
    for(int i=10;i>0;i--){
        s.insert(i);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout<<(*it)<<" ";
    }

   // MyComplex<int>C(2,3);
   // MyComplex<int>C1(3,4);
    //cin>>C;
    //cout<<C;

//vector<const int>v;
//cout<<something::x;

/**
MyVector<int>v;
cout<<v.Size()<<" "<<v.Capacity()<<endl;
for(int i=0;i<10;i++){
    v.Push_Back(i);
    cout<<v.Size()<<" "<<v.Capacity()<<endl;
}
//cout<<sizeof(v);
for(MyVector<int>::Iterator it=v.Begin();it!=v.End();it++){
    cout<<(*it)<<" ";
}
cout<<endl;
//v.shrink_to_fit();
cout<<v.Size()<<" "<<v.Capacity()<<endl;
for(MyVector<int>::Const_Iterator it=v.Begin();it!=v.End();it++){
    cout<<(*it)<<" ";
}
cout<<endl;
int arr[]={786,456,345,23};
v.Insert(4,arr,4);
//v.Erase(0,0);
cout<<endl<<v.Size()<<" "<<v.Capacity()<<endl;
cout<<endl;
for(MyVector<int>::Const_Iterator it=v.Begin();it!=v.End();it++){
    cout<<(*it)<<" ";
}
//v.Clear();
//cout<<v.Size()<<" "<<v.Capacity()<<endl;
//cout<<v.isEmpty()<<endl;


/**
int *arr=0;
cout<<arr[0];
    vector<int>v(10);
v.resize(0);
    cout<<v.empty()<<endl;
    cout<<v.size()<<" "<<v.capacity();

**/

//    MyString s;

//s[0]='B';
//s[1]='k';
//cout<<s[1];
//cout<<s;
//="uoh";
//cout<<endl<<s<<endl<<s[1];
//cout<<<<endl;
//str2[0]='p';
//cout<<str2;



 //char *p;
 //cout<<(*p)<<endl;
 //string s;
 //getline(cin,s,'$');
 //cout<<s<<endl;
 //cin>>s;
//cout<<s<<endl;
// cout<<s.length()<<" "<<s.capacity()<<endl;
//cin>>s;
//cout<<s<<endl;//
//cout<<s.length()<<" "<<s.capacity()<<endl;
// cout<<s[0]<<endl;
 //cout<<s.length()<<" "<<s.capacity()<<endl;

//cout<<s;
    /**
//cout<<char(255)<<endl;
    char str[]={'h','e','l','l','o',' ','w','o','r','l','d'};
    cin.getline(str,6,'$');
    cout<<str<<endl;
    cin.clear();
    cin.getline(str,6);
    cout<<str<<endl;
    //char ch=cin.get();
    //cout<<ch<<" "<<int(ch)<<endl;
**/
    return 0;
}















/**
int main(){

int num='ABCD';
char*ptr=(char*)&num;
cout<<ptr<<endl;
ptr++;
cout<<(void*)ptr<<endl;
unsigned int x=4294967298;
cout<<x<<endl;
unsigned int a=3;
cout<<(a<-4)<<endl;
int y=-1;
return 0;

}
**/
/**
int main(){

    int num=328;
    char ch=num;
    char *x=(char*)(&num);

  cout<<(char*)(x+1)<<endl;
    cout<<&num<<endl;
    cout<<num<<endl;
    cout<<ch<<endl;

    cout<<&ch<<endl;


    cout<<(char*)&num<<endl;
    char *ptr=(char*)&num;
    *(ptr+1)='A';
    cout<<ptr<<endl;
    cout<<(char*)&num<<endl;
    cout<<&ch<<endl;
    cout<<(int*)(ptr+1)<<endl;
    cout<<(void*)&ch<<endl;
    cout<<sizeof(double **)<<endl;
    return 0;
}
**/























/**
#include<iostream>
#include<typeinfo>

using namespace std;

void func( int (&arr)[2]){

cout<<arr<<endl;
cout<<&arr[0]<<endl;
cout<<arr[1]<<endl;
cout<<&arr<<endl;
return;
}

int main(){
cout<<func<<endl;
int arr[]={1,2,3,4,5};
cout<<arr<<endl;
cout<<&arr<<endl;
cout<<&arr[0]<<endl;
int *p=arr+3;
//func(*p);
//cout<<typeof(arr);
return 0;

}

**/
