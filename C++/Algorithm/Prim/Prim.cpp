#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<vector<pair<int, int>>>adj(N);
int V, E;
void primsAlgorithm(){
    vector<int>key(V, INT_MAX);
    vector<int>parent(V, -1);
    vector<bool>inMST(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    int src = 0;
    pq.push(make_pair(0, src));
    key[src] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;
        for(auto i : adj[u]){
            int v = i.first;
            int weight = i.second;
            if(inMST[v] == false && weight < key[v]){
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << endl;
    }
}
int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    primsAlgorithm();
    return 0;
}