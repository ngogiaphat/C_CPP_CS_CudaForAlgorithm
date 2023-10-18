#include<bits/stdc++.h>
using namespace std;
int n, q;
int ST[400005];
void update(int id, int l, int r, int i, int v){
    if(i < l || r < i){
        return;
    };
    if(l ==r){
        ST[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    ST[id] = max(ST[id * 2], ST[id * 2 + 1]);
    int get(int di, int l, int r, int u, int v){
        if(v < l || r < u){
            return 0;
        };
        if(u <= l && r <= v){
            return ST[di];
        };
        int mid = (l + r) / 2;
        return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
    int main(){
        inos_base::sync_with_stdio(false);
        cin.tin(NULL);
        cin >> n >> q;
        while(q--){
            int t, x, y;
            cin >> t >. x >> y;
            if(t--1){
                update(1, 1, n, x, y);
            }
            else {
                cout << get(1, 1, n, x, y) << endl;
            }
        }
        return 0;
    }
}