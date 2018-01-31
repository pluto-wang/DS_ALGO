#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void heap_sort(int*,int);
void heapify(int*,int,int);
void swap(int*,int,int);

int main(){
    
    int list[]={28,13,1,77,9,24,7};
    printf("Original list: ");
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    printf("\nSorted list: ");   
    heap_sort(list,sizeof(list)/sizeof(int));
    for(int i =0;i<sizeof(list)/sizeof(int);i++)
        printf("%d ",list[i]);
    return 0;
}

void swap (int *data, int i, int j){ 
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}
// adjust to Max Heap
void heapify(int *data, int root, int length){
    int leftChild = root*2 + 1;	    
    int rightChild = root*2 + 2;    
    int maxNode = -1;
		
    // find the maxNode on root, leftChild, rightChild
    if(leftChild < length && (data[leftChild] > data[root]))
        maxNode = leftChild;
    else
        maxNode = root;	
    if(rightChild < length && (data[rightChild] > data[maxNode]))
        maxNode = rightChild;
	
    if(maxNode != root){
        swap(data, root, maxNode);
        heapify(data, maxNode, length);
    }	
}

void heap_sort(int *data,int size){
    // adjust to Max Heap
    for(int i = floor(size/2)-1; i >= 0; i--){ //start from the last not leaf element
        heapify(data, i, size);
    }	
    //sort
    for(int i = size - 1; i > 0; i--){
        swap(data, 0, i); //swap root and the last element
        heapify(data, 0, i);
    }
}

