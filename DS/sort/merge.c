#include <stdlib.h>
#include <stdio.h>

void merge(int [],int,int,int);
void merge_sort(int [],int,int);

int main(){
    
    int list[]={28,13,41,77,9,24,7};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    merge_sort(list,0,sizeof(list)/sizeof(int)-1);
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    return 0;
}
 
void merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[]*/
    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[] */
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}
 
void merge_sort(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}