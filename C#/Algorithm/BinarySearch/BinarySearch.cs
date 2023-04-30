using System;
public class BinarySearch {
    public static int DoBinarySearch(int[] sortedArray, int key) {
        int left = 0;
        int right = sortedArray.Length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (sortedArray[middle] == key) {
                return middle;
            } 
            else if (sortedArray[middle] > key) {
                right = middle - 1;
            } 
            else {
                left = middle + 1;
            }
        }
        return -1;
    }
}
public class Program {
    static void Main(string[] args) {
        int[] sortedArray = {1, 4, 8, 12, 15, 18, 20};
        int key = 15;
        int index = BinarySearch.DoBinarySearch(sortedArray, key);
        if (index != -1) {
            Console.WriteLine("The index of the key {0} is {1}", key, index);
        } 
        else {
            Console.WriteLine("The key {0} is not found in the sorted array", key);
        }
    }
}