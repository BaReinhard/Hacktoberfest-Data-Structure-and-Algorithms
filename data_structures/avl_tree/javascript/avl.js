var Node = function (value)
{
    this.left = null;
    this.right = null;
    this.value = value;
	this.balance = 0;
};

var AVL = function ()
{
    this._root = null;
    this._size = 0;
    this.get = function (value){
        if (this._root === null) return null;
        return this._get(value, this._root).value;
    };
    this._get = function (value, root){
		if(root === null) 		 return null;
        if (value == root.value) return root;
        if (value < root.value)  return this._get(value, root.left);
        else					 return this._get(value, root.right);
    };
    this.insert = function (value){
        this._root = this._insert(value, this._root);
        this._size++;
        this._root = this.rebalance(this._root, value);
    };
    this._insert = function (value, root){
        if (root === null)				return new Node(value);
        if (value < root.value)     	root.left = this._insert(value, root.left);
        else if (value > root.value)	root.right = this._insert(value, root.right);
        else							this._size--;
        return root;
    }
    this.Height = function (node){
        if (node !== null) return 1 + Math.max( this.Height(node.left), this.Height(node.right) );
        return 0;
    };
    this.rotateLeft = function (n){
        temp = n;
        n = n.right;
        temp.right = n.left;
        n.left = temp;
        return n;
    };
    this.rotateRight = function (n){
        temp = n;
        n = n.left;
        temp.left = n.right;
        n.right = temp;
        return n;
    };
    this.rebalance = function(node, value){
        if(node === null) 				return null;
        if(node.value > value) 			node.left = this.rebalance(node.left, value);
        else if(node.value < value) 	node.right = this.rebalance(node.right, value);
        this.setBalance(node);
        if (node.balance == -2){
            if (this.Height(node.left.left) >= this.Height(node.left.right))
                node = this.rotateRight(node);
            else
                node = this.rotateLeftThenRight(node);
        }
        else if (node.balance == 2){
            if (this.Height(node.right.right) >= this.Height(node.right.left))
                node = this.rotateLeft(node);
            else
                node = this.rotateRightThenLeft(node);
        }
        return node;
    }
    this.rotateLeftThenRight = function(node){
        node.left = this.rotateLeft(node.left);
        node = this.rotateRight(node);
        return node;
    }
    this.rotateRightThenLeft = function(node){
        node.right = this.rotateRight(node.right);
        node = this.rotateLeft(node);
        return node;
    }
    this.setBalance = function(node){
        if(node === null) return null;
        node.balance = this.Height(node.right) - this.Height(node.left);
        return node;
    }
    this.delete = function(value){
        this._root = this._delete(this._root, value);
        this._root = this.rebalance(this._root, value);
        if(this._root === null)return;
    }
    this._delete = function(node, value){
		if (node === null) return null;
    	var cmp;
        if(node.value < value) cmp = -1;
        else if(node.value > value) cmp = 1;
        else cmp = 0;

		if (cmp > 0)		node.left = this._delete (node.left, value);
		else if (cmp < 0)	node.right = this._delete (node.right, value);
		else{
			if (node.right === null) 						return node.left;
			if (node.left === null)  						return node.right;
			if(node.right === null && node.left === null)   return null;
			var temp = this._Min(node.right);
			node.value = temp.value;
			node.right = this._DeleteMin(node.right);
		}
		return node;
	}
    this.Min = function(){
        return this._Min(this._root);
    }
    this._Min = function(r){
        var temp = r;
        while(temp.left !== null)
            temp = temp.left;
        return temp;
    }
    this.DeleteMin = function(){
        this._DeleteMin(this._root);
    }
    this._DeleteMin = function(n){
        if(n.left !== null)
            n.left = this._DeleteMin(n.left);
        else{
            if(n.right !== null) return n.right;
            else				 return null;
        }
        return n;
    }
};
