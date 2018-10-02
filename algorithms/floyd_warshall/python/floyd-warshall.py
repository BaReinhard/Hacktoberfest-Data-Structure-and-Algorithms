# Author: Parth Doshi
# Github ID: arsenal-2004

# This program is a Python 3.5 implementation of the Floyd-Warshall Shortest Path algorithm.

# Defining a value to be used as the distance between nodes without any direct edges
INF = 99999

# Assuming graph to be a square matrix
# In Python, that is represented as a list of lists.
def shortestPath(graph):
	
	# The number of vertices in the graph
	num_v = len(graph)

	# Making a copy of the graph to be used as the result variable
	dist = graph[:]

	for i in range(num_v):
		# Selecting a source vertex
		for j in range(num_v):
			# Selecting a destination vertex
			for k in range(num_v):
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k])

	return dist


def printSolution(dist): 
	for i in range(len(dist)):
		for j in range(len(dist)):
			print("{0:7d}".format(dist[i][j]), end="")
		print()

# Driver program to test the above program 
# Let us create the following weighted graph 
""" 
            10 
       (0)------->(3) 
        |         /|\
      5 |          | 
        |          | 1 
       \|/         | 
       (1)------->(2) 
            3           """

graph = [[0,5,INF,10], 
             [INF,0,3,INF], 
             [INF, INF, 0,   1], 
             [INF, INF, INF, 0] 
        ] 
# Print the solution 
dist = shortestPath(graph)	
printSolution(dist)	
