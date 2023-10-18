#include<bits/stdc++.h>
using namespace std;
double eps = 1e - 10;
bool isExit(double l, double r){
    if(r - l > eps){
        return false;
    }
    return true;
}
double sqrt(double n){
    double l = 0, r = n;
    while(!isExit(l, r)){
        double mid = l + (r - l)/2;
        if(fabs(n - mid*mid) <= eps){
            return mid;
        }
        if(mid*mid >= n){
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}
int main(){
    double n = 2;
    cout << fixed << setprecision(9) << sqrt(n);
}