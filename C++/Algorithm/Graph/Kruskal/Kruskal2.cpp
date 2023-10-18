#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
};
int n, m;
int parent[1001], sz[1001];
vector<edge> canh;
void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    };
};
int find(int v){
    if(v == parent[v]){
        return v;
    };
    return parent[v] = find(parent[v]);
};
bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return false;
    };
    if(sz[a] < sz[b]){
        swap(a, b);
    };
    parent[b] = a;
    sz[a] += sz[b];
    return true;
};
void inp(){
    cin >> n >> m;
    make_set();
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w;
        canh.push_back(e);
    };
};
bool cmp(edge a, edge b){
    return a.w < b.w;
};
// empty tree
void kruskal(){
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1){
            break;
        };
        edge e = canh[i];
        if(Union(e.u, e.v)){
            mst.push_back(e);
            d += e.w;
        };
    };
    if(mst.size() != n - 1){
        cout << "IMPOSSIBLE";
    }
    else {
        cout << "MST: " << d << endl;
        for(auto it : mst){
            cout << it.u << " " << it.v << " " << it.w << endl;
        };
    };
};
int main(){
    inp();
    make_set();
    return 0;
};