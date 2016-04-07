/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
public class Solution {
    public ArrayList<TreeNode> generateTrees(int n) {
        return generateTrees(1, n);
    }
    ArrayList<TreeNode> generateTrees(int l, int r) {
        ArrayList<TreeNode> ans = new ArrayList<TreeNode>();
        if(l > r) {
            ans.add(null);
            return ans;
        }
        for(int i = l; i <= r; i++) {
            ArrayList<TreeNode> left = generateTrees(l, i - 1);
            ArrayList<TreeNode> right = generateTrees(i + 1, r);
            for(int j = 0; j < left.size(); j++)
                for(int k = 0; k < right.size(); k++) {
                    TreeNode root = new TreeNode(i);
                    root.left = left.get(j);
                    root.right = right.get(k);
                    ans.add(root);
                }
        }
        return ans;
    }
}