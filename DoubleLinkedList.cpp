#include<iostream>
using namespace std;
#define ERROR -1
#define OK 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct DuLNode{
    ElemType data;
    struct DuLNode* prior;
    struct DuLNode* next;
}DuLNode,*DuLinkList;

DuLinkList CreateList_Tail(int n){
    //以尾插法建立双向链表
    DuLinkList L = new DuLNode;
    L->data=n;//首元结点保存表长
    L->prior=NULL;
    L->next=NULL;
    DuLinkList p=L;
    for(int i=0;i<n;i++){
        DuLinkList s = new DuLNode;
        cin>>s->data;
        s->next=NULL;
        p->next=s;
        s->prior=p;
        p=s;
    }
    return L;
}

void TraverseList(DuLinkList L){
    //遍历
    while(L->next){
        cout<<L->next->data<<" ";
        L=L->next;
    }
    cout<<endl;
}

ElemType GetElem(DuLinkList L,int n){
    //获取L的第n个元素
    for(int i=0;i<n;i++){
        L=L->next;
    }
    if(L) return L->data;
    return ERROR;
}

int LocateElem(DuLinkList L,ElemType e){
    //查找L中e的位置
    DuLinkList p=L->next;
    int i;
    for(i=1;(p->data)!=e;i++){
        p=p->next;
        if(!p) return -1;
    }
    return i;
}

Status ListInsert(DuLinkList L,int n,ElemType e){
    //在第L的第n个位置插入e(前插)
    DuLinkList p=L; 
    for(int i=1;i<n;i++){
        p=p->next;
        if(!p) return ERROR;
    }
    DuLinkList s = new DuLNode;
    s->data=e;
    s->prior=p;
    s->next=p->next;
    p->next=s;
    L->data++;
    return OK;

}

Status ListDelete(DuLinkList L,int n){
    //删除L的第n个元素
    DuLinkList p=L;
    for(int i=0;i<n;i++){
        p=p->next;
        if(!p) return ERROR;
    }
    p->prior->next=p->next;
    if(p->next) p->next->prior=p->prior;
    delete (p);
    L->data--;
    return OK;
}

int main(){
    DuLinkList L = CreateList_Tail(5);
    TraverseList(L);
    cout<<GetElem(L,3)<<endl;
    ListInsert(L,6,6);
    TraverseList(L);
    ListDelete(L,6);
    TraverseList(L);
    cout<<L->data;
}