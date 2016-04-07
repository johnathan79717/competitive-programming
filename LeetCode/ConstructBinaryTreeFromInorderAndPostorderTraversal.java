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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, postorder, 0, 0, inorder.length);
    }
    public TreeNode buildTree(int[] inorder, int[] postorder, int i, int p, int n) {
        if(n == 0) return null;
        for(int j = i; j < i + n; j++) {
            if(inorder[j] == postorder[p + n - 1]) {
                TreeNode root = new TreeNode(inorder[j]);
                root.left = buildTree(inorder, postorder, i, p, j - i);
                root.right = buildTree(inorder, postorder, j + 1, p + j - i, n - j + i - 1);
                return root;
            }
        }
        return null;
    }
}