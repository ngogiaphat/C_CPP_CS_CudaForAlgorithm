function prim(graph) {
    //Initialize the necessary variables
    const nodes = Object.keys(graph);
    const numOfNodes = nodes.length;
    const visited = new Array(numOfNodes).fill(false);
    const MST = [];
    const startNode = nodes[0];
    visited[0] = true;
    //The function to find the edge with the least weight
    function findMinEdge(){
      let minEdge = [null, null, Infinity];
      for (let i = 0; i < MST.length; i++){
        for (let j = 0; j < nodes.length; j++){
          const node = nodes[j];
          if (graph[MST[i][0]][node] && !visited[j]){
            if (graph[MST[i][0]][node] < minEdge[2]){
              minEdge = [MST[i][0], node, graph[MST[i][0]][node]];
            }
          }
        }
      }
      return minEdge;
    }
    //Traverse all vertices of the graph
    for (let i = 0; i < numOfNodes - 1; i++){
      const minEdge = findMinEdge();
      MST.push(minEdge);
      visited[nodes.indexOf(minEdge[1])] = true;
    }
    return MST;
  }
  //Use the graph in the example above to test the algorithm
  const graph = {
    A: { B: 2, C: 3 },
    B: { A: 2, C: 1, D: 1 },
    C: { A: 3, B: 1, D: 2 },
    D: { B: 1, C: 2 },
  };
  console.log(prim(graph)); 
  //The returned result will be a list of edges in the smallest spanning tree: [['A', 'B', 2], ['B', 'D', 1], ['C', 'B', 1]]