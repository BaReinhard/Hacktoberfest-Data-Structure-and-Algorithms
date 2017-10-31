/* Graphs: Breadth-first search */

function bfs(graph, root) {
    var nodesLen = {};
    
    for (var i = 0; i < graph.length; i++) {
      nodesLen[i] = Infinity;
    }
    nodesLen[root] = 0; 
    
    var queue = [root]; 
    var current; 
  
    while (queue.length != 0) {
      current = queue.shift();
      
      var curConnected = graph[current];
      var neighborIdx = []; 
      var idx = curConnected.indexOf(1); 
      while (idx != -1) {
        neighborIdx.push(idx); 
        idx = curConnected.indexOf(1, idx + 1); 
      }
      
      for (var j = 0; j < neighborIdx.length; j++) {
        if (nodesLen[neighborIdx[j]] == Infinity) {
          nodesLen[neighborIdx[j]] = nodesLen[current] + 1;
          queue.push(neighborIdx[j]); 
        }
      }
    }
    return nodesLen;
  };
  
  // Enter your tree here
  var exBFSGraph = [
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0]
  ];
  console.log(bfs(exBFSGraph, 1));