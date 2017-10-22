#!/usr/bin/python

class UnionFind:
    
    def __init__(self):
        self.weights = {}
        self.parents = {}

    def __getitem__(self, object):
        # check for unknown object
        if object not in self.parents:
            self.parents[object] = object
            self.weights[object] = 1
            return object

        # find path to the root
        path = [object]
        root = self.parents[object]
        while root != path[-1]:
            path.append(root)
            root = self.parents[root]

        for ancestor in path:
            self.parents[ancestor] = root
        return root

    def __iter__(self):
        return iter(self.parents)

    # Merges the component in the list
    def union(self, objects):
        if type(objects) is not list:
            print "Need list of objects"
            return

        roots = [self[x] for x in objects]
        heaviest = max([(self.weights[root], root) for root in roots])[1]
        for root in roots:
            if root != heaviest:
                self.weights[heaviest] += self.weights[root]
                self.parents[root] = heaviest

    # Returns true if p and q are connected
    def isConnected(self, p, q):
        return self.__getitem__(p) == self.__getitem__(q)


if __name__ == '__main__':
    uf = UnionFind()

    print "Connect 0, 1 and 4"
    uf.union([0, 1, 4])
    print "0 -> 2 =", uf.isConnected(0, 2)

    print "Connect 5 and 2"
    uf.union([5, 1])
    print "0 -> 2 =", uf.isConnected(0, 2)

    print "Connect 5 and 1"
    uf.union([5, 1])
    print "0 -> 2 =", uf.isConnected(0, 2)

