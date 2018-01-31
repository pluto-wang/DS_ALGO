#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 100 
int stack[MAXSTACK];  
int top=-1;		
int isEmpty();
void push(int); 
int pop();
 
void main() {
    //first in last out
	push(2);
	push(4);
	push(5);
	push(8);
	
	while(!isEmpty())
		printf("pop order:%d\n",pop()); 
	pop();
}

int isEmpty(){
	if(top==-1)
		return 1; 
	else
		return 0;
} 

void push(int data){
	if(top>=MAXSTACK)
		printf("Stack Full\n");	
	else{
		top++;
		stack[top]=data;
	}
} 

int pop(){
	int data;
	if(isEmpty())
		printf("Empty!\n");
	else{
		data=stack[top];
		top--;
		return data; 
	}
}