function Dijkstra(graph, startNode){
    const nodesCount = graph.length;
    const distance = new Array(nodesCount).fill(Number.MAX_VALUE);
    const visited = new Array(nodesCount).fill(false);
    distance[startNode] = 0;
    for(let i = 0; i < nodesCount - 1; i++){
        const currentNode = findNextNodeWithMinDistance(distance, visited);
        if(currentNode === -1) 
        break;
        visited[currentNode] = true;
        for(let j = 0; j < nodesCount; j++){
            if(graph[currentNode][j] > 0 && !visited[j]) {
                const newDistance = distance[currentNode] + graph[currentNode][j];
                if(newDistance < distance[j]){
                    distance[j] = newDistance;
                }
            }
        }
    }
    printResult(distance);
}
function findNextNodeWithMinDistance(distance, visited){
    let minDistance = Number.MAX_VALUE;
    let minNode = -1;
    for(let i = 0; i < distance.length; i++){
      if(!visited[i] && distance[i] < minDistance){
        minDistance = distance[i];
        minNode = i;
      }
    }
    return minNode;
}
function printResult(distance){
    console.log("Vertex Distance from Start Node");
    for (let i = 0; i < distance.length; i++) {
        console.log(${i} ${distance[i]});
    }
}
const graph = [
    [0, 1, 4, 0, 0],
    [1, 0, 2, 5, 0],
    [4, 2, 0, 1, 3],
    [0, 5, 1, 0, 2],
    [0, 0, 3, 2, 0],
];
Dijkstra(graph, 0);