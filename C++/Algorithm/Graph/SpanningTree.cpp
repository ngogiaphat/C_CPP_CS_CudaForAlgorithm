#include<bits/stdc++.h>
using namespace std;
struct Node {
    int parent;
    vector<int> neighbors;
};
// funtion find spanning tree
void findSpannigTree(vector<Node>& graph, int start){
    // root of tree
    graph[start].parent = -1;
    vector<int> queue;
    queue.push_back(start);
    while(!queue.empty()){
        int current = queue.front();
        queue.erase(queue.begin());
        for(int i = 0; i < graph[current].neighbors.size(); i++){
            int neighbor = graph[current].neighbors[i];
            if(graph[neighbor].parent == -1){
                graph[neighbor].parent = current;
                queue.push_back(neighbor);
            };
        };
    };
};
int main(){
    int numberVertices, numEdges;
    cout << "Enter number of vertices and edges: ";
    cin >> numberVertices;
    cout << "Enter number of edges: ";
    cin >> numEdges;
    vector<Node> graph(numberVertices);
    cout << "Enter edges: " << endl;
    for(int i = 0; i < numEdges; i++){
        int u, v;
        cin >> u >> v;
        graph[u].neighbors.push_back(v);
        graph[v].neighbors.push_back(u);
    };
    int startVertex;
    cout << "Enter start vertex: ";
    cin >> startVertex;
    findSpannigTree(graph, startVertex);
    cout << "Spanning tree: " << endl;
    for(int i = 0; i < numberVertices; i++){
        if(graph[i].parent != -1){
            cout << i << " " << graph[i].parent << endl;
        };
    };
    return 0;
};