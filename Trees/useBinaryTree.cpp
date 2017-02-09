#include<iostream>
using namespace std;

class something{

public:
    static  int x;
    something(){
        cout<<"constructor"<<endl;
    }

    void show(){
        x=34;
        cout<<"hello"<<endl;
        cout<<"x="<<x<<endl;
    }

    ~something(){
        cout<<"destructor"<<endl;
    }

    static void print(){
        cout<<"print"<<endl;
    }

};
int something::x=89;

int main(){
    cout<<sizeof(something)<<endl;
    //something s;
    //s.print();
    something *s=0;
    s->show();
    cout<<sizeof(*s)<<endl;
    return 0;
}

