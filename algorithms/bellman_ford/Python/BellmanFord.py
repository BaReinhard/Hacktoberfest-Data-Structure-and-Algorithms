#Bellman-Ford Algorithm

#Author: Samhita Varambally B
#Date: 26 October 2017

# Node() and LinkedList() classes are present to form the adjacency list from the input graph.
#The adjacency list has n nodes, which are present as an array of objects of the LinkedList class.

#Each of the n nodes has a linked list associated with it, the linked list carries information about  
#the directed nodes and their respective weights, which are connected to a node in n.
class Node():
	def __init__(self, weight = None, name = None, next = None, head = None):
		self.weight = weight
		self.next = next
		self.name = name

class LinkedList():
	def __init__(self,Lname = None, head = None):
		self.Lname = Lname
		self.head = None

	def insert(self, newname, newweight):
		newNode = Node()
		newNode.weight = newweight
		newNode.name = newname
		newNode.next = self.head
		self.head = newNode

	def setDist(self,i):
		current = self.head
		while current != None:
			x = int(current.name)
			if dist[x] == None and dist[i] != None:
				dist[x] = int(current.weight) + dist[i]
			elif dist[i] == None:
				current = current.next
				continue
			elif dist[x] > int(current.weight) + dist[i]:
				dist[x] = int(current.weight) + dist[i]
			current = current.next
			
G = []
dist = []

#Function which reads input from a file and stores as an adjacency list
#Comment below code while using function user_input_nodes(G,dist)
def input_from_file(G,dist):
	f= open("inputBellman1.txt","r")
	data = f.readlines()

	n=0
	for line in data:
		words = line.split()
		G.append(LinkedList(words[0]))
		dist.append(None)
		for i in words[1:]:
			connectednode = i.split('(')
			connectedweight = connectednode[1].split(')')
			G[n].insert(connectednode[0],connectedweight[0])
		n= n+1

	f.close()
	return n

n = input_from_file(G,dist)

#Function which allows user to directly input the nodes and directed adjacent nodes along with edge weights
#Uncomment below code to use this feature.
'''def user_input_nodes(G,dist):
	n=0
	while True:
		nodename = raw_input("Enter name of Node: \n")
		G.append(LinkedList(nodename))
		dist.append(None)

		while True:
			term = raw_input("If nodes are directed, type 'y' \n")
			if term !="y":
				break
			connectednode = raw_input("Enter name of adjacent directed node: \n")
			connectedweight = raw_input("Enter weight of adjacent connected node: \n")
			G[n].insert(connectednode,connectedweight)
		
		n = n+1
		terminate = raw_input("If more nodes are present, type 'y' \n")
		if terminate != "y":
			break
	return n

n = user_input_nodes(G,dist)
'''

dist[0] = 0
for j in range(n-1):
	for i in range(n): 
		G[i].setDist(i)

print "Node			  Shortest Path"
for i in range(n):
	print " ",i,"				",dist[i],"\n"


