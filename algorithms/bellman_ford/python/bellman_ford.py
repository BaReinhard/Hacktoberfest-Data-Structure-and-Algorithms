class Graph:
    def __init__(self):
        self.edges = {}
        self.nodes = set()

    def add_edge(self, fromNode, toNode, weight):
        self.nodes.add(fromNode)
        self.nodes.add(toNode)
        self.edges[(fromNode, toNode)] = weight

def bellman_ford(graph, source):
    dist = {source: 0}
    for _ in range(len(graph.nodes) - 1):
        for f, t in graph.edges:
            if f in dist and (t not in dist or dist[f] + graph.edges[(f, t)] < dist[t]):
                dist[t] = dist[f] + graph.edges[(f, t)]
    for f, t in graph.edges:
        if f in dist and t in dist and dist[f] + graph.edges[(f, t)] < dist[t]:
            return None
    return dist


if __name__ == '__main__':
    print("Test for non negative weight graph:")
    g1 = Graph()
    g1.add_edge(0, 1, -1)
    g1.add_edge(0, 2, 4)
    g1.add_edge(1, 2, 3)
    g1.add_edge(1, 3, 2)
    g1.add_edge(1, 4, 2)
    g1.add_edge(3, 2, 5)
    g1.add_edge(3, 1, 1)
    g1.add_edge(4, 3, -3)
    print(bellman_ford(g1, 1))

    print("\nTest for negative weight graph:")
    g2 = Graph()
    g2.add_edge(1, 2, 1)
    g2.add_edge(2, 1, -2)
    print(bellman_ford(g2, 1))
