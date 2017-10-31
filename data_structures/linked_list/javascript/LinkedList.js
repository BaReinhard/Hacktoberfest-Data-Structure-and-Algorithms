/**
 * Single Linked list implementation in javascript
 * @author smulyono
 */
/**
 * Node object representation
 */
class Node {
    /**
     * Accept initial value in constructor
     * @param {object} value 
     */
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

/**
 * Single linked list 
 */
class SingleLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    /**
     * Check for condition where head and tail are still null / empty
     * @param {Object} newNode 
     */
    _emptyList(newNode) {
        if (this.head === null && this.tail === null) {
            this.head = newNode;
            this.tail = this.head;
            return true;
        } 
        return false;
    }

    /**
     * Add new value in the end of the list
     * @param {Object} value 
     */
    addLast(value) {
        let newNode = new Node(value);
        if (!this._emptyList(newNode)) {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.size ++;
    }

    /**
     * Add new value in the beginning of list
     * @param {Object} value 
     */
    addFirst(value) {
        let newNode = new Node(value);
        if (!this._emptyList(newNode)) {
            newNode.next = this.head;
            this.head = newNode;
        }
        this.size++;
    }

    /**
     * Adding node in certain position; n index starts at 0
     * @param {Number} n
     * @param {Object} value 
     */
    addAtPos(n, value) {
        if (n >= this.size) {
            throw new Error("Out of bounds exception");
        }
        let newNode = new Node(value);
        if (!this._emptyList(newNode)) {
            let pointer = this.head;
            let counter = 0;
            // move pointer to the `n` position without
            // bypassing the tail position
            while (pointer !== null &&
                    counter < n) {
                pointer = pointer.next;
                counter++;
            }
            if (pointer === null) {
                throw new Error("Out of bounds exception ");
            }
            // we reach in the position
            newNode.next = pointer.next;
            pointer.next = newNode;
            this.size++;
        }
    }

    /**
     * Remove first node (head)
     */
    removeFirst() {
        if (this.head !== null) {
            this.head = this.head.next;
            this.size--;
        }
    }

    /**
     * Remove last node (tail)
     */
    removeLast(){
        if (this.tail !== null && this.head !== null) {
            let pointer = this.head;
            while (pointer.next !== this.tail) {
                pointer = pointer.next;
            }
            pointer.next = null;
            this.tail = pointer;
            this.size--;
        }
    }

    /**
     * List all nodes
     */
    list() {
        let pointer = this.head;
        while (pointer != null ) {
            console.info(pointer.value);
            pointer = pointer.next;
        }
    }
}

export default SingleLinkedList;