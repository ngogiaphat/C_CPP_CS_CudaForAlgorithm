#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[1001], r_g[1001];
bool visited[1001];
stack<int> st;
void inp(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        r_g[v].push_back(u);
    };
};
void dfs1(int u){
    visited[u] = true;
    for(int v: g[u]){
        if(!visited[v]){
            dfs1(v);
        };
    };
    cout << u << ' ';
    st.push(u);
};
void dfs2(int u){
    visited[u] = true;
    cout << u << ' ';
    for(int v: r_g[u]){
        if(!visited[v]){
            dfs2(v);
        };
    };
};
void scc(){
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs1(i);
        };
    };
    cout << endl;
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!visited[u]){
            cnt++;
            cout << "SCC " << cnt << ": ";
            dfs2(u);
            cout << endl;
        };
    };
    if(cnt == 1){
        cout << "The graph is strongly connected\n";
    }
    else {
        cout << "The graph is not strongly connected\n";
    };
};
int main(){
    inp();
    scc();
    return 0;
};