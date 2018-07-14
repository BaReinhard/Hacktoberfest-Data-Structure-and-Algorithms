# Define queue class
class Queue:

    def __init__(self):
        self.q_List = []

    def is_empty(self):
        return self.q_List == []

    def enqueue(self, item):
        self.q_List.append(item)

    def dequeue(self):
        if not self.is_empty():
            return self.q_List.pop(0)


# Define vertex class
class Vertex:

    def __init__(self, data):

        self.data = data    # data in vertex
        # color variable for finding the visits
        # 0 - white -> not visited
        # 1 - gray  -> visiting
        # 2 - black -> visited
        self.color = 0  # initialize as white
        self.to = []    # adjacency vertices list


# Define graph class
class Graph:

    def __init__(self, v_num):  # v_num = number of vertices
        self.v_List = []
        for i in range(v_num):
            new_vertex = Vertex(i)
            self.v_List.append(new_vertex)

    def add_edge(self, parent_vertex, child_vertex):
        self.v_List[parent_vertex].to.append(self.v_List[child_vertex])

    # Breath First Search
    def BFS(self, starting_vertex):

        queue = Queue()     # initialize an empty queue
        s = self.v_List[starting_vertex]
        s.color = 1     # current visiting vertex
        queue.enqueue(s)

        while not queue.is_empty():
            u = queue.dequeue()
            for v in u.to:
                if v.color == 0:
                    v.color = 1
                    queue.enqueue(v)
            u.color = 2
            print(u.data)


g = Graph(4)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(2, 0)
g.add_edge(2, 3)
g.add_edge(3, 3)

g.BFS(3)
