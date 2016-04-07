/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(root == null) return;
        TreeLinkNode leftMost = root;
        while(leftMost.left != null) {
            TreeLinkNode node = leftMost;
            while(node != null) {
                node.left.next = node.right;
                if(node.next != null)
                    node.right.next = node.next.left;
                node = node.next;
            }
            leftMost = leftMost.left;
        }
    }
}