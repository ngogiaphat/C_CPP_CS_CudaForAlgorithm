#include <vector>
#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;
struct Rectangle {
    ll 
    x1, 
    y1, 
    x2, 
    y2;
};
ll countCoveredCells(vector<Rectangle>& rectangles){
    vector<ll> xs, ys;
    for(Rectangle r: rectangles){
        xs.push_back(r.x1);
        xs.push_back(r.x2);
        ys.push_back(r.y1);
        ys.push_back(r.y2);
    };
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    vector<vector<bool>> filled(xs.size() -1, vector<bool>(ys.size() -1));
    for(Rectangle r: rectangles){
        int x1 = lower_bound(xs.begin(), xs.end(), r.x1) - xs.begin();
        int x2 = lower_bound(xs.begin(), xs.end(), r.x2) - xs.begin();
        int y1 = lower_bound(ys.begin(), ys.end(), r.y1) - ys.begin();
        int y2 = lower_bound(ys.begin(), ys.end(), r.y2) - ys.begin();
        for(int x = x1; x < x2; x++){
            for(int y = y1; y < y2; y++){
                filled[x][y] = true;
            };
        };
    };
    ll count = 0;
    for(int x = 0; x < filled.size(); x++){
        for(int y = 0; y < filled[x].size(); y++){
            if(filled[x][y]){
                count++;
            };
        };
    };
    return count;
};
int main(){
    int n;
    cin >> n;
    vector<Rectangle> rectangles(n);
    for(int i = 0; i < n; i++){
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >> rectangles[i].y2;
    };
    ll result = countCoveredCells(rectangles) % MOD;
    cout << result << endl;
    return 0;
};