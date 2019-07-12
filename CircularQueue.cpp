#include <iostream>
using namespace std;
#define MAXSIZE 4
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
    if(Q.rear==Q.front){
        return true;
    }
    else return false;
}

bool EnQueue(SqQueue &Q,ElemType e){
    if((Q.rear+1)%MAXSIZE==Q.front) return false;//栈满
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &e){
    if(isEmpty(Q)) return false;
    e=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXSIZE;
    return true;
}

int main(){
    SqQueue Q = InitQueue();
    for(int i=0;i<3;i++){
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
}