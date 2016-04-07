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
    public boolean isSymmetric(TreeNode root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == null) return true;
        // Recursive Solution
        // return isReflection(root.left, root.right);
        Stack<TreeNode> stackLeft = new Stack<TreeNode>();
        Stack<TreeNode> stackRight = new Stack<TreeNode>();
        stackLeft.push(root.left);
        stackRight.push(root.right);
        while(!stackLeft.empty() && !stackRight.empty()) {
            TreeNode nodeLeft = stackLeft.pop();
            TreeNode nodeRight = stackRight.pop();
            if(nodeLeft == null && nodeRight == null)
                continue;
            if(nodeLeft == null || nodeRight == null)
                return false;
            if(nodeLeft.val != nodeRight.val)
                return false;
            stackLeft.push(nodeLeft.right);
            stackLeft.push(nodeLeft.left);
            stackRight.push(nodeRight.left);
            stackRight.push(nodeRight.right);
        }
        return stackLeft.empty() && stackRight.empty();
    }
    public boolean isReflection(TreeNode p, TreeNode q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(p == null)
            return q == null;
        if(q == null)
            return false;
        return p.val == q.val && isReflection(p.left, q.right) && isReflection(p.right, q.left);
    }
}