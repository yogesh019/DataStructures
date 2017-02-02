#include"QueueLL.h"
#include"CircularQueue.h"
#include"StackUsing2Queues.h"
#include"StackUsingQueue.h"
#include"QueueUsing2Stacks.h"
int main(){
    /**
    QueueUsingStacks<int>Q;
    cout<<Q.isEmpty()<<endl;
    for(int i=0;i<10;i++){
        Q.Enqueue(i);
    }
    QueueUsingStacks<int>Q1(Q);
    Q.Front()=98;
    while(!Q.isEmpty()){
        cout<<Q.Front()<<" ";
        Q.Dequeue();
    }
    cout<<endl;
    while(!Q1.isEmpty()){
        cout<<Q1.Front()<<" ";
        Q1.Dequeue();
    }**/

    StackUsingQueue<int>S;
    for(int i=0;i<10;i++){
        S.Push(i);
    }
    S.Top()=89;
    StackUsingQueue<int>S1(S);
    while(!S.isEmpty()){
        cout<<S.Top()<<endl;
        S.Pop();

    }
    while(!S1.isEmpty()){
        cout<<S1.Top()<<endl;
        S1.Pop();

    }


    /**
    CircularQueue<int>Q;
    for(int i=0;i<10;i++){
        Q.Enqueue(i);
    }
        CircularQueue<int>Q1(Q);
    while(!Q.isEmpty()){
        cout<<Q.Front()<<" ";
        Q.Dequeue();
    }

    cout<<Q1.Size()<<endl;
        while(!Q1.isEmpty()){
        cout<<Q1.Front()<<" ";
        Q1.Dequeue();
    }
    **/

/**
    QueueLL<int>Q;
    QueueLL<int>Q1(Q);
    for(int i=0;i<10;i++){
        Q.Enqueue(i);
    }
    Q.Front()=54;
    while(!Q.isEmpty()){
        cout<<Q.Front()<<" ";
        Q.Dequeue();
    }
        while(!Q1.isEmpty()){
        cout<<Q1.Front()<<" ";
        Q1.Dequeue();
    }

**/

    return 0;
}
