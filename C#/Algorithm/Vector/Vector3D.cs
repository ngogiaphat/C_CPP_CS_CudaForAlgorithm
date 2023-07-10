using System;
namespace Vector3D {
    class Program {
        static void Main(string[] args){
            Vector3D vector1 = new Vector3D(1, 2, 3);
            Vector3D vector2 = new Vector3D(4, 5, 6);
            Console.WriteLine("Vector 1:" + vector1);
            Console.WriteLine("Vector 2:" + vector2);
            Vector3D sum = vector1 + vector2;
            Console.WriteLine("Sum: " + sum);
            Vector3D difference = vector1 - vector2;
            Console.WriteLine("Difference: " + difference);
            Vector3D scalarProduct = vector1 * 2;
            Console.WriteLine("Scalar product: " + scalarProduct);
            double dotProduct = Vector3D.DotProduct(vector1, vector2);
            Console.WriteLine("Dot product: " + dotProduct);
            Vector3D crossProduct = Vector3D.CrossProduct(vector1, vector2);
            Console.WriteLine("Cross product: " + crossProduct);
            double magnitude = vector1.Magnitude();
            Console.WriteLine("Magnitude of vector 1: " + magnitude);
            Console.ReadLine();
        };
    };
    class Vector3D{
        private double x;
        private double y;
        private double z;
        public Vector3D(double x, double y, double z){
            this.x = x;
            this.y = y;
            this.z = z;
        };
        public override string ToString(){
            return "(" + x + ", " + y + ", " + z + ")";
        };
        public static Vector3D operator +(Vector3D v1, Vector3D v2){
            return new Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        };
        public static Vector3D operator -(Vector3D v1, Vector3D v2){
            return new Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
        };
        public static Vector3D operator *(Vector3D v, double scalar){
            return new Vector3D(v.x * scalar, v.y * scalar, v.z * scalar);
        };
        public static double DotProduct(Vector3D v1, Vector3D v2){
            return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
        };
        public static Vector3D CrossProduct(Vector3D v1, Vector3D v2){
            double x = v1.y * v2.z - v1.z * v2.y;
            double y = v1.z * v2.x - v1.x * v2.z;
            double z = v1.x * v2.y - v1.y * v2.x;
            return new Vector3D(x, y, z);
        }
        public double Magnitude(){
            return Math.Sqrt(x * x + y * y + z * z);
        };
    };
};