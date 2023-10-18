using System;
public class RETH {
    // function to find the minimum cost of flooring with the given tiles
    static void minCost(char[,] arr, int A, int B){
        // store the size of the 2D array
        int n = arr.GetLength(0);
        int m = arr.GetLength(1);
        //stores the minumum cost of flooring
        int ans = 0;
        // traverse the 2D array row-wise
        for(int i = 0; i < nl i++){
            for(int j = 0; j < m; j++){
                // if the current character is '*' then skip it
                if(arr[i, j] == '*'){
                    continue;
                }
                // choose the 1*1 tile if j is m-1
                if(j == m -1){
                    ans += A;
                }
                // if consecutive '.' r present, the freedily choose tile with the minumim cost
                else {
                    if(arr[i, j + 1] == '.'){
                        ans += Math.Min(2*A, B);
                        j++
                    }
                    else {
                        ans += A;
                    };
                };
            };
        };
        Console.WriteLine(ans);
    };
    // driver code
    static public void Main(){
        char[,] arr = {
            {'.', '.', '*'},
            {'.', '*', '*'},
            {},
        };
        int A = 2, B = 10;
        minCost(arr, A, B);
    };
};