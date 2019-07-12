#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;
typedef struct SqQueue{
    ElemType data[MAXSIZE];
    int front,rear;
}SqQueue;

SqQueue InitQueue(){
    SqQueue Q;
    Q.front=0;
    Q.rear=0;
    return Q;
}

bool isEmpty(SqQueue Q){
    if(Q.front==Q.rear){
        return true;
    }
    else return false;
}

bool EnQueue(SqQueue &Q,ElemType e){
    if(Q.rear>=MAXSIZE) return false;
    Q.data[Q.rear]=e;
    Q.rear++;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &e){
    if(isEmpty(Q)) return false;
    e=Q.data[Q.front];
    Q.front++;
    return true;
}

int main(){
    SqQueue Q = InitQueue();
    EnQueue(Q,0);
    EnQueue(Q,1);
    EnQueue(Q,2);
    ElemType e;
    DeQueue(Q,e);
    cout<<e;
    DeQueue(Q,e);
    cout<<e;
    DeQueue(Q,e);
    cout<<e;
}