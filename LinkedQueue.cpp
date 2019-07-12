#include <iostream>
using namespace std;
typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue{
    LinkNode *front;
    LinkNode *rear;
}LinkQueue;

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=new LinkNode;//建立头结点
    Q.front->next=NULL;
}

bool isEmpty(LinkQueue Q){
    if(Q.front==Q.rear) return true;
    else return false;
}

void EnQueue(LinkQueue &Q,ElemType e){
    LinkNode *n = new LinkNode;
    n->data=e;
    n->next=NULL;
    Q.rear->next=n;
    Q.rear=n;
}

bool DeQueue(LinkQueue &Q,ElemType &e){
    if(isEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p){//若删除前队列中除头结点外只有一个节点
        Q.rear=Q.front;//删除后尾指针指向头结点，即队列为空
    }
    delete(p);
    return true;
}

int main(){
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q,1);
    EnQueue(Q,2);
    EnQueue(Q,3);
    ElemType e;
    DeQueue(Q,e);
    cout<<e;
    DeQueue(Q,e);
    cout<<e;
    DeQueue(Q,e);
    cout<<e;
}