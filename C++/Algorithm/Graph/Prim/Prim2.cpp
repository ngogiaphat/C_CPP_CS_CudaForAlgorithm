#include<bits/stdc++.h>
using namespace std;
struct horizon {
    int x, y, w;
};
int n, m;
vector<pair<int, int>> g[1001];
bool used[1001];
void scanf(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back(make_pair(y, w));
        g[y].push_back(make_pair(x, w));
    };
    memset(used, false, sizeof(used));
};
void prim(int u){
    vector<horizon> mst;
    int d = 0;
    used[u] = true;
    while(mst.size() < n - 1){
        int min_w = INT_MAX;
        int x, y;
        for(int i = 1; i <= n; i++){
            if(used[i]){
                for(pair<int, int> it : g[i]){
                    int j = it.first, numberimportant = it.second;
                    if(!used[j] && numberimportant < min_w){
                        min_w = numberimportant;
                        x = i;
                        y = j;
                    };
                };
            };
        };
        mst.push_back({x, y, min_w});
        d += min_w;
        used[x] = true;
    };
    cout << d << endl;
    for(horizon e : mst){
        cout << e.x << " " << e.y << " " << e.w << endl;
    };
};
int main(){
    scanf();
    prim(1);
    return 0;
};