#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void enqueue(int);
void dequeue();
int queue[MAX_SIZE], front = 0, rear = 0;
//first in first out
void main(){
    enqueue(0);
    enqueue(1);
    enqueue(6);
    dequeue();
    dequeue();
    dequeue();
}

void enqueue(int data){
    if (rear == MAX_SIZE)
        printf("The queue is full!\n");
    else
        queue[rear++] = data;
}

void dequeue(){
    if (front == rear)
        printf("The queue is empty!\n");
    else
        printf("%d\n", queue[front++]);
}