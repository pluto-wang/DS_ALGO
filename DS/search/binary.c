#include <stdio.h>
int binary_search(int*,int,int);

int main(){
    
    int list[]={11,15,23,27,35,38,40,52,61,78};
    int num = 0;
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nEnter your searching number: \n");
    scanf("%d",&num);   
    int index = binary_search(list,sizeof(list)/sizeof(int),num);
    printf("Searching number is in the %d index",index);
    return 0;
}
int binary_search(int *a, int size,int n){
    int left = 0;
    int right = size-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(n>a[mid]) //right
            left = mid+1;
        else if(n<a[mid])  //left  
            right = mid-1;
        else
            return mid;
    }
    return -1;
}
