#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define F first
#define S second
typedef pair<int, int>P;
typedef tuple<int, int, int>T;
class DisjointSetUnion {
    public:
    vector<int>parent;
    vector<int>size;
    DisjointSetUnion(int n){
        parent = vector<int>(n+1, 0);
        for(int i=0;i<=n;i++)parent[i]=i;
        size = vector<int>(n+1, 1);
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void merge(int x, int y){
        int px=find(x),py=find(y);
        if(px==py)return;
        if(size[px]<size[py]){
            parent[px]=py;
            size[py]+=size[px];
        }
        else{
            parent[py]=px;
            size[px]+=size[py];
        }
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
};
int main(){
    int n,m; cin >> n >> m;
    DisjointSetUnion uf(n);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        uf.merge(u,v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(uf.parent[i]==i)ans++;
    cout << ans << endl;
    return 0;
}