class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.root = null;
    this.size = 0;
  }

  /* ---- Functions to insert into Linked List ---- */

  insertAtLast(data) {
    let ptr = this.root;
    this.size++;
    if (!ptr) {
      this.root = new Node(data);
    } else {
      while (ptr.next) {
        ptr = ptr.next;
      }
      ptr.next = new Node(data);
    }
  }

  insertAtFirst(data) {
    let node = new Node(data);
    node.next = this.root;
    this.root = node;
    this.size++;
  }

  insertAtNthPosition(data, n) {
    let node = new Node(data);
    if (n <= 0 || n > this.size + 1) {
      return;
    }
    if (n === 1) {
      insertAtFirst(data);
      return;
    }
    let ptr = this.root;
    n--;
    for (let i = 1; i < n; i++) {
      ptr = ptr.next;
    }
    node.next = ptr.next;
    ptr.next = node;
    this.size++;
  }

  /* ---- Functions to remove from Linked List ---- */

  removeNthNode(n) {
    if (n <= 0 || n > this.getSize()) {
      return;
    }
    if (n == 1) {
      this.removeFirstNode();
      return;
    }
    let ptr = this.root;
    n--;
    for (let i = 1; i < n; i++) {
      ptr = ptr.next;
    }
    ptr.next = ptr.next.next;
  }

  removeFirstNode() {
    if (root === null) {
      return;
    }
    this.root = this.root.next;
    this.size--;
  }

  removeLastNode() {
    if (this.getSize() > 0) {
      if (this.getSize() === 1) {
        this.root = null;
      } else {
        let ptr = this.root;
        while (ptr.next.next) {
          ptr = ptr.next;
        }
        ptr.next = null;
      }
      this.size--;
    }
  }

  /* ---- General Purpose functions ---- */

  printList() {
    let ptr = this.root;
    while (ptr) {
      console.log(`${ptr.data} `);
      ptr = ptr.next;
    }
  }

  getSize() {
    return this.size;
  }
}

/* -----------  USAGE  ------------ */

/*
  let root = new LinkedList();
  
  root.insertAtLast(1);
  root.insertAtLast(2);
  root.insertAtLast(3);
  root.insertAtFirst(5);
  root.insertAtNthPosition(9,2);
  
  root.printList();
  
  root.insertAtNthPosition(55,6);
  root.insertAtNthPosition(77,6);
  
  root.printList();
  */
