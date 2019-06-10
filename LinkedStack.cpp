#include<iostream>
#define OK 0
#define ERROR -1
#define OVERFLOW -2
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct LSNode{
    ElemType data;
    struct LSNode *next;
}LSNode,*LStack;

LStack InitStack(){
    LStack S = new LSNode;
    S->next==NULL;
    return S;
}

Status Push(LStack &S, ElemType e){
    LStack x = new LSNode;
    //if(!x) exit(OVERFLOW);
    x->data=e;
    x->next=S;
    S=x;
    return OK;
}

Status Pop(LStack &S, ElemType &e){
    if(S->next==NULL) return ERROR;
    LStack temp = S;
    S=S->next;
    e=temp->data;
    delete temp;
    return OK;
}

Status GetTop(LStack S, ElemType &e){
    if(S->next==NULL) return ERROR;
    e=S->data;
    return OK;
}

bool StackEmpty(LStack S){
    if(S->next==NULL) return true;
    else return false;
}

int main(){
    ElemType e;
    LStack S = InitStack();
    for(int i=0;i<50;i++){
        Push(S,i);
    }
    GetTop(S,e);
    cout<<e<<endl;
    Pop(S,e);
    cout<<e<<endl;
    GetTop(S,e);
    cout<<e<<endl;
}
