#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int u, v, w;
};
const int MAXN = 1000;
const int INF = 1e9;
vector<Edge> edges;
int dist[MAXN];
int V, E;
bool bellman_ford(int source){
    fill(dist, dist + V, INF);
    dist[source] = 0;
    for (int i = 1; i < V; i++){
        for (int j = 0; j < E; j++){
            int u = edges[j].u;            
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < E; j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]){
            return true;
        }
    }
    return false;
}
int main(){
    cin >> V >> E;
    for (int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    if (bellman_ford(0)){
        cout << "Chu trình âm tồn tại" << endl;
    } 
    else {
        cout << "Không tồn tại chu trình âm" << endl;
    }
    return 0;
}