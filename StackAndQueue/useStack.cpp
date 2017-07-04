//#include"StackLL.h"
//#include"DynamicStack.h"
//#include"MiddleElementStack.h"
#include"MinElementStack.h"
int main(){

try{
    SpecialStack<int>S;
    S.Push(18);
    S.Push(19);
    S.Push(29);
    S.Push(15);
    S.Push(16);
    
    while(!S.isEmpty()){
       cout<<S.Top()<<" "<<S.getMinimum()<<endl;
        S.Pop();
   }
    

/**
    DynamicStack<int>S;
for(int i=0;i<10;i++){
    S.Push(i);
}

DynamicStack<int>S2=S;
while(!S2.isEmpty()){
    cout<<S2.Top()<<endl;
    S2.Pop();
}
cout<<S2.Size()<<endl;
cout<<S.Size()<<endl;
S.Top()=67;
while(!S.isEmpty()){
    cout<<S.Top()<<endl;
    S.Pop();
}
**/
}catch(const char*error){
    cerr<<error<<endl;
}
return 0;
}
