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
    // public TreeNode sortedArrayToBST(int[] num) {
    //     if(num.length == 0)
    //         return null;
    //     TreeNode root = new TreeNode(num[num.length / 2]);
    //     root.left = sortedArrayToBST(Arrays.copyOf(num, num.length / 2));
    //     root.right = sortedArrayToBST(Arrays.copyOfRange(num, num.length / 2 + 1, num.length));
    //     return root;
    // }
    public TreeNode sortedArrayToBST(int[] num) {
        return sortedArrayToBST(num, 0, num.length);
    }
    public TreeNode sortedArrayToBST(int[] num, int begin, int end) {
        if(begin >= end) return null;
        TreeNode root = new TreeNode(num[(begin+end)/2]);
        root.left = sortedArrayToBST(num, begin, (begin+end)/2);
        root.right = sortedArrayToBST(num, (begin+end)/2+1, end);
        return root;
    }
}