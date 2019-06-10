#include <iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 100
using namespace std;
typedef int ElemType;
typedef int Status;
typedef struct SqStack{
    ElemType data[MAXSIZE];
    int top;//栈顶指针
}SqStack;

Status InitStack(SqStack &S){
    //初始化一个空栈S
    S.top=-1; //初始化栈顶指针
    return OK;
}

Status Push(SqStack &S, ElemType e){
    //插入元素e为新的栈顶元素
    if(S.top==MAXSIZE-1) return ERROR;//栈满
    S.top++;
    S.data[S.top]=e;
    return OK;
}

Status Pop(SqStack &S, ElemType &e){
    //删除栈顶元素，用e返回其值
    if(S.top==-1) return ERROR;
    e=S.data[S.top];
    S.top--;
    return OK;
}

Status GetTop(SqStack S, ElemType &e){
    //返回S的栈顶元素，不修改栈顶指针
    if(S.top!=-1){
        e=S.data[S.top];
        return OK;
    }
    else return ERROR;
}

bool StackEmpty(SqStack S){
    //判断栈是否为空
    if(S.top==-1) return true;
    else return false;
}

int main(){
    SqStack S;
    ElemType e;
    InitStack(S);
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