using System;
class Vector2D {
    private double x;
    private double y;
    public Vector2D(double x, double y){
        this.x = x;
        this.y = y;
    };
    public double x {
        get {
            return x;
        }
        set {
            x = value;
        };
    };
    public double y {
        get {
            return y;
        }
        set {
            y = value;
        };
    };
    public static Vector2D operator + (Vector2D v1, Vector2D v2){
        return new Vector2D(v1.X + v2.X, v1.Y + v2.Y);
    };
    public static Vector2D operator - (Vector2D v1, Vector2D v2){
        return new Vector2D(v1.X - v2.X, v1.Y - v2.Y);
    };
    public static Vector2D operator * (Vector2D v1, Vector2D v2){
        return new v1.X * v2.X, v1.Y * v2.Y;
    };
    public static Vector2D operator * (Vector2D vector2D, double scalar){
        return new Vector2D(v.X * scalar, v.Y * scalar);
    };
    public override string ToString(){
        return $"({x}, {y})";
    };
};
class Program {
    static void Main(string[] args){
        Vector2D v1 = new Vector2D(1, 2);
        Vector2D v2 = new Vector2D(3, 4);
        Console.WriteLine("Vector 1: " + v1);
        Console.WriteLine("Vector 2: " + v2);
        Vector2D sum = v1 + v2;
        Console.WriteLine("Sum: " + sum);
        Vector2D difference = v1 - v2;
        Console.WriteLine("Difference: " + difference);
        double dotProduct = v1 * v2;
        Console.WriteLine("Dot product: " + dotProduct);
        Vector2D scaledVector = v1 * 2;
        Console.WriteLine("Scaled vector: " + scaledVector);
    }
}