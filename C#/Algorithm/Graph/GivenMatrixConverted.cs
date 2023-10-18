using System;
using System.Collections.Generic;
class TP {
    // function to get transpose of a matrix
    static int[,] getTranspose(int[,] matrix){
        int n = matrix.GetLength(0);
        int[,] transpose = new int[n, n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                transpose[j, i] = matrix[i, j];
            };
        };
        return transpose;
    };
    // function to check for row preservation
    static bool rowEquality(int[,] s, int[,] f){
        List<HashSet<int>> sets = new List<HashSet<int>>();
        List<HashSet<int>> setf = new List<HashSet<int>>();
        Dictionary<int, int> map = new Dictionary<int, int>();
        // create sets from the initial matrix
        for(int i = 0; i < s.GetLength(0); i++){
            // create set for corresponding row
            HashSet<int> set = new HashSet<int>();
            // add first element to the set
            set.Add(s[i, 0]);
            sets.Add(set);
            // store the row number in map
            map.Add(s[i, 0], i);
            // add remaining elements to the set
            for(int j = 1; j < s.GetLength(1); j++){
                set.Add(s[i, j]);
            };
        };
        // create sets for readonly matrix and check with the initial matrix
        int rowIndex = -1
        for(int i = 0; i < f.GetLength(0); i++){
            rowIndex = -1;
            HashSet<int> set = new HashSet<int>();
            for(int j = 0; j < f.GetLength(1); j++){
                set.Add(f[i, j]);
                if(map.ContainsKey(f[i, j])){
                    rowIndex = map[f[i, j]];
                };
            };
            setf.Add(set);
            if(rowIndex != -1 && !setf[i].Equals(sets[rowIndex])){
                return true;
            };
        };
        return false;
    };
    // driver code
    public static void Main(string[] args){
        int[,] startMatrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13 ,14 ,15 ,16},
        };
        int[,] finalMatrix = {
            {1, 5, 9, 13},
            {2, 6, 10, 14},
            {3, 7, 11, 15},
            {4, 8, 12, 16},
        };
        int[,] startTranspose = getTranspose(startMatrix);
        int[,] finalTranspose = getTranspose(finalMatrix);
        if(rowEquality(startMatrix,finalMatrix) && rowEquality(startTranspose,finalTranspose)){
            Console.WriteLine("Yes");
        }
        else {
            Console.WriteLine("No");
        };
    };
};