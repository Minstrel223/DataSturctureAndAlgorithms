#include <stdio.h>
void InsertSort(int a[],int n){
    int i,j;
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            int low=0,high=i-2;
            while(low<=high){
                int mid=(low+high)/2;
                if(a[i]<a[mid]) high=mid-1;
                else low=mid+1;
            }
            j=low;
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
    int a[8]={4,1,2,5,3,6,8,6};
    InsertSort(a,8);
}