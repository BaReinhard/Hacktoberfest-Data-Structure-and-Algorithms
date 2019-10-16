class hashTable:
    def __init__(self):
        self.size = 13  # hash table with size of 13 to be consistent with cpp code
        self.slots = [None] * self.size
        self.data = [None] * self.size

    def hashfunction(self, key, size): # remainder used to define slots
        return key % size

    def rehash(self, oldhash, size): # just a simple linear probing function for rehashing
        return ( oldhash + 1 ) % size

    def insert(self, key, data):
        hash_val = self.hashfunction(key, len(self.slots))

        if self.slots[hash_val] == None:
            self.slots[hash_val] = key
            self.data[hash_val] = data
        else:
            new_slot = self.rehash(hash_val,len(self.slots))
            while self.slots[new_slot] != None and self.slots[new_slot] != key:
                new_slot = self.rehash(new_slot,len(self.slots))

            if self.slots[new_slot] == None:
                self.slots[new_slot] = key
                self.data[new_slot] = data

    def get(self, key):
        first_slot = self.hashfunction(key, len(self.slots))

        data = None
        stop = False
        found = False
        position = first_slot
        while self.slots[position] != None and not found and not stop:
            if self.slots[position] == key:
                found = True
                data = self.data[position]
            else:
                position=self.rehash(position,len(self.slots))
                if position == first_slot:
                    stop = True
        return data

    def __getitem__(self,key):
        return self.get(key)

    def __setitem__(self,key,data):
        self.insert(key,data)

        
