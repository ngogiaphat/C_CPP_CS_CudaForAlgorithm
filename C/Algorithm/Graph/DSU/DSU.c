#include<stdio.h>
#define N 1000
int parent[N];
int rank[N];
//Initialization function
void Initialize(int n){
    for(int i=0;i<=n;++i){
        parent[i]=i;
        rank[i]=0;
    }
}
//Function to find father
int Find(int x){
    if(parent[x]!=x)
        parent[x]=Find(parent[x]);
    return parent[x];
}
//Function to join two sets
void Union(int x, int y){
    int px=Find(x);
    int py=Find(y);
    if(px!=py){
        if(rank[px]<rank[py])
            parent[px]=py;
        else if(rank[py]<rank[px])
            parent[py]=px;
        else {
            parent[px]=py;
            rank[py]++;
        }
    }
}
int main(){
    int n,m,x,y,op;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    Initialize(n);
    printf("Enter the number of edges: ");
    scanf("%d",&m);
    printf("Enter the edges: \n");
    for(int i=0;i<m;++i){
        scanf("%d %d",&x,&y);
        Union(x,y);
    }
    printf("Enter the queries [1 for Query / 0 to exit]: ");
    scanf("%d",&op);
    while(op){
        printf("Enter the nodes to check for connectivity: ");
        scanf("%d %d",&x,&y);
        if(Find(x)==Find(y))
            printf("They are connected.\n");
        else
            printf("They are not connected.\n");
        printf("Enter the queries [1 for Query / 0 to exit]: ");
        scanf("%d",&op);
    }
    return 0;
}