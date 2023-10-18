#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[10001];
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    };
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        };
        cout << endl;
    };
};