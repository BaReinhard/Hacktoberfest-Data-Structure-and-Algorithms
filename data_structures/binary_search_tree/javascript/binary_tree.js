// Cleaner Logging
export const _ = (...vals) => console.log(...vals);

// Create BST Node
export function BST(val) {
    let self = Object.create(BST.prototype);

    // Create Based Properties of BST Node
    self.value = val;
    self.right = undefined;
    self.left = undefined;

    // Insert Function, to properly place value in tree structure

    return self;
}
BST.prototype.insert = function(value) {
    let node = BST(value);
    function recurse(bst) {
        if (bst.value > value && bst.left === undefined) {
            bst.left = node;
        } else if (bst.value > value) {
            recurse(bst.left);
        } else if (bst.value < value && bst.right === undefined) {
            bst.right = node;
        } else if (bst.value < value) {
            recurse(bst.right);
        }
    }

    recurse(this);
};
