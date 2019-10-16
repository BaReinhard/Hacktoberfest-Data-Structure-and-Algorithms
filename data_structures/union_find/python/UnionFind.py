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
        
# recursive conncetions to find the connected components. 
def connected(data, i, j):
    return find(data, i) == find(data, j)

n = 10
data = [i for i in range(n)]
connections = [(0, 1), (1, 2), (0, 9), (5, 6), (6, 4), (5, 9)]

# union
for i, j in connections:
    union(data, i, j)

print(data)