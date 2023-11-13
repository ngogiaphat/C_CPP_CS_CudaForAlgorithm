#include<bits/stdc++.h>
using namespace std;
int n, m, q;
long long A[1001][1001];
long long dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i][j - 1] - A[i][j];
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        int sum = db[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1];
        cout << sum "\n";
    }
    return 0;
}