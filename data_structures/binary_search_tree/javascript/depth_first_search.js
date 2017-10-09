import { _, BST } from './binary_tree';

// Create Stack Class
let Stack = () => {
    let _data = [];
    return {
        Top() {
            return _data[_data.length - 1];
        },
        Pop() {
            return _data.splice(_data.length - 1, 1)[0];
        },
        Push(val) {
            _data.push(val);
        },
        isEmpty() {
            return _data.length === 0;
        },
    };
};
// Test Stack Class
// let stack = Stack();
// stack.Push(1);
// stack.Push(2);
// stack.Push(3);
// stack.Push(4);
// _(stack.Pop());
// _(stack.Pop());
// _(stack.Pop());
// _(stack.Pop());

BST.prototype.depthFirstLog = function(callback) {
    function recurse(bst) {
        callback.call(bst, bst.value);
        if (bst.left !== undefined) {
            recurse(bst.left);
        }
        if (bst.right !== undefined) {
            recurse(bst.right);
        }
    }

    recurse(this);
};
BST.prototype.depthFirstSearch = function(searchVal) {
    let stack = Stack();
    let it = 0;
    let returnVal = null;
    function recurse(bst) {
        it++;
        if (bst.value === searchVal) {
            returnVal = { bst, it };
        } else {
            if (bst.left !== undefined) {
                stack.Push(bst.left);
            }
            if (bst.right !== undefined) {
                stack.Push(bst.right);
            }
            if (!stack.isEmpty()) {
                recurse(stack.Pop());
            }
        }
    }

    recurse(this);
    if (returnVal === null) {
        returnVal = { bst: null, it };
    }
    return returnVal;
};
BST.prototype.depthFirstSearchIterative = function(searchVal) {
    let bst = this;
    let stack = Stack();
    let it = 0;
    do {
        it++;
        if (bst.value === searchVal) {
            return { bst, it };
        } else {
            if (bst.left !== undefined) {
                stack.Push(bst.left);
            }
            if (bst.right !== undefined) {
                stack.Push(bst.right);
            }
            bst = stack.Pop();
        }
    } while (!stack.isEmpty() || bst !== undefined);

    return { bst: null, it };
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
_(`Depth First Search for ${num}: `, _bst.depthFirstSearch(num));
