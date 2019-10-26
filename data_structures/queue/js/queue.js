class Queue {
  constructor () {
    this.store = []
  }
  enqueue (data) {
    this.store.push(data)
  }
  dequeue () {
    if (this.store.length === 0)
      throw 'Zero length'
    return this.store.shift()
  }
  front () {
    if (this.store.length === 0)
      throw 'Zero length'
    return this.store[0]
  }
  back () {
    return this.store[this.store.length - 1]
  }
  size () {
    return this.store.length
  }
}

// usage
const q = new Queue()
q.enqueue('a')
q.enqueue('b')
q.enqueue('c')

console.log('-----')
console.log(q.front())
console.log(q.back())
console.log('-----')
console.log(q.dequeue())
console.log(q.dequeue())
