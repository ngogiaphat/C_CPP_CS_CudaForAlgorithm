#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
struct queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

struct graph {
    int vertices;
    int** matrix;
};
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
struct graph* createGraph(int vertices);
void addEdge(struct graph* graph, int src, int dest);
void printGraph(struct graph* graph);
void bfs(struct graph* graph, int startVertex);
int main(){
    struct graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    bfs(graph, 0);
    return 0;
}
struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
void enqueue(struct queue* q, int value){
    if (q->rear == MAX_QUEUE_SIZE - 1)
        printf("\nQueue is Full!!");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct queue* q){
    int item;
    if(q->front == -1){
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
    }
    return item;
}
void display(struct queue* q){
    int i;
    if(q->rear == -1)
        printf("Queue is empty");
    else {
        for (i = q->front; i <= q->rear; i++)
            printf("\n%d", q->items[i]);
    }
}
struct graph* createGraph(int vertices){
    int i, j;
    struct graph* graph = (struct graph*)malloc(sizeof(struct graph));
    graph->vertices = vertices;
    graph->matrix = (int**)malloc(vertices * sizeof(int*));
    for(i = 0; i < vertices; i++){
        graph->matrix[i] = (int*)malloc(vertices * sizeof(int));
        for(j = 0; j < vertices; j++){
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}
void addEdge(struct graph* graph, int src, int dest){
    //Add edge
    graph->matrix[src][dest] = 1;
    //Add bak edge for undirected graph
    //Graph->matrix[dest][src] = 1;
}
void printGraph(struct graph* graph){
    int i, j;
    for(i = 0; i < graph->vertices; i++){
        for(j = 0; j < graph->vertices; j++){
            printf("%d  ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
void bfs(struct graph* graph, int startVertex){
    int visited[graph -> vertices]; 
    visited[startVertex] = 1;
    struct queue* q = createQueue();
    enqueue(q, startVertex);
    while (q->rear != -1){
        int currentVertex = dequeue(q);
        printf("Visited %d", currentVertex);
        int i;
        for(i = 0; i < graph->vertices; i++){
            if (graph->matrix[currentVertex][i] == 1 && !visited[i]){
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}