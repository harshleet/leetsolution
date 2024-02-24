/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxi=Integer.MIN_VALUE;
    int helper(TreeNode root){
        if(root==null){
            return 0;
        }
        int lbs=helper(root.left);
        int rbs=helper(root.right);
        maxi=Math.max(maxi, lbs+root.val+rbs);

        return Math.max(0,Math.max(lbs+root.val,rbs+root.val));

    }
    public int maxPathSum(TreeNode root) {
        if(root==null){
            return 0;
        }
        helper(root);
        return maxi;
    }
}