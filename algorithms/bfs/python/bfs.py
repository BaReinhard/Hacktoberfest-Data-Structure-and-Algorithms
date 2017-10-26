from collections import defaultdict
import time

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def edge(self, init, connect):
        self.graph[init].append(connect)

    def BFS(self, source):
        visited = [False]*(len(self.graph))
        queue=[]

        queue.append(source)
        visited[source]=True

        while queue:

            toprint = queue.pop(0)
            print(toprint,)

            for i in self.graph[toprint]:
                if(visited[i]==False):
                    queue.append(i)
                    visited[i]=True

if __name__ == '__main__':
    newG = Graph()
    print("Enter the connected nodes seperated by a space ")
    print("Type bfs <source_node> to print the BFS.")
    k=input("> ")
    while (k.count('bfs')==0):
        init, connect = map(int, k.split())
        newG.edge(init, connect)
        k=input("> ")

    k=k.split()
    source = int(k[1])
    newG.BFS(source)
