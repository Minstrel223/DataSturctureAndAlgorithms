#include <stdio.h>
void InsertSort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            for(j=0;a[i]>a[j];j++);
            int t=a[i];
            for(int m=i-1;m>=j;m--) a[m+1]=a[m];
            a[j]=t;
            for(int k=0;k<n;k++){
                printf("%d",a[k]);
            }
            printf("\n");
        }
    }
}
int main(){
    int a[8]={2,1,2,3,5,6,8,6};
    InsertSort(a,8);
}