using System;
class PrimAlgorithm{
    private static readonly int verticesCount = 5;
    private static int MinKey(int[] key, bool[] mstSet){
        int min = int.MaxValue, minIndex = -1;
        for (int i = 0; i < verticesCount; ++i){
            if (mstSet[i] == false && key[i] < min)
                min = key[i];
                minIndex = i;
        }
        return minIndex;
    }
    private static void PrintMST(int[] parent, int[,] graph){
        Console.WriteLine("Đỉnh \t Đỉnh cha");
        for (int i = 1; i < verticesCount; ++i)
            Console.WriteLine(parent[i] + " - " + i + " \t " + graph[i, parent[i]]);
    }
    private static void PrimMST(int[,] graph){
        int[] parent = new int[verticesCount];
        int[] key = new int[verticesCount];
        bool[] mstSet = new bool[verticesCount];
        for (int i = 0; i < verticesCount; ++i){
            key[i] = int.MaxValue;
            mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < verticesCount - 1; ++count){
            int u = MinKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < verticesCount; ++v){
                if (graph[u, v] != 0 && mstSet[v] == false && graph[u, v] < key[v]){
                    parent[v] = u;
                    key[v] = graph[u, v];
                }
            }
        }
        PrintMST(parent, graph);
    }
    public static void Main(string[] args){
        int[,] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };
        PrimMST(graph);
    }
}