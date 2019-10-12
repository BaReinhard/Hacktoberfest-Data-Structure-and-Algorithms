'''
Question source -- LeetCode
Given n nodes labeled from 0 to n - 1 and a list of undirected edges
(where each edge is a pair of nodes), write a function to find the number
of connected components in an undirected graph.

'''

def countComponents( n, edges):
    """
    :type n: int
    :type edges: List[List[int]]
    :rtype: int
    """
    # finds the path recursively
    def find(data, i):
        if i != data[i]:
            data[i] = find(data, data[i]) 
        return data[i]

    # creates the union find data structure
    def union(data, i, j):
        root_i, root_j = find(data, i), find(data, j)
        if root_i != root_j:
            data[root_i] = root_j

    data = [i for i in range(n)]
    
    for i,j in edges:
        union(data, i, j)
    # set data structure to eliminate the possibilities of duplicates. 
    res = set()

    # union-find the roots of the each nodes in the components. 
    for i in range(n):
        res.add(find(data,i))

    # the total length of the root nodes determine the total number of components. 
    return len(res)


print(countComponents(5, [[0, 1], [1, 2], [3, 4]]))

