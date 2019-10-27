#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int data;
    struct ListNode *link;
};
typedef struct ListNode *Nodeptr;

void show();
void insert(int);
void del(int);
void search(int);
int length();
void reverse();
void release();
Nodeptr head;

void main(){
    head=(Nodeptr)malloc(sizeof(struct ListNode));
    head->link=NULL;
    // insert nodes
    insert(23);
    insert(13);
    insert(2);
    insert(55);
    show();
    
    // calculate the number of elements
    printf("The length is : %d\n",length());
    //search one element
    search(13);
    //delete one elemnet
    del(13);
    show();
    //reverse the linked-list
    reverse();
    show();
    //free the linked-list
    release();
    show();
    
}
void insert(int num){
    Nodeptr p,curr;
    curr = head;
    while(curr->link!=NULL)
        curr=curr->link;
    p=(Nodeptr)malloc(sizeof(struct ListNode));
    p->data =num;
    curr->link=p;
    p->link=NULL;
}

void del(int num){
    printf("delete %d: ", num);
    int i = 0;
    if(head!=NULL){
        Nodeptr curr,pre;
        curr = head;
        while(curr->link!=NULL){
            if(curr->link->data!=num)
                curr=curr->link;
            else{
                pre = curr->link;
                curr->link = curr->link->link;
                free(pre);
                i = 1;
            }
        }
        if(i==0) 
            printf("not contain the deleted element! ");
    }
    else
         printf("Empty\n");
}

void search(int target){ 
    int ind=0;
    if(head!=NULL){
        Nodeptr curr;
        curr = head->link;
        while(curr->link!=NULL){
            if (curr->data == target){
                printf("The target %d is in index %d\n",target,ind+1); 
                ind = -1;
                break;
            }
            ind++;
            curr=curr->link;
        }
    }
    else
        printf("Empty\n");
    if (ind != -1){
        printf("can't search the element!\n");
}

void reverse(){
    printf("Reverse: ");
    // list is empty or list has only one node
    if (head==NULL||head->link==NULL){
        return;
    }
    Nodeptr curr,pre,fut;
    pre = NULL;
    curr = head->link; // the first element
    fut = curr->link; 
    while(fut!=NULL){
        curr->link=pre;
        pre=curr;
        curr=fut;
        fut=fut->link;
    }
    curr->link = pre;
    head->link = curr;
}

void show(){
    if(head!=NULL){
        Nodeptr curr;
        curr = head->link;
        while(curr!=NULL){
            printf("%d->",curr->data);
            curr = curr->link;
        }
        printf("NULL\n");
    }
    else
        printf("Empty\n");
}

void release(){
    Nodeptr curr; 
    while(head!=NULL){
        curr = head;
        head = head->link;
        free(curr);
        }
}

int length(){ //not contain head node
    int len = 0;
    Nodeptr curr;
    curr = head;
    while(curr->link!=NULL){
        len++;
        curr=curr->link;
    }
    return len;
}