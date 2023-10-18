#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[10001][10001];
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    };
    for(int i = 1; i <= n; i++){
        cout << i << ": ";
        for(int j = 1; j <= n; j++){
            cout << a[i][j] << " ";
        };
        cout << endl;
    };
};