#include <stdio.h>
#include <stdlib.h>

/* tree structure
       8  
    3    10
  1   6     14
    4  7  13    
    
contains 9 nodes */
  
struct tree{
    struct tree *left,*right;
    int data;
};
typedef struct tree *Treeptr;

void creat();
void insert(int);
void search(int);
void preorder(Treeptr);
void inorder(Treeptr);
void postorder(Treeptr);
void getDepth(Treeptr);

Treeptr root;
int d = 0, num = 0, dep[15];
void main(){
    creat(); // 3 node
    
    insert(1);
    insert(14);
    insert(6);
    insert(4);
    insert(13);
    insert(7);
    search(13);
    
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("inorder: ");
    inorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    getDepth(root);
    printf("\n");
    printf("leaf depth: ");
    for(int i=0; i<15; ++i)
        printf("%d ",dep[i]);
        
    
}
void creat(){
    root=(Treeptr)malloc(sizeof(struct tree));
    root->data = 8;
    Treeptr l,r;
    l=(Treeptr)malloc(sizeof(struct tree));
    r=(Treeptr)malloc(sizeof(struct tree));
    root->left = l;
    l->data = 3;
    root->right = r;
    r->data = 10;
}

void insert(int num){
    Treeptr node,parent,x;
    node = (Treeptr)malloc(sizeof(struct tree));
    parent = (Treeptr)malloc(sizeof(struct tree));
    x = (Treeptr)malloc(sizeof(struct tree));
    if(root!=NULL){
        parent = root;
        while(parent!=NULL){
            x = parent;
            if(num > parent->data){ //right
                parent = parent->right;
            }
            else{ //left
                parent = parent->left;
            }
        }
    node->data = num;
    if(num < x->data)
        x->left = node;
    else
        x->right =node;
    }
}

void getDepth(Treeptr n){
    if(n == NULL) return;
    ++d;
    getDepth(n->left);
    if(n->left == NULL && n->right == NULL) //leaf
            dep[num++] = d;
    getDepth(n->right);
    --d;
}

void search(int target){
    int ind,flag = 0;
    Treeptr parent;
    parent = (Treeptr)malloc(sizeof(struct tree));
    if(root!=NULL){
        parent = root;
        while(parent!=NULL){
            if(target > parent->data){ //right
                parent = parent->right;
                ind = ind*2 + 2;
            }
            else if(target < parent->data){ //left
                parent = parent->left;
                ind = ind*2 +1;
            }
            else{
                printf("The target is in index %d\n",ind);
                flag =1;
                break;
            }
        }
    if(flag!=1)
        printf("The target does not find!\n");
    }
}

void preorder(Treeptr node){ //root->left->right
    if(node==NULL) 
        return;
    printf("%d ",node->data);
    preorder(node->left);
    preorder(node->right);
}

void inorder(Treeptr node){ //left->root->right
    if(node==NULL) 
        return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);
}
void postorder(Treeptr node){ //left->right->root
    if(node==NULL) 
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->data);
}