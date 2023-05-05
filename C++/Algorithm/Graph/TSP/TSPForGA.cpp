#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const int MAXN = 100; //Maximum number of cities
const int MAXGEN = 1000; // Số thế hệ tối đa
const int POPSIZE = 100; // Kích thước quần thể
const double MUTRATIO = 0.2; //Mutation rate
const double CROSSRATIO = 0.3; //Crossover rate
const double LIMIT = 1e-9; //Fitness correction threshold
int n; //Cities
double d[MAXN][MAXN]; //Distance Matrix
int a[POPSIZE][MAXN]; //Solution Matrix
double fit[POPSIZE]; //Value fitness

//Create solution
void init(){
    for(int t = 0; t < POPSIZE; ++t){
        for(int i = 0; i < n; ++i){
            a[t][i] = i;
        }
        for(int i = 0; i < n; ++i){
            int j = rand() % n;
            swap(a[t][i], a[t][j]);
        }
    }
}
//Update fitness
void calcFitness(){
    for(int t = 0; t < POPSIZE; ++t){
        fit[t] = 0;
        for(int i = 0; i < n - 1; ++i) {
            fit[t] += d[a[t][i]][a[t][i + 1]];
        }
        fit[t] += d[a[t][n - 1]][a[t][0]];
    }
}
//Crossover
void crossover(int t1, int t2){
    int p = rand() % (n - 1) + 1;
    for(int i = 0; i < n; ++i){
        if(i < p) {
            continue;
        }
        int j = 0;
        while(j < n && a[t1][j] != a[t2][i]){
            ++j;
        }
        if(j == n) {
            a[t1][p++] = a[t2][i];
        }
    }
    for(int i = 0; i < n; ++i){
        if(i < p){
            continue;
        }
        int j = 0;
        while(j < n && a[t2][j] != a[t1][i]){
            ++j;
        }
        if(j == n){
            a[t2][p++] = a[t1][i];
        }
    }
}
//Mutate
void mutate(int t){
    int p1 = rand() % n;
    int p2 = rand() % n;
    while(p1 == p2) {
        p2 = rand() % n;
    }
    swap(a[t][p1], a[t][p2]);
}
//Selection
void selection(){
    double newFit[POPSIZE + 1];
    int idx[POPSIZE + 1];
    for(int t = 0; t < POPSIZE; ++t) {
        idx[t] = t;
        newFit[t] = 1.0 / (1.0 + fit[t]);
    }
    newFit[POPSIZE] = 0;
    for(int t = 0; t < POPSIZE; ++t){
        newFit[POPSIZE] += newFit[t];
    }
    for(int t = 0; t < POPSIZE; ++t){
        double r = (double)rand() / RAND_MAX * newFit[POPSIZE];
        int i = 0;
        while(r > newFit[i]) {
            r -= newFit[i];
            ++i;
        }
        int j = 0;
        do {
            r = (double)rand() / RAND_MAX * newFit[POPSIZE];
            j = 0;
            while(r > newFit[j]) {
                r -= newFit[j];
                ++j;
            }
        }
        while(i == j);
        crossover(idx[i], idx[j]);
        if((double)rand() / RAND_MAX < MUTRATIO){
            mutate(idx[i]);
        }
        if((double)rand() / RAND_MAX < MUTRATIO){
            mutate(idx[j]);
        }
    }
}
//Find best solution
int findBestSolution(){
    int bestidx =0;
    double bestfit = fit[0];
    for(int i  = 1; i < POPSIZE; ++i){
        if(fit[i] < bestfit) {
            bestfit = fit[i];
            bestidx = i;
        }
    }
    return bestidx;
}
//Print result
void printResult(int bestidx){
    cout << "Best solution: ";
    for(int i = 0; i < n; ++i){
        cout << a[bestidx][i] << " ";
    }
    cout << endl;
    cout << "Best fitness: " << fit[bestidx] << endl;
}
//Genetic Algorithm
void geneticAlgorithm(){
    init();
    calcFitness();
    int bestidx = findBestSolution();
    double bestfit = fit[bestidx];
    int cnt = 0;
    while(cnt < MAXGEN && bestfit > LIMIT){
        selection();
        calcFitness();
        int tmpidx = findBestSolution();
        double tmpfit = fit[tmpidx];
        if(tmpfit < bestfit) {
            bestfit = tmpfit;
            bestidx = tmpidx;
            cnt = 0;
        }
        else {
            ++cnt;
        }
    }
    printResult(bestidx);
}
int main(){
    srand((unsigned)time(NULL));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> d[i][j];
        }
    }
    geneticAlgorithm();
    return 0;
}