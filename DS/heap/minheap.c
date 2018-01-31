#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void min_heapify(int*,int,int);
void swap(int*,int,int);

int main(){
    
    int list[]={28,13,1,77,9,24,7};
    printf("Original list: ");
    int size = sizeof(list)/sizeof(int);
    for(int i =0;i<size;i++)
        printf("%d ",list[i]);
    printf("\nMin heap: ");
    for(int i = floor(size/2)-1; i >= 0; i--) //start from the last not leaf element
        min_heapify(list, i, size);
    for(int i =0;i<size;i++)
        printf("%d ",list[i]);
    return 0;
}

void swap (int *data, int i, int j){ 
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}
// adjust to Min Heap
void min_heapify(int *data, int root, int length){
    int leftChild = root*2 + 1;     
    int rightChild = root*2 + 2;    
    int minNode = -1;
        
    // find the minNode on root, leftChild, rightChild
    if(leftChild < length && (data[leftChild] < data[root]))
        minNode = leftChild;
    else
        minNode = root; 
    if(rightChild < length && (data[rightChild] < data[minNode]))
        minNode = rightChild;
    
    if(minNode != root){
        swap(data, root, minNode);
        min_heapify(data, minNode, length);
    }   
}