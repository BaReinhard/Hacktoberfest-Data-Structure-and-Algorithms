class Obj:
    def __init__(self,val,index):
        self.val = val
        self.index = index

    def __lt__(self,obj):
        return (-self.val,self.index) < (-obj.val,obj.index)

    def __int__(self):
        return self.index

class MinHeap:
    def __init__(self,A = [], n = 0):
        self.heap = []
        self.size = 0
        self.objectLocator = {}
        for obj in A:
            # Locator[Id] -> [object, current index in heap]
            self.objectLocator[int(obj)] = [obj,self.size]
            self.heap.append(obj)
            self.size+=1
            
        self.heapify()

    def __len__(self): # O(1)
        return self.size

    def heapify(self): # O(n)
        start = self.size//2
        while start>0:
            start-=1
            self.shiftDown(start)

    def getTop(self):
        return self.heap[0]
    
    def getLeftChild(self, index): # O(1)
        return 2*index+1

    def getRightChild(self, index): # O(1)
        return 2*index+2

    def getParent(self, index): # O(1)
        return (index-1)//2

    def swap(self, ind1, ind2): # O(1)
        obj1 = self.heap[ind1]
        obj2 = self.heap[ind2]

        self.heap[ind1] = obj2
        self.heap[ind2] = obj1

        self.objectLocator[int(obj1)][1] = ind2
        self.objectLocator[int(obj2)][1] = ind1

        
    def shiftDown(self, index): # O(Height of Index)
        left = self.getLeftChild(index)
        right = self.getRightChild(index)

        mini = index

        if left<self.size and self.heap[left]<self.heap[mini]:
            mini = left

        if right < self.size and self.heap[right]<self.heap[mini]:
            mini = right

        if mini==index:
            return
        else:
            self.swap(index,mini)
            self.shiftDown(mini)

    def shiftUp(self,index): # O(Depth of Index)
        if index==0: 
            return 
        parent = self.getParent(index)
        if self.heap[index]<self.heap[parent]:
            self.swap(index,parent)
            self.shiftUp(parent)

    def push(self,obj): # HeapPush - O(logn)
        self.heap.append(obj)
        index = self.size
        self.objectLocator[int(obj)] = [obj,index]
        self.size+=1
        self.shiftUp(index)

    def pop(self): # HeapPop - O(logn)
        if self.size==0:
            raise IndexError("Pop from empty Heap not allowed")
        lastIndex = self.size-1
        self.swap(0,lastIndex)
        self.size-=1
        self.shiftDown(0)
        obj = self.heap.pop()
        del self.objectLocator[int(obj)]
        return obj

    def changePriority(self,index, newVal = sys.maxsize): # O(logn)
        if index not in self.objectLocator:
            raise IndexError("Task not present in Heap")
        hIndex = self.objectLocator[index][1]
        oldVal = self.heap[hIndex].val
        self.heap[hIndex].val = newVal
        
        if newVal > oldVal:
            self.shiftUp(hIndex) 
        else:
            self.shiftDown(hIndex)



# Solving Leetcode 239. Sliding Window Maximum with this heap data structure (https://leetcode.com/problems/sliding-window-maximum/)
# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         objects = [Obj(j,i) for i,j in enumerate(nums)]
#         heap = MinHeap(objects[:k-1])
#         start = 0
#         for i in range(k-1,len(nums)):
#             heap.push(objects[i])
#             yield(heap.getTop().val)
#             heap.changePriority(start)
#             heap.pop()
#             start+=1
            
