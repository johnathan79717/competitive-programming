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
    class Info {
        boolean valid;
        int min;
        int max;
        Info(boolean v, int m, int M) {
            valid = v;
            min = m;
            max = M;
        }
    }
    
    public boolean isValidBST(TreeNode root) {
        return getInfo(root).valid;
    }
    
    public Info getInfo(TreeNode root) {
        if(root == null)
            return new Info(true, Integer.MAX_VALUE, Integer.MIN_VALUE);
        Info left = getInfo(root.left);
        Info right = getInfo(root.right);
        boolean valid = left.valid && right.valid && left.max < root.val && root.val < right.min;
        return new Info(valid, Math.min(left.min, root.val), Math.max(right.max, root.val));
    }
}