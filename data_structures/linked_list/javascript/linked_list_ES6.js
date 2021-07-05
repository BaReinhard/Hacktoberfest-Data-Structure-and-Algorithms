class LinkedList {
  constructor() {
    this._length = 0
    this._head = null
  }

  add(data) {
    const node = {
      data,
      next: null
    }
    let current

    // No items in the list yet
    if (this._head === null) {
      this._head = node
    } else {
      current = this._head
      while (current.next) {
        current = current.next
      }
      current.next = node
    }

    this._length++
  }

  get(index) {
    if (index > -1 && index < this._length) {
      let current = this._head
      let i = 0

      while (i++ < index) {
        current = current.next
      }

      return current.data
    }
    return null
  }

  size() {
    return this._length
  }

  remove(index) {
    if (index > -1 && index < this._length) {
      let current = this._head
      let previous
      let i = 0

      // Remove first item
      if (index === 0) {
        this._head = current.next
      } else {
        while (i++ < index) {
          previous = current
          current = current.next
        }
        previous.next = current.next
      }

      this._length--

      return current.data
    }
    return null
  }

  toArray() {
    const result = []
    let current = this._head

    while (current) {
      result.push(current.data)
      current = current.next
    }
    return result
  }

  toString() {
    return this.toArray().toString()
  }
}
