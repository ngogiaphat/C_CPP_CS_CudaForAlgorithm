#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001;
int n, m;
vector<int> g[maxn];
bool visited[maxn];
vector<int> topo;
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    };
    memset(visited, false, sizeof(visited));
};
void dfs(int x){
    visited[x] = true;
    for(int y : g[x]){
        if(!visited[y]){
            dfs(y);
        };
    };
    topo.push_back(x);
};
int main(){
    inp();
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
        };
    };
    reverse(topo.begin(), topo.end());
    for(int x : topo){
        cout << x << ' ';
    };
    return 0;
};