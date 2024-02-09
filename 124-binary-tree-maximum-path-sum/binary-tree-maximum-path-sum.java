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
    int maxi= Integer.MIN_VALUE;
    private int helper(TreeNode root,int sum){
        if(root==null){
            return 0;
        }
        int lsum=Math.max(0,helper(root.left,sum));
        int rsum=Math.max(0,helper(root.right,sum));
        int vl=root.val;
        maxi=Math.max(maxi,lsum+rsum+vl);
        return Math.max(Math.max(lsum+vl,rsum+vl),vl);
    }
    public int maxPathSum(TreeNode root) {
        if(root==null){
            return 0;
        }
        int a=helper(root,0);
        return Math.max(maxi,a);
    }
}