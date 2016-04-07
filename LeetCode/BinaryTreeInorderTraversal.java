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
    public ArrayList<Integer> inorderTraversal(TreeNode root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<Integer> ans = new ArrayList<Integer>();
        if(root == null) return ans;
        HashSet<TreeNode> visited = new HashSet<TreeNode>();
        Stack<TreeNode> stack = new Stack();
        stack.push(root);
        while(!stack.empty()) {
            TreeNode node = stack.pop();
            if(visited.contains(node))
                ans.add(node.val);
            else {
                visited.add(node);
                if(node.right != null)
                    stack.push(node.right);
                stack.push(node);
                if(node.left != null)
                    stack.push(node.left);
            }
        }
        return ans;
    }
}