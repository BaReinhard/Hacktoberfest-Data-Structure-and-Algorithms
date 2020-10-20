from collections import deque


# class to represent a graph object:
class Graph:
    # Constructor
    def __init__(self, edges, N):

        # A List of Lists to represent an adjacency list
        self.adjList = [[] for _ in range(N)]

        # add edges to the graph
        for (src, dest) in edges:
            # Please note that directed is directed
            self.adjList[src].append(dest)


# Perform BFS on graph g starting from given source vertex
def BFS(g, source, N):

    # create a queue used to do BFS
    q = deque()

    # stores vertex is discovered or not
    discovered = [False] * (N + 1)

    # mark source vertex as discovered
    discovered[source] = True

    # assign minimum distance of source vertex as 0 and
    # push it into the queue
    q.append((source, 0))

    # run till queue is empty
    while q:

        # pop front node from queue
        vertex, minDist = q.popleft()

        # vertex stores number associated with graph node
        # minDist stores minimum distance of node from starting vertex

        # Stop BFS if we have reached last node
        if vertex == N:
            print(minDist)
            break

        # do for every adjacent node of current node
        for u in g.adjList[vertex]:
            if not discovered[u]:
                # mark it discovered & push it into queue
                discovered[u] = True

                # assign minimum distance of current node
                # as minimum distance of parent node + 1
                n = (u, minDist + 1)
                q.append(n)


def findSolution(ladder, snake):

    # Number of vertices in the graph
    N = 10 * 10

    # find all edges involved and store them in a list
    edges = []
    for i in range(N):

        j = 1
        while j <= 6 and i + j <= N:
            src = i

            # update destination if there is any ladder
            # or snake from current position.

            _ladder = ladder.get(i + j) if (ladder.get(i + j)) else 0
            _snake = snake.get(i + j) if (snake.get(i + j)) else 0

            if _ladder or _snake:
                dest = _ladder + _snake
            else:
                dest = i + j

            # add edge from src to dest
            edges.append((src, dest))

            j = j + 1

    # construct directed graph
    g = Graph(edges, N)

    # Find Shortest path between 1 and 100 using BFS
    BFS(g, 0, N)


if __name__ == '__main__':

    # snakes and ladders are represented using a dict.
    ladder = {}
    snake = {}

    # insert ladders into the dictionary
    ladder[1] = 38
    ladder[4] = 14
    ladder[9] = 31
    ladder[21] = 42
    ladder[28] = 84
    ladder[51] = 67
    ladder[72] = 91
    ladder[80] = 99

    # insert snakes into the dictionary
    snake[17] = 7
    snake[54] = 34
    snake[62] = 19
    snake[64] = 60
    snake[87] = 36
    snake[93] = 73
    snake[95] = 75
    snake[98] = 79

    findSolution(ladder, snake)
