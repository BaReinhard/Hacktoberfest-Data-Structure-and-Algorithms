class Graph {
  constructor(vertices = 0) {
    this.graph = Array(vertices).map(() => new Set());
  }

  addEdge(source, destination) {
    this.graph[source].add(destination);
  }

  getEdgesForVertex(vertex) {
    return [...this.graph[vertex]];
  }

  checkIfEdgeExists(source, destination) {
    return this.graph[source].has(destination);
  }
}
