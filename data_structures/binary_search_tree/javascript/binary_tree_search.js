import { _, BST } from './binary_tree';

// Recursive binary search
BST.prototype.contains = function(value) {
    var doesContain = false;
    function recurse(bst) {
        if (bst.value === value) {
            doesContain = true;
        } else if (bst.left !== undefined && value < bst.value) {
            recurse(bst.left);
        } else if (bst.right !== undefined && value > bst.value) {
            recurse(bst.right);
        }
    }

    recurse(this);
    return doesContain;
};
BST.prototype.binarySearch = function(value) {
    let bst = this;
    let returnVal = null;
    let it = 0;
    function recurse(bst) {
        it++;
        if (bst.value === value) {
            returnVal = { bst, it };
        } else if (bst.left !== undefined && value < bst.value) {
            recurse(bst.left);
        } else if (bst.right !== undefined && value > bst.value) {
            recurse(bst.right);
        }
    }

    recurse(this);
    return returnVal;
};
BST.prototype.binarySearchIterative = function(value) {
    let bst = this;
    let it = 0;
    let found = false;
    while (!found) {
        it++;
        if (bst.value === value) {
            return { bst, it };
        } else if (bst.left !== undefined && value < bst.value) {
            bst = bst.left;
        } else if (bst.right !== undefined && value > bst.value) {
            bst = bst.right;
        } else {
            found = true;
        }
    }

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

_(`Binary Search for ${num}: `, _bst.binarySearchIterative(num));
