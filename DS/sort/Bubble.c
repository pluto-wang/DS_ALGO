#include <stdio.h>
void bubble_sort(int [],int);

int main(){
    
    int list[]={28,13,41,77,9,24,7};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    bubble_sort(list,sizeof(list)/sizeof(int));
    return 0;
}
void bubble_sort(int a[], int size){
    int temp = 0;
    int flag = 1;
    for(int i=0;i<size && flag ==1;i++){
        flag = 0;
        for(int j=0;j<size-i;j++){
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                flag = 1;
            }
        }
        
    }
    for(int i =0;i<size;i++)
        printf("%d ",a[i]);
}