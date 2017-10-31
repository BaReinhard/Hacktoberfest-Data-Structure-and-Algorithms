/**
 * Double Linked list implementation in javascript
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
        this.prev = null;
    }
}

/**
 * Double linked list 
 */
class DoubleLinkedList {
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
            newNode.prev = this.tail;
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
            this.head.prev = newNode;
            this.head = newNode;
        }
    }

    /**
     * Adding node in certain position; n index starts at 0
     * @param {Number} n
     * @param {Object} value 
     */
    addAtPos(n, value) {
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
            newNode.prev = pointer;
            if (pointer.next !== null) {
                pointer.next.prev = newNode;
            } else {
                // if pointer.next -> null then this is tail
                this.tail = newNode;
            }
            pointer.next = newNode;

        }
    }

    /**
     * Remove first node (head)
     */
    removeFirst() {
        if (this.head !== null) {
            this.head = this.head.next;
            this.head.prev = null;
        }
    }

    /**
     * Remove last node (tail)
     */
    removeLast(){
        if (this.tail !== null && this.head !== null) {
            this.tail = this.tail.prev;
            this.tail.next = null;
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

    reverseList() {
        let pointer = this.tail;
        while (pointer != null) {
            console.info(pointer.value);
            pointer = pointer.prev;
        }
    }
}

export default DoubleLinkedList;