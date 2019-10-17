#!/usr/bin/env python3

# Number of vertices
n = 5

# List of edges where edges[i] is the list of neighbours of i^th node
# 0-based indexing
edges = [[1, 3], [0, 2, 4], [1, 3, 4], [0, 2], [1, 2]]

# q is the queue used. dis is the distance array which initially has value -1 for all nodes
q = [(0, 0)]
dis = [-1] * n

while len(q) != 0:
    # we remove current element from queue
    el = q[0][0]
    cd = q[0][1]
    q.remove((el, cd))

    # if node has not been visited, we give it a distance value
    if dis[el] == -1:
        dis[el] = cd

    # adding neighbours of current element to queue
    for i in edges[el]:
        if dis[i] == -1:
            q.append((i, cd+1))

print(dis)
