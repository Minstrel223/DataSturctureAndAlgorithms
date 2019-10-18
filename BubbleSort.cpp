#include <stdio.h>
void BubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j+1];
                a[j+1]=a[j];
                a[j]=t;
            }
        }
    }
}
int main(){
    int a[8]={3,1,4,1,5,9,2,7};
    BubbleSort(a,8);
    for(int k=0;k<8;k++){
        printf("%d",a[k]);
    }
}