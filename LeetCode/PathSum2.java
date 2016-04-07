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
    ArrayList<ArrayList<Integer>> ans;
    public ArrayList<ArrayList<Integer>> pathSum(TreeNode root, int sum) {
        ans = new ArrayList<ArrayList<Integer>>();
        if(root == null) return ans;
        dfs(root, sum, new ArrayList<Integer>());
        return ans;
    }
    public void dfs(TreeNode root, int sum, ArrayList<Integer> path) {
        sum -= root.val;
        path.add(root.val);
        if(root.left == null && root.right == null && sum == 0)
            ans.add(new ArrayList<Integer>(path));
        if(root.left != null)
            dfs(root.left, sum, path);
        if(root.right != null)
            dfs(root.right, sum, path);
        path.remove(path.size() - 1);
    }
}