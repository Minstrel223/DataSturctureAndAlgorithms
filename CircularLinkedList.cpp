#include<iostream>
#define OK 0
#define ERROR -1
#define OVERFLOW -2
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status InitList(LinkList &L){
    //初始化为空链表
    L=new LNode;
    L->next=L;
    L->data=0;
    return OK;
}

LinkList CreateList_Head(int n){
    //以头插法建立长度为n的单链表
    LinkList L=new LNode;//头指针
    L->next=L;
    L->data=n;//头结点数据域存放表长
    for(int i=0;i<n;i++){
        LinkList p=new LNode;
        cin>>p->data;
        p->next=L->next;
        L->next=p;//将新结点插入到头结点之后
    }
    return L;
}

LinkList CreateList_Tail(int n){
    //以尾插法建立长度为n的单链表
    LinkList L=new LNode;
    L->data=n;
    L->next=L;
    LinkList q=L;//尾指针
    for(int i=0;i<n;i++){
        LinkList p = new LNode;
        cin>>p->data;
        p->next=L;
        q->next=p;
        q=p;
    }
    return L;
}

void TraverseList(LinkList L){
    //遍历链表
    LinkList p=L;
    while(p->next!=L){
        cout<<p->next->data<<" ";
        p=p->next;
    }
}

ElemType GetElem(LinkList L, int n){
    //获取L的第n个元素
    if(n>(L->data)||n<1) return ERROR;
    for(int i=0;i<n;i++){
        L=L->next;
    }
    return L->data;
}

int LocateElem(LinkList L,ElemType e){
    //查找L中e的位置
    LinkList p=L->next;
    int i;
    for(i=1;(p->data)!=e;i++){
        p=p->next;
        if(p==L) return -1;
    }
    return i;
}

Status ListInsert(LinkList L,int n,ElemType e){
    //将e插入到L的第n个位置
    if(n>(L->data)+1||n<1) return ERROR;
    LinkList p=L;
    for(int i=1;i<n;i++){
        p=p->next;
    }
    LinkList s=new LNode;
    s->next=p->next;
    p->next=s;
    s->data=e;
    L->data++;
    return OK;
}

Status ListDelete(LinkList L,int n){
    //删除L的第n个元素
    LinkList p=L;
    if(n>(L->data)||n<1) return ERROR;
    for(int i=1;i<n;i++){
        p=p->next;
    }
    LinkList q=p->next;
    p->next=q->next;
    delete q;
    L->data-=1;
    return OK;
}

int main(){
    LinkList L=CreateList_Tail(5);
    TraverseList(L);
    cout<<endl<<GetElem(L,4)<<endl;
    ListInsert(L,6,9);
    TraverseList(L);
    cout<<endl;
    ListDelete(L,6);
    TraverseList(L);
    cout<<endl;
    cout<<LocateElem(L,3);

    return 0;
}