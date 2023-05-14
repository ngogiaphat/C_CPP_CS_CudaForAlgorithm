//Adjacency graph
const graph = {
  'A': ['B', 'C'],
  'B': ['D', 'E'],
  'C': ['F'],
  'D': [],
  'E': ['F'],
  'F': []
};

//Check function DFS
function dfs(graph, start){
    //Create a set to store the traversed vertices
    const visited = new Set(); 
    function traverse(vertex){
        //If the vertex is already checked, return it
        if (visited.has(vertex)) return; 
        //If you haven't browsed yet, add it to set visited
        visited.add(vertex); 
        //Print out the vertex you are browsing
        console.log(vertex); 
        for(const neighbor of graph[vertex]){ 
            //Traverse the adjacent vertices
            //Recursion into adjacent vertice
            traverse(neighbor); 
        }
    }
    //Start from the top start
    traverse(start);
}
//Traverse the graph from vertex 'A'
dfs(graph, 'A');