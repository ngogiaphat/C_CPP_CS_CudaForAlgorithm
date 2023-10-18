#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[10001];
int a[10001][10001];
int main(){
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s, num;
        getline(cin, s);
        stringstream ss(s);
        int x;
        while(ss >> num){
            adj[i][stoi(num)] = 1;
        };
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << adj[i][j] << " ";
        };
        cout << endl;
    };
};