#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[10001];
bool visited[10001];
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    };
    memset(visited, false, sizeof(visited));
};
void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for(int i : g[u]){
        int v = g[u][i];
        if(!visited[v]){
            dfs(v);
        };
    };
};
int main(){
    inp();
    dfs(1);
    return 0;
};