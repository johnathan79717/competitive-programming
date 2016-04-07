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
    int ans;
    public int sumNumbers(TreeNode root) {
        ans = 0;
        if(root == null) return 0;
        dfs(root, 0);
        return ans;
    }
    public void dfs(TreeNode root, int sum) {
        sum = sum * 10 + root.val;
        if(root.left == null && root.right == null)
            ans += sum;
        if(root.left != null)
            dfs(root.left, sum);
        if(root.right != null)
            dfs(root.right, sum);
    }
}