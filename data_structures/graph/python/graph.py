class vertex:
    def __init__(self,key):
        self.id = key
        self.connected_to = {}

    def addNeighbor(self,neighbour,weight=0):
        self.connected_to[neighbour] = weight

    def __str__(self):
        return str(self.id) + ' connected_to: ' + str([x.id for x in self.connected_to])

    def getConnections(self):
        return self.connected_to.keys()

    def getId(self):
        return self.id

    def getWeight(self,nbr):
        return self.connected_to[neighbour]



class Graph:
    def __init__(self):
        self.vert_list = {}
        self.num_vertices = 0

    def add_vertex(self,key):
        self.num_vertices = self.num_vertices + 1
        new_vertex = vertex(key)
        self.vert_list[key] = new_vertex
        return new_vertex

    def get_vertex(self,n):
        if n in self.vert_list:
            return self.vert_list[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vert_list

    def add_edge(self,f,t,cost=0):
        if f not in self.vert_list:
            nv = self.add_vertex(f)
        if t not in self.vert_list:
            nv = self.add_vertex(t)
        self.vert_list[f].add_neighbor(self.vert_list[t], cost)

    def get_vertices(self):
        return self.vert_list.keys()

    def __iter__(self):
        return iter(self.vert_list.values())

    def __del__(self):
    	pass
