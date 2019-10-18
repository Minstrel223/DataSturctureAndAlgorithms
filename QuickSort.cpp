#include <stdio.h>
int Partiition(int a[],int low,int high){
    int pivot=a[low];
    while(low<high){
        while(low<high&&a[high]>=pivot) high--;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) low++;
        a[high]=a[low];
    }
    a[low]=pivot;
    for(int i=0;i<6;i++) printf("%d ",a[i]);
    printf("---\n");
    return low;
}
void QuickSort(int a[],int low,int high){
    if(low<high){
        int pos=Partiition(a,low,high);
        QuickSort(a,low,pos-1);
        QuickSort(a,pos+1,high);
    }
}
int main(){
    int a[6]={21,19,23,16,30,20};
    QuickSort(a,0,5);
    for(int i=0;i<6;i++) printf("%d ",a[i]);
}