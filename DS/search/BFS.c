#include <stdio.h>

void BFS(int);
int G[7][7]={{0,1,1,0,0,0,0},
            {1,0,0,1,1,0,0},
            {1,0,0,0,0,1,1},
            {0,1,0,0,0,0,0},
            {0,1,0,0,0,0,0},
            {0,0,1,0,0,0,0},
            {0,0,1,0,0,0,0}};
int q[7], visited[7], f = 0, r = -1;

void BFS(int v){
    if (visited[v]==0){
        printf("%d\n",v);
        visited[v] = 1;
    }
    for(int i = 0; i < 7; i++) //enqueue neighbor
        if(G[v][i] && visited[i]==0){
            q[++r] = i; 
        }
    if(f <= r) { //not empty
        visited[q[f]] = 1;
        printf("%d\n",q[f]);
        BFS(q[f++]);
    }
}

void main(){
    for(int i=0; i < 7; i++) { //init visit and queue
        q[i] = 0;
        visited[i] = 0;
    }
    BFS(3); //start point
}