#include <stdio.h>
void selection_sort(int [],int);

int main(){
    
    int list[]={28,13,41,77,9,24,7};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    selection_sort(list,sizeof(list)/sizeof(int));
    return 0;
}
void selection_sort(int a[], int size){
    int temp,n,j = 0;
    for(int i=0;i<size;i++){
        int min =a[i];
        for(j=i;j<size;j++){
            if(a[j]<min){
                min = a[j];
                n = j;
            }
        }
        temp = a[i];
        a[i] = a[n];
        a[n] = temp;
    }
    for(int i =0;i<size;i++)
        printf("%d ",a[i]);
}