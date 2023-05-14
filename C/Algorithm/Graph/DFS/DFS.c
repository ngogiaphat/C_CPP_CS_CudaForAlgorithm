#include<stdio.h>
#include<stdlib.h>
//Define the vertices of the graph
#define V 4
//The function checks whether the vertex has been visited or not
int checkVisited(int visited[], int vertex){
    if(visited[vertex] == 1)
        return 1;
    else
        return 0;
}
//Depth First Search Algorithm
void DFS(int graph[V][V], int start_vertex, int visited[]){
    //Mark current peak visited
    visited[start_vertex] = 1; 
    //Print out the visited vertex
    printf("%d -> ", start_vertex); 
    for(int i = 0; i < V; i++){
        //Check if the i-th vertex is a neighbor of start_vertex
        if(graph[start_vertex][i] == 1){ 
            //If vertex i has not been visited, proceed to visit it
            if(checkVisited(visited, i) == 0){ 
                DFS(graph, i, visited);
            }
        }
    }
}
//Main function to test DFS
int main(){
    //Represent the graph as an adjacency matrix
    int graph[V][V] = {{0,1,1,0}, {1,0,0,1}, {1,0,0,1}, {0,1,1,0}};
    //Array to store visited vertices
    int visited[V] = {0}; 
    printf("Starting from vertex 0 -> ");
    DFS(graph, 0, visited);
    return 0;
}