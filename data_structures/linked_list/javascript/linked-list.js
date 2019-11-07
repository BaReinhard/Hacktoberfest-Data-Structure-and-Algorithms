class Node {
  constructor(value, next = null) {
    this.value = value;
    this.next = next;
  }
}

class LinkedList {
  constructor(value) {
    this.head = new Node(value);
  }

  insert(value) {
    const node = new Node(value);
    node.next = this.head;
    this.head = node;
  }

  printList() {
    let head = this.head;
    let str = '';
    while (head.next != null) {
      str += head.value + '->';
      head = head.next;
    }
    str += head.value;
    console.log(str);
  }
}
