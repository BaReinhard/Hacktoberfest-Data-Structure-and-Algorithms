class Stack:
    def __init__(self):
        self.items = [] #Creates a stack and calls it items
    def push(self, item):
        self.items.append(item) #Adds new item to end of the stack
    def pop(self):
        return self.items.pop() #Returns top item of the stack && removes it from stack
    def peek(self):
       # return self.items[:-1] 
       temp = self.items.copy()
       return temp.pop() #Returns last item of the stack using splicing
    def size(self):
        return len(self.items) #Uses len method to return the length of a stack
    def isEmpty(self):
        return self.items == [] #True if empty, false if not
    def displayStack(self):
    	for i in reversed(self.items):
		    print(i) #Initalizing a stack object and just messing around...
s = Stack()
s.push(21)
s.push("python")
s.push("O(1)")
s.push("1984")
print(s.size())
popped_item = s.pop()
print(popped_item)
print(s.peek())
print("\nStack contents")
s.displayStack()
print("\n")

def revstring(mystr):
    s = Stack()
    revStr = ""
    for i in mystr:
        s.push(i)
    while not s.isEmpty():
        revStr += str(s.pop())
    return revStr

print(revstring("this string should be reversed"))

def convert2binary(num):
    st = Stack()
    while num > 0:
        newnum = num % 2
        st.push(newnum)
        num = num // 2

    #Now get the binary number
    binary = ""
    while not st.isEmpty():
        binary += str(st.pop())
    return binary


print(convert2binary(42))
print(convert2binary(8))
print(convert2binary(21))


