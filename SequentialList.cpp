#include <stdio.h>
#include <iostream>
#define InitSize 50
#define MaxSize 100
#define OVERFLOW -2
using namespace std;
typedef int ElemType;
typedef struct{
    ElemType *data;
    int length;
}SqList;

bool InitList(SqList &L){
    //初始化
    L.data=new ElemType[InitSize];//初始动态分配内存
    if(!L.data) exit(OVERFLOW);//分配失败
    L.length=0;
    return true;
}

bool ListInsert(SqList &L, int i, ElemType e){
    //在将e插入到L中的第i个位置
    if(i<1||i>L.length+1) return false;
    if(L.length>=MaxSize) return false;
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i){
    //删除第i个位置上的元素
    if(i<1||i>L.length) return false;
    for(int j=i-1;j<L.length-1;j++){
        L.data[j]=L.data[j+1];
    }
    L.length--;
    return true;
}

ElemType GetElem(SqList &L, int i){
    //获取第i个元素
    if(i<1||i>L.length) return NULL;
    return L.data[i-1];
}

int LocateElem(SqList &L, ElemType e){
    //查找元素e的位置
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e) return i+1;
    }
    return 0;//查找失败
}

int main(){
    //测试
    SqList L;
    InitList(L);
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,3);
    ListInsert(L,4,4);
    ListInsert(L,2,2);
    ListDelete(L,2);
    for(int i=1;i<=L.length;i++){
        ElemType e=GetElem(L,i);
        cout<<e;
    }

}