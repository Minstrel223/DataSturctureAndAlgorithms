#include <stdio.h>
int BinarySearch(int a[],int l,int n){
    int low=0,high=l-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(n==a[mid]) return mid;//查找成功
        if(n<a[mid]) high=mid-1;
        else low=mid+1;
    }
    return low;//查找失败，应插入位置
}
int main(){
    int a[8]={1,2,3,5,6,7,8,9};
    int i=BinarySearch(a,8,4);
    printf("%d",i);
}