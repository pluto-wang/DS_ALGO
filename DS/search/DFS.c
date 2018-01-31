#include <stdio.h>

void DFS(int);
int G[7][7]={{0,1,1,0,0,0,0},
            {1,0,0,1,1,0,0},
            {1,0,0,0,0,1,1},
            {0,1,0,0,0,0,0},
            {0,1,0,0,0,0,0},
            {0,0,1,0,0,0,0},
            {0,0,1,0,0,0,0}};
int visited[7];   
 
void main(){
    //visited is initialized to zero
   for(int i=0;i<7;i++)
        visited[i]=0;
   DFS(0); //start point
}
 
void DFS(int i){
    printf("\n%d",i);
    visited[i]=1;
    
    for(int j=0;j<7;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}