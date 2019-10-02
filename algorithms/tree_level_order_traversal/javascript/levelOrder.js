/*
TreeNode {
  val: any;
  left: TreeNode;
  right: TreeNode;
}
*/
function levelOrderTraversal(treeRoot, callback) {
  if (!treeRoot) return;

  const queue = [];
  queue.push(treeRoot);

  while (queue.length) {
    const front = queue.shift();
    callback(front.val);

    front.left && queue.push(front.left);
    front.right && queue.push(front.right);
  }
}
