#Articulation Points Algorithm
#Algorithm to find vertex with breaks graph to maximum components
#Applications: Find weak point in network, find critical server in a system
#Algorithm: 
#	set time to 0
#	pass initial vertex, adjacency matrix, discovery array (initialized to 0), back edge array (initialized to infinity), 
#	... articulation point array (initialized to False), visited array (initialized to False), parent array (initialized to NIL), 
#	... time and number of nodes to a recursive DFS function
#	for initial vertex: set visited as True, set discovery = time and back edge = time
#	start a counter for components of root node
#	traverse through the adjacency matrix and find the adjacent vertices
#		if the vertex is not visited
#			increment the component counter
#			update parent of child node
#			recursively call DFS function for child node with time+1
#			update back edge of vertex to minimum of back edge of vertex or back edge of child node
#			if root node and component count > 1 then update articulation point of root node to true
#			if not root node and back edge of child node is equal to or not lesser that current node then update articulation point of node to True
#		else if parent of the current vertex is not equal to the child node then update back edge to minimum of back edge of current vertex or discovery of i
#an extra list - output, to maintain bridges found during traversal
import math

def dfsVertexBridge(adj, disc, backEdge, visited, parent, articulationPt, vertex, time, nodes, output):
	visited[vertex] = True
	disc[vertex] = backEdge[vertex] = time
	components = 0
	for i in range(nodes):
		if adj[vertex][i]:
			if not visited[i]:
				components += 1
				parent[i] = vertex
				dfsVertexBridge(adj, disc, backEdge, visited, parent, articulationPt, i, time+1, nodes, output)
				backEdge[vertex] = min(backEdge[vertex], backEdge[i])
				if not parent[vertex] and components > 1:
					articulationPt[vertex] = True
				if parent[vertex] is not None and backEdge[i] >= disc[vertex]:
					articulationPt[vertex] = True
				if backEdge[i] > disc[vertex]:
					if vertex < i:
						output.insert(0, [vertex, i])
					else:
						output.insert(0, [i, vertex])
			elif parent[vertex] != i:
				backEdge[vertex] = min(backEdge[vertex], disc[i])
				
	

nodes, edges = list(map(int, input().strip().split()))			
adj = [([False] * nodes) for j in range(nodes)]
for i in range(edges):
	u, v = list(map(int, input().strip().split()))
	adj[u][v] = adj[v][u] = True
#print (adj)

time = 0
disc = [0] * nodes
backEdge = [math.inf] * nodes
visited = [False] * nodes
parent = [None] * nodes
articulationPt = [False] * nodes
output = []
dfsVertexBridge(adj, disc, backEdge, visited, parent, articulationPt, 0, 1, nodes, output)
print (articulationPt.count(True))
for i in range(nodes):
	if articulationPt[i]:
		print (i, end=" ")
print ()
print (len(output))
for i in sorted(output):
	print (str(i[0]) + " " + str(i[1]))