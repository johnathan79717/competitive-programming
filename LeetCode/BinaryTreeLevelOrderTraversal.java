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
    class TreeNodeWithLevel extends TreeNode {
        int level;
        TreeNodeWithLevel(TreeNode tn, int l) {
            super(tn.val);
            left = tn.left;
            right = tn.right;
            level = l;
        }
    }
    
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        if(root == null) return ans;
        Queue<TreeNodeWithLevel> q = new LinkedList<TreeNodeWithLevel>();
        ArrayList<Integer> currList = new ArrayList<Integer>();
        int currLevel = 1;
        TreeNodeWithLevel node = new TreeNodeWithLevel(root, 1);
        while(node != null) {
            if(node.left != null)
                q.add(new TreeNodeWithLevel(node.left, node.level+1));
            if(node.right != null)
                q.add(new TreeNodeWithLevel(node.right, node.level+1));
            if(node.level > currLevel) {
                ans.add(currList);
                currList = new ArrayList<Integer>();
                currLevel = node.level;
            }
            currList.add(node.val);
            node = q.poll();
        }
        ans.add(currList);
        return ans;
    }
}