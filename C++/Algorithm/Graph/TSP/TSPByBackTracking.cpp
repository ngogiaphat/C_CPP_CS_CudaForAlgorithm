#include<bits/stdc++.h>
using namespace std;
const int N = INT_MAX;
int n = 4;
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};
vector<int> v;
int min(int a, int b){
    return (a < b) ? a : b;
}
int tsp(int s){
    for(int i = 0; i < n; i++){
        if(i != s){
            v.push_back(i);
        }
    }
    int min_path = N;
    do {
        int cur_path = 0;
        int k = s;
        for(int i = 0; i < v.size(); i++){
            cur_path += dist[k][v[i]];
            k = v[i];
        }
        cur_path += dist[k][s];
        min_path = min(min_path, cur_path);
    }
    while(next_permutation(v.begin(), v.end()));
    return min_path;
}
int main(){
    int s = 0;
    cout << tsp(s) << endl;
    return 0;
}