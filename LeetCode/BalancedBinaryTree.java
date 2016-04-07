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
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        return isBalanced(root.left) && isBalanced(root.right) && Math.abs(height(root.left) - height(root.right)) <= 1;
    }
    public int height(TreeNode root) {
        if(root == null) return 0;
        else return 1 + Math.max(height(root.left), height(root.right));
    }
    //     bool isBalanced(TreeNode *root) {
    //     if(root == NULL) return true;
    //     return isBalanced(root->left) && isBalanced(root->right) && abs(h(root->left)-h(root->right)) <= 1;
    // }
    // int h(TreeNode *root) {
    //     if(root == NULL) return 0;
    //     return 1 + max(h(root->left), h(root->right));
    // }
}