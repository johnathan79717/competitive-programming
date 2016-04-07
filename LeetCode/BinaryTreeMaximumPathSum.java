/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int ans = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        maxChildSum(root);
        return ans;
    }
    public int maxChildSum(TreeNode root) {
        if(root == null) return 0;
        int l = maxChildSum(root.left);
        int r = maxChildSum(root.right);
        ans = Math.max(ans, l + r + root.val);
        return Math.max(0, root.val + Math.max(l, r));
    }
}