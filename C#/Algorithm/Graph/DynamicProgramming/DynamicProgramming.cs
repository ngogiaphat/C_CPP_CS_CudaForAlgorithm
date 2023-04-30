using System;
public class Fibonacci {
    public static int GetNthFibonacci(int n){
        int[] fib = new int[n + 1];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= n; ++i){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[n];
    }
}
public class Program {
    static void Main(string[] args) {
        int n = 10;
        int result = Fibonacci.GetNthFibonacci(n);
        Console.WriteLine("The {0}th Fibonacci number is {1}", n, result);
    }
}