

#%%
""" def recursiveDfs(graph, start, path=[]):
    path = path+[start]
    for node in graph[start]:
        if not node in path:
            path=recursiveDfs(graph, node, path)
    return path
 """

#%%
def iterative_bfs(graph, start, path=[]):
    q = [start]
    while q:
        v = q.pop(0)
        if not v in path:
            path = path + [v]
            q = q + graph[v]
    return path

#%%
graph = {
    'A':['B', 'D', 'C'],
    'B':['E'],
    'C':['E'],
    'D':['E'],
    'E':['A']
}

#%%
print('recursive dfs :', iterative_bfs(graph, 'A'))



#%%
