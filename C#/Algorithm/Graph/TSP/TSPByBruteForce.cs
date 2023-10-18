using System;
using System.Collections.Generic;
using System.Text;
namespace TSP {
    class Program {
        const int N = int.MaxValue;
        static int n = 4;
        static int[,] dist = {
            {0, 20, 42, 25},
            {20, 0, 30, 34},
            {42, 30, 0, 10},
            {25, 34, 10, 0}
        };
        static List<int> v = new List<int>();
        static int Min(int a, int b){
            return (a < b) ? a : b;
        }
        static int Tsp(int s){
            for(int i = 0; i < n; i++){
                if(i != s){
                    v.Add(i);
                }
            }
            int min_path = N;
            do {
                int cur_path = 0;
                int k = s;
                for(int i = 0; i < v.Count; i++){
                    cur_path += dist[k, v[i]];
                    k = v[i];
                }
                cur_path += dist[k, s];
                min_path = Min(min_path, cur_path);

            }
            while(NextPermutation(v));
            return min_path;
        }
        static bool NextPermutation(List<int> nums){
            int i = nums.Count - 2;
            while(i >= 0 && nums[i] >= nums[i + 1]) i--;
            if(i < 0)
            return false;
            int j = nums.Count - 1;
            while(nums[j] <= nums[i]) j--;
            Swap(nums, i, j);
            Reverse(nums, i + 1, nums.Count - 1);
            return true;
        }
        static void Swap(List<int> nums, int i, int j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        static void Reverse(List<int> nums, int l, int r){
            while(l < r){
                Swap(nums, l, r);
                l++;
                r--;
            }
        }
        static void Main(string[] args){
            int s = 0;
            Console.WriteLine(Tsp(s));
        }
    }
}