from queue import Queue

edges = {}


def add_edge(from_node, to_node):
    if from_node not in edges:
        edges[from_node] = {to_node}
    else:
        edges[from_node].add(to_node)


def bfs(graph, from_node):
    queue = Queue()
    queue.put((from_node, -1))
    comes_from = {}
    while not queue.empty():
        next_node, coming_from = queue.get()
        if next_node not in comes_from:
            comes_from[next_node] = coming_from
            for nabour in graph[next_node]:
                queue.put((nabour, next_node))
    return comes_from


# TEST:
add_edge(0, 1)
add_edge(0, 2)
add_edge(1, 2)
add_edge(2, 0)
add_edge(2, 3)
add_edge(3, 3)
print(bfs(edges, 2))
