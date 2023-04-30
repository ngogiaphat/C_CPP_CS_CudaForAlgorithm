#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
//Vertex storage structure and corresponding weight 
struct Edge {
    int src, dest, weight;
};
//Main function to find the shortest path from a vertex to all other vertices in the graph 
void bellmanFord(int V, int E, vector<Edge>& edges, int src){
    //Initial distance all infinity 
    vector<int> dist(V, INF);
    //Set the distance from the starting function to 0
    dist[src] = 0;
    //Do |V|-1 iteration to find the shortest path
    for (int i = 1; i <= V - 1; i++){
        for (int j = 0; j < E; j++){
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    //Check if there is a negative cycle
    for (int i = 0; i < E; i++){
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;        
        if (dist[u] != INF && dist[u] + weight < dist[v]){
            cout << "Negative cycle detected!";
            return;
        }
    }
    //Print result
    cout << "Vertex Distance from Source";
    for (int i = 0; i < V; i++) {
        cout << i << "" << dist[i] << endl;    }
}
int main(){
    //Create Graph
    int V = 5;
    int E = 8;
    vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    int src = 0;
    bellmanFord(V, E, edges, src);
    return 0;
}