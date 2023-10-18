#include<bits/stdc++.h>
using namespace std;
vector<int> g[10001];
vector<pair<int, int>> edge;
int a[10001][10001];
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        };
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 1){
                g[i].push_back(j);
                edge.push_back({i, j});
            };
        };
    };
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        };
        cout << endl;
    };
};