#include<bits/stdc++.h>
using namespace std;
int parent[10001], rankArr[10001];
struct Edge{
    int u, v, w;
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int find(int i){
    if(parent[i] == i){
        return i;
    }
    return parent[i] = find(parent[i]);
}
void Union(int x, int y){
    int rootX = find(x);
    int rootY = find(y);
    if(rankArr[rootX] < rankArr[rootY]){
        parent[rootX] = rootY;
    }
    else if(rankArr[rootX] > rankArr[rootY]){
        parent[rootY] = rootX;
    }
    else{
        parent[rootX] = rootY;
        rankArr[rootY]++;
    }
}
vector<Edge> Kruksal(vector<Edge> edges, int n){
    vector<Edge> MST;
    sort(edges.begin(), edges.end(), cmp);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rankArr[i] = 0;
    }
    int cnt = 0;
    for(auto edge : edges){
        int u = edge.u, v = edge.v, w = edge.w;
        if(find(u) != find(v)){
            cnt++;
            MST.push_back({u, v, w});
            Union(u, v);
        }
        if(cnt == n - 1){
            break;
        }
    }
    return MST;
}
int main(){
    int n = 5;
    vector<Edge> edges = {{0, 1 ,6}, {0, 3 ,1}, {1, 2 ,5}, {1, 3, 2}, {1, 4, 2}, {2, 4, 1}, {3, 4, 1}};
    vector<Edge> MST = Kruksal(edges, n);
    for(auto edge : MST){
        cout << edge.u << " - " << edge.v << " : " << edge.w << endl;
    }
    return 0;
}