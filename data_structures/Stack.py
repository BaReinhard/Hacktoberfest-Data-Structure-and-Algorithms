class Stack:
    def __init__(self):
        self._a = []

    def push(self, item):
        self._a.append(item)

    def pop(self):
        return self._a.pop()

    def isEmpty(self):
        return len(self._a) == 0

    def __iter__(self):
        return reversed(self._a)

    def __str__(self):
        # return str(list(reversed(self._a)))
        return str(list(iter(self)))

def main():
    stack = Stack()
    stack.push('a')
    stack.push('b')
    stack.push('c')
    stack.pop()
    print(stack)
    if stack:
        print("stack not empty")
    stack.pop()
    stack.pop()
    if stack.isEmpty():
        print("stack empty")

if __name__ == '__main__':
    main()
