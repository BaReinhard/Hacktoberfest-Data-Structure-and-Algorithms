/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
 
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
class Solution {
    public boolean isSymmetric(TreeNode node) {
        if (node==null)
            return true;
        return(symmetricTreeHelper(node.left,node.right));
    }
    
    public boolean symmetricTreeHelper(TreeNode p, TreeNode q)
    {
        if(p==null && q==null)
            return true;
        if( p!=null && q==null || q!=null && p==null || p.val!=q.val)
            return false;
        return (symmetricTreeHelper(p.left,q.right)&&symmetricTreeHelper(p.right,q.left));
    }
}
