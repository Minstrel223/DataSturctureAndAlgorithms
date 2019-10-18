#include <stdio.h>
void ShellSort(int A[],int n){
    int i,j,k,t,dk;
    for(dk=n/2;dk>=1;dk=dk/2){
        for(i=dk;i<=n;++i){
            if(A[i]<A[i-dk]){
                t=A[i];
                for(j=i-dk;j>=0&&t<A[j];j-=dk){
                    A[j+dk]=A[j];
                }
                A[j+dk]=t;
            }
        }
    }
}
int main(){
    int a[8]={3,1,4,1,5,9,2,7};
    ShellSort(a,8);
    for(int k=0;k<8;k++){
        printf("%d",a[k]);
    }
}