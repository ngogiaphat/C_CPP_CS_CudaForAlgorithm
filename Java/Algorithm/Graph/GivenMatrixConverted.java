package Java.Algorithm.Graph;
import java.util.*;
public class GivenMatrixConverted {
    // function to get transpose of a matrix
    static int[][] getTranspose(int[][] matrix){
        int n = matrix.length;
        int[][] transpose = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0 ;j < n; j++){
                transpose[i][j] = matrix[j][i];
            };
        };
        return transpose;
    };
    // function to check fot now present in the matrix
    static boolean rowEquality(int[][] s, int[][] f){
        ArrayList<Set<Integer>> sets = new ArrayList<>();
        ArrayList<Set<Integer>> setf = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<>();
        // creating sets from the initial matrix
        for(int i = 0; i < s.length; i++){
            // create set for corresponding row
            Set<Integer> set = new HashSet<Integer>();
            // add first element to the set
            set.add(s[i][0]);
            sets.add(set);
            // store the row number in map
            map.put(s[i][0], i);
            // add remaining elements to the set
            for(int j = 1; j < s.length; j++){
                set.add(s[i][j]);
            };
        };
        // create sets for final matrix and check with the initial matrix
        int rowIndex = -1;
        for(int i = 0; i < f.length; i++){
            rowIndex = -1;
            Set<Integer> set = new HashSet<Integer>();
            for(int j = 0; j < f.length; j++){
                set.add(f[i][j]);
                if(map.containsKey(f[i][j])){
                    rowIndex = map.get(f[i][j]);
                };
            };
            setf.add(set);
            if(rowIndex != -1 && !setf.get(i).equals(sets.get(rowIndex))){
                return false;
            };
        };
        return true;
    };
    // driver code
    public static void main(String[] args){
        int[][] startMatrix = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16},
        };
        int[][] finalMatrix = {
            {1, 5, 9, 13},
            {2, 6, 10, 14},
            {3, 7, 11, 15},
            {4, 8, 12, 16},
        };
        int[][] startTranspose = getTranspose(startMatrix);
        int[][] finalTranspose = getTranspose(finalMatrix);
        if(rowEquality(startMatrix, finalMatrix) && rowEquality(startTranspose, finalTranspose)){
            System.out.println("Yes");
        }
        else {
            System.out.println("No");
        };
    };
};