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
        TreeLinkNode leftMost = root;
        while(leftMost != null) {
            TreeLinkNode parent = leftMost;
            TreeLinkNode prev = leftMost.left;
            while(prev == null) {
                if(prev == parent.right) {
                    parent = parent.next;
                    if(parent == null)
                        return;
                    prev = parent.left;
                } else {
                    prev = parent.right;
                }
            }
            
            leftMost = prev;
            TreeLinkNode next = prev;
            while(prev != null) {
                do {
                    if(next == parent.right) {
                        parent = parent.next;
                        if(parent == null) {
                            next = null;
                            break;
                        }
                        next = parent.left;
                    } else {
                        next = parent.right;
                    }
                } while(next == null);
                if(next != null) {
                    prev.next = next;
                    prev = next;
                } else {
                    break;
                }
            }
        }
    }
}