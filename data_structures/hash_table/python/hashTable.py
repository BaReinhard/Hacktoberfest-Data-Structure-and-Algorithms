class HashTable:
    def __init__(self):
        self.size = 13  # hash table with size of 13 to be consistent with cpp code
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def hashfunction(self, key, size): # remainder used to define slots
        return key % size

    def rehash(self, oldhash, size): # just a simple linear probing function for rehashing
        return ( oldhash + 1 ) % size

    def put(self, key, data):
        hash_val = self.hashfunction(key, len(self.slots))

        if self.slots[hash_val] == None:
            self.slots[hash_val] = key
            self.data[hash_val] = data
        else:
            if self.slots[hash_val] == key:
                self.data[hash_val] = data
            else:
                nextslot = self.rehash(hash_val,len(self.slots))
                while self.slots[nextslot] != None and self.slots[nextslot] != key:
                    nextslot = self.rehash(nextslot,len(self.slots))

                if self.slots[nextslot] == None:
                    self.slots[nextslot]=key
                    self.data[nextslot]=data
                else:
                    self.data[nextslot] = data

    def get(self,key):
        startslot = self.hashfunction(key,len(self.slots))

        data = None
        stop = False
        found = False
        position = startslot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == key:
                found = True
                data = self.data[position]
            else:
                position=self.rehash(position,len(self.slots))
                if position == startslot:
                    stop = True
        return data

    def __getitem__(self,key):
        return self.get(key)

    def __setitem__(self,key,data):
        self.put(key,data)

        
