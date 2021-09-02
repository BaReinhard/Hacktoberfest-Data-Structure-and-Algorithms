#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

#include "FlowGraph.h"

std::istream& operator>> (std::istream& in, FlowGraph& graph) {
  /* Citim numarul de noduri din graf. */
  in >> graph.n;

  /* Alocam graful. */
  graph.capacity = new int*[graph.n];
  graph.edge = new int*[graph.n];
  for (unsigned int i = 0; i < graph.n; ++i) {
    graph.capacity[i] = new int[graph.n];
    graph.edge[i] = new int[graph.n];
    memset(graph.capacity[i], 0x00, graph.n * sizeof(int));
    memset(graph.edge[i], 0x00, graph.n * sizeof(int));
  }

  /* Si punem capacitatile de pe fiecare muchie. */
  unsigned int edges;
  in >> edges;
  for (unsigned int i = 0; i < edges; ++i) {
    unsigned int u, v, capacity;
    in >> u >> v >> capacity;
    graph[u][v] = capacity;
    graph.edge[u][v] = 1;
  }

  return in;
}
