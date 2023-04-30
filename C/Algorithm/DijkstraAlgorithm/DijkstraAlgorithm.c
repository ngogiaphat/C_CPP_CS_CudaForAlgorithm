#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100
#define INF 1000000

typedef struct{
    int distance;
    int visited;
    int previous_vertex;
}
Vertex;
int min_distance(Vertex vertices[], int num_vertices){
    int min_distance = INF_MAX;
    int min_vertex_index = -1;
    for(int i = 0; i < num_vertices; i++){
        if(!vertices[i].visited && vertices[i].distance < min_distance){
            min_distance = vertices[i].distance;
            min_vertex_index = i;
        }
    }
    return min_vertex_index;
}
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices, int start_vertex, int end_vertex) {
    Vertex vertices[MAX_VERTICES];
    for (int i = 0; i < num_vertices; i++) {
        vertices[i].distance = INF;
        vertices[i].visited = 0;
        vertices[i].previous_vertex = -1;
    }
    vertices[start_vertex].distance = 0;
    for (int i = 0; i < num_vertices - 1; i++) {
        int current_vertex_index = min_distance(vertices, num_vertices);
        vertices[current_vertex_index].visited = 1;
        for (int j = 0; j < num_vertices; j++) {
            int edge_distance = graph[current_vertex_index][j];
            if (edge_distance > 0 && vertices[j].visited == 0) {
                int tentative_distance = vertices[current_vertex_index].distance + edge_distance;
                if (tentative_distance < vertices[j].distance) {
                    vertices[j].distance = tentative_distance;
                    vertices[j].previous_vertex = current_vertex_index;
                }
            }
        }
    }
    printf("Shortest distance between vertices %d and %d is %d\n", start_vertex, end_vertex, vertices[end_vertex].distance);
    //Print shortest path
    int path[MAX_VERTICES];
    int path_index = 0;
    int current_vertex_index = end_vertex;
    while (current_vertex_index != -1) {
        path[path_index] = current_vertex_index;
        path_index++;
        current_vertex_index = vertices[current_vertex_index].previous_vertex;
    }
    printf("Shortest path: ");
    for (int i = path_index - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}
int main() {
    int num_vertices = 7;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 7, 0, 5, 0, 0, 0},
        {7, 0, 8, 9, 7, 0, 0},
        {0, 8, 0, 0, 5, 0, 0},
        {5, 9, 0, 0, 15, 6, 0},
        {0, 7, 5, 15, 0, 8, 9},
        {0, 0, 0, 6, 8, 0, 11},
        {0, 0, 0, 0, 9, 11, 0}
    };
    dijkstra(graph, num_vertices, 0, 6);
    return 0;
}