const node1 = ['a', null]
const node2 = ['b', null]
const node3 = ['c', null]

class Node {
  constructor (data, next = null) {
    this.data = data
    this.next = next
  }
}

class LinkedList {
  constructor () {
    this.head = null
    this.tail = null
  }

  insertFirst (data) {
    const node = new Node(data, this.head)
    if (this.tail === null)
      this.tail = node
    this.head = node
  }

  insertLast (data) {
    const node = new Node(data)
    if (this.head === null)
      this.head = node

    if (this.tail !== null && this.tail.next !== null)
      this.tail.next = node

    this.tail =  node
  }

  find (data) {
    let current = this.head
    while (current !== null) {
      if (current.data === data)
        return current
      current = current.next
    }
    return null
  }

  remove (node) {
    let prev = null, current = this.head
    while (current !== null) {
      if (current === node) {
        if (current === this.head)
          this.head = this.head.next
        else if (current === this.tail) {
          this.tail = prev
          prev.next = null
        }
        else
          prev.next = current.next
        break 
      }
      prev = current
      current = current.next
    }
  }

  iterate () {
    let current = this.head
    while (current !== null) {
      console.log(current.data)
      current = current.next
    }
    console.log('-----')
  }
}

// usage
const L = new LinkedList()
L.insertLast('c')
L.insertFirst('b')
L.insertFirst('a')

// a b c
L.iterate()

let node = L.find('a')
L.remove(node)

// b c
L.iterate()
