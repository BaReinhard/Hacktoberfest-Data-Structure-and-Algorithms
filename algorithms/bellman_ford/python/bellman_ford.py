class Edge:
	def __init__(self, src, dest, weight):
		self.src = src
		self.dest = dest
		self.weight = weight
class Graph:
	def __init__(self, vertices):
		self.vertices = vertices
		self.edges = []

	def addEdges(self, src, dest, weight):
		if (( src < 0) or (dest < 0) or (src > V-1) or (dest > V-1)):
			return False
		
		self.edges.append(Edge(src, dest, weight))
 		return True

 	def bellmanFord(self, src):
 		if((src < 0) or (src > self.vertices-1)):
 			print("Invalid Start Point")
 			return
 		
 		distance = [float('inf')]*self.vertices
 		distance[src] = 0
 		
 		for i in range(0,self.vertices-1):
 			for j in self.edges:	
 				u = j.src
 				v = j.dest
 				weight = j.weight
 				
 				if(distance[u]+weight < distance[v]):
 					distance[v] = distance[u] + weight

 		for i in self.edges:
 			u = i.src
 			v = i.dest
 			weight = i.weight
 				
 			if(distance[u]+weight < distance[v]):
 				print("NEGATIVE CYCLE PRESENT")
 				return
 		self.printDistance(distance,src)

 	def printDistance(self,distance,src):
 		print("Distance to Vertex:"+str(src))
 		for i in range(len(distance)):
 			print("Distance from node:"+str(i)+"="+str(distance[i]))

if(__name__ == '__main__'):
	V = 5
	graph = Graph(V)
	graph.addEdges(0, 1, -1)
	graph.addEdges(0, 2, 4)
	graph.addEdges(1, 2, 3)
	graph.addEdges(1, 3, 2)
	graph.addEdges(1, 4, 2)
	graph.addEdges(3, 2, 5)
	graph.addEdges(3, 1, 1)
	graph.addEdges(4, 3, -3)
	graph.bellmanFord(1)

 		