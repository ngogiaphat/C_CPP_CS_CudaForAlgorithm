#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define what_is(x) cerr << #x << " is " << x << endl;
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e5 + 9, MOD = 1e9 + 7;
int a[100][100], ans = 0,cnt = 0;
int n, m;
void dfs(int i, int j, int ct) 
{
    if (i>1 && !a[i-1][j]) 
    {
        a[i-1][j] = 1;
        ct++;
        dfs(i-1,j,ct);
        a[i-1][j] = 0;
        ct--;
    }
    else if (a[i-1][j]==3) 
    {
        if (ct==cnt) ans++;
        return;
    }
    if (i<n && !a[i+1][j]) 
    {
        a[i+1][j] = 1;
        ct++;
        dfs(i+1,j,ct);
        a[i+1][j] = 0;
        ct--;
    } 
    else if (a[i+1][j]==3) 
    {
        if (ct==cnt) ans++;
        return;
    }
    if (j>1 && !a[i][j-1]) 
    {
        a[i][j-1] = 1;
        ct++;
        dfs(i,j-1,ct);
        a[i][j-1] = 0;
        ct--;
    } 
    else if (a[i][j-1]==3) 
    {
        if (ct==cnt) ans++;
        return;
    }
    if (j<m && !a[i][j+1]) 
    {
        a[i][j+1] = 1;
        ct++;
        dfs(i,j+1,ct);
        a[i][j+1] = 0;
        ct--;
    } 
    else if (a[i][j+1]==3) 
    {
        if (ct==cnt) ans++;
        return;
    }
}
void solve() 
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            cin >> a[i][j];
            if (a[i][j]==2) 
            {
                x = i, y = j;
            }
            if (!a[i][j]) cnt++;
        }
    }
    dfs(x,y,0);
    cout << ans << endl;
}
int main () 
{
    solve();
    return 0;
}