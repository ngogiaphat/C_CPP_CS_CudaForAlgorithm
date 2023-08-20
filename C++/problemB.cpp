#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> skills(n);
    for(int i = 0; i < n; i++){
        cin >> skills[i];
    };
    sort(skills.begin(), skills.end());
    int teams = 0;
    for(int i = 0; i < n - 2; i++){
        if(skills[i + 2] - skills[i] <= 2){
            teams++;
        };
    };
    cout << teams << endl;
    return 0;
};