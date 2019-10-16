import { _, BST } from './binary_tree';
// Create Queue Class
let Queue = () => {
    let _data = [];

    return {
        enqueue(val) {
            _data.push(val);
        },
        dequeue() {
            return _data.splice(0, 1)[0];
        },
        isEmpty() {
            return _data.length === 0;
        },
        Top() {
            return _data[0];
        },
    };
};
// Test Queue
// let que = Queue();
// que.enqueue(1);
// que.enqueue(2);
// que.enqueue(3);

// _(que.dequeue());
// _(que.dequeue());

// _(que.dequeue());

BST.prototype.breadthFirstLog = function(callback) {
    let bst = this;
    let queue = Queue();
    let firstRun = true;
    function recurse(bst) {
        callback.call(bst, bst.value);
        if (!queue.isEmpty() || (bst.left !== undefined || bst.right !== undefined) || firstRun) {
            if (firstRun) {
                firstRun = false;
            }
            if (bst.left !== undefined) {
                queue.enqueue(bst.left);
            }

            if (bst.right !== undefined) {
                queue.enqueue(bst.right);
            }
            recurse(queue.dequeue());
        }
    }
    recurse(this);
};
BST.prototype.breadthFirstSearch = function(searchVal) {
    let queue = Queue();
    let firstRun = true;
    let it = 0;
    let returnVal = null;
    function recurse(bst) {
        it++;
        _(bst.value, searchVal);
        if (bst.value === searchVal) {
            // Set Return for BST Node and how many recursive iterations there were
            returnVal = { bst, it };
        } else {
            if (!queue.isEmpty() || (bst.left !== undefined || bst.right !== undefined) || firstRun) {
                if (firstRun) {
                    firstRun = false;
                }
                if (bst.left !== undefined) {
                    queue.enqueue(bst.left);
                }

                if (bst.right !== undefined) {
                    queue.enqueue(bst.right);
                }
                if (!queue.isEmpty()) {
                    recurse(queue.dequeue());
                }
            }
        }
    }
    recurse(this);
    if (returnVal === null) {
        returnVal = { bst: null, it };
    }
    return returnVal;
};
BST.prototype.breadthFirstSearchIterative = function(searchVal) {
    let bst = this;
    let queue = Queue();
    let firstRun = true;
    let it = 0;
    do {
        it++;
        _(bst.value, searchVal);
        if (bst.value === searchVal) {
            // Set Return for BST Node and how many recursive iterations there were
            return { bst, it };
        } else {
            if (!queue.isEmpty() || (bst.left !== undefined || bst.right !== undefined) || firstRun) {
                if (firstRun) {
                    firstRun = false;
                }
                if (bst.left !== undefined) {
                    queue.enqueue(bst.left);
                }

                if (bst.right !== undefined) {
                    queue.enqueue(bst.right);
                }
                bst = queue.dequeue();
            }
        }
    } while (!queue.isEmpty() || bst !== undefined);
    return { BST: null, it };
};

let _bst = BST(5);
_bst.insert(3);
_bst.insert(4);
_bst.insert(1);
_bst.insert(2);
_bst.insert(0);
_bst.insert(8);
_bst.insert(7);
_bst.insert(9);
_bst.insert(6);

let num = 3;
_(`Breadth First Search for ${num}: `, _bst.breadthFirstSearch(num));
