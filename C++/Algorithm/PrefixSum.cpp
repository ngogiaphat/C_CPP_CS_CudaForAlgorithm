#include<bits/stdc++.h>
using namespace std;
int n, q;
long long a[200005], prefSum[200005];
void buildPrefixSum(){
    prefSum[1] = a[1];
    for(int i = 2; i <= n; i++){
        prefSum[i] = prefSum[i - 1] + a[i];
    }
}
void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    buildPrefixSum();
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefSum[r] - prefSum[l - 1] << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    solve();
    return 0;
}