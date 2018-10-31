
/**
 * Binary Tree
 * (c) 2014 Ben Lesh <ben@benlesh.com>
 * MIT license
 */

/*
 * A simple Binary Tree implementation in JavaScript
 */


function BinaryTree() {
    var self = this;
    var root;
    
    function traverse(value, fn) {
        var found = root,
            side, parent;
        while(found && found.value !== value) {
            parent = found;
            if(value > found.value) {
                side = 'right';
                found = found.right;    
            } else {
                side = 'left';
                found = found.left;
            }
        }
        return { found: found, parent: parent, side: side };
    }
    
    self.add = function (value, item) {
        if(typeof value === 'undefined') {
            throw new Error('value cannot be undefined');
        }
        
        var node = new BinaryTreeNode(value, item);
        if(!root) {
            root = node;
            return;
        }
        
        var result = traverse(value);
        if(!result.found) {
            result.parent[result.side] = node;
        } else {
            throw new Error('two items of the same value added');
        }
    };

    self.search = function(value) {
        var result = traverse(value);
        return result.found ? result.found.item : null;
    };
    
    self.contains = function(value) {
        return !!self.find(value)
    };
    
    self.root = function (){
        return root;
    };
    
    function BinaryTreeNode(value, item) {
        this.value = value;
        this.item = item;
        this.left = null;
        this.right = null;
    }
};