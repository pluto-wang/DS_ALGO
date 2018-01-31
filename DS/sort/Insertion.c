#include <stdio.h>
void insertion_sort(int [],int);

int main(){
    
    int list[]={28,13,41,69,9,24,57};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    insertion_sort(list,sizeof(list)/sizeof(int));
    return 0;
}
void insertion_sort(int a[], int size){
    int temp = 0;
    for(int i=1;i<size;i++){
        int tmp = a[i];
        for(int j=i;j>=0;j--){
            if(tmp < a[j-1]){
                temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    for(int i =0;i<size;i++)
        printf("%d ",a[i]);
}