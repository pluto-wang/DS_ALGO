#include <stdlib.h>
#include <stdio.h>

void quick_sort(int*,int,int);
void swap(int*,int,int);

int main(){
    
    int list[]={28,13,1,77,9,24,7};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    quick_sort(list,0,sizeof(list)/sizeof(int)-1);
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    return 0;
}

/* The first element is the pivot*/ 
void quick_sort(int *data, int left, int right){
    int pivot, i, j;

    if (left >= right) 
        return; 
    pivot = data[left];
    i = left + 1;
    j = right;

    while (1){
        while (i <= right){
            if (data[i] > pivot) //find bigger than pivot
                break;
            i++;
        }

        while (j > left){
            if (data[j] < pivot) //find smaller than pivot
                break;
            j--;
        }

        if (i > j)
            break; 
        swap(data,i,j);
    }

    swap(data,left,j);
    quick_sort(data, left, j - 1);
    quick_sort(data, j + 1, right);
}

void swap(int *data,int a, int b){
    int temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}
