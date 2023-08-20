// #include<vector>
// #include<iostream>
// const int MOD = 1000000007;
// int main(){
//     int n;
//     std::cin >> n;
//     std::vector<long long> energy(n);
//     for(int i = 0; i < n; i++){
//         std::cin >> energy[i];
//     };
//     long long minEnergy = energy[0];
//     long long currentProduct = energy[0];
//     for(int i = 1; i < n; i++){
//         if(energy[i] == 0){
//             minEnergy = 0;
//             break;
//         };
//         currentProduct = (currentProduct * energy[i]) % MOD;
//         minEnergy = std::min(minEnergy, currentProduct);
//     };
//     std::cout << minEnergy << std::endl;
//     return 0;
// };


#include<vector>
#include<iostream>
#include<algorithm>
const int MOD = 1000000007;
int main(){
    int n;
    std::cin >> n;
    std::vector<long long> energy(n);
    for(int i = 0; i < n; i++){
        std::cin >> energy[i];
    };
    std::vector<long long> prefixSum(n);
    prefixSum[0] = energy[0];
    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + energy[i];
    };
    long long minEnergy = prefixSum[n-1];
    for(int i = 0; i < n-1; i++){
        long long currentEnergy = (prefixSum[n-1] - prefixSum[i]) % MOD;
        minEnergy = std::min(minEnergy, currentEnergy);
    };
    std::cout << minEnergy << std::endl;
    return 0;
};