/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
Example 1:
Input:     1         1
          / \       / \
         2   3     2   3
        [1,2,3],   [1,2,3]
Output: true
Example 2:
Input:     1         1
          /           \
         2             2
        [1,2],     [1,null,2]
Output: false
Example 3:
Input:     1         1
          / \       / \
         2   1     1   2
        [1,2,1],   [1,1,2]
Output: false
Link : https://leetcode.com/problems/same-tree/
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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return(sameTreeHelper(p,q));
    }
    
    public boolean sameTreeHelper(TreeNode p, TreeNode q)
    {
        if(p==null && q==null)
            return true;
        if( p!=null && q==null || q!=null && p==null || p.val!=q.val)
            return false;
        return (sameTreeHelper(p.left,q.left)&&sameTreeHelper(p.right,q.right));
    }
}
