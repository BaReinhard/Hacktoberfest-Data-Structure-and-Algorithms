def get_command():
    parts = input().strip().split(' ')
    command = int(parts[0])

    if len(parts) == 1:
        return (command, None)
    try:
        arg = int(parts[1])
    except ValueError:
        arg = parts[1]

    return command, arg


class Stack:
    def __init__(self):
        self._l = []

    def __len__(self):
        return len(self._l)

    def push(self, data):
        self._l.append(data)

    def pop(self):
        return self._l.pop()

    def top(self):
        if self._l:
            return self._l[-1]
        return None


class Queue:
    def __init__(self):
        self._head = Stack()
        self._tail = Stack()

    def enqueue(self, data):
        self._tail.push(data)

    def dequeue(self):
        if self._head:
            return self._head.pop()

        return self._tail_to_head().pop()

    def peek(self):
        if self._head:
            return self._head.top()

        return self._tail_to_head().top()

    def _tail_to_head(self):
        while self._tail:
            self._head.push(self._tail.pop())

        return self._head


def main():

    queue = Queue()

    command_no = int(input().strip())
    for _ in range(command_no):
        command, arg = get_command()
        if command == ENQUEUE:
            queue.enqueue(arg)
        elif command == DEQUEUE:
            queue.dequeue()
        elif command == PRINT:
            print(queue.peek())


if __name__ == '__main__':
    main()
