class BSTNode {
  constructor(val) {
    this.val = val;
    this.left = null;
    this.right = null;
  }

  insertLeft(val) {
    if (this.left) {
      throw new Error('Left child exists!');
    }

    this.left = new BSTNode(val);
  }

  insertRight(val) {
    if (this.right) {
      throw new Error('Right child exists!');
    }

    this.right = new BSTNode(val);
  }

  removeLeft() {
    if (!this.left) {
      throw new Error('Left child does not exists!');
    }

    this.left = null;
  }

  removeRight() {
    if (!this.right) {
      throw new Error('Right child does not exists!');
    }

    this.right = null;
  }
}

class BST {
  constructor(rooVal) {
    this.root = new BSTNode(rooVal);
  }
}
