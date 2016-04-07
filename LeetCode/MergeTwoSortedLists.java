/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        ListNode ans;
        if(l1.val <= l2.val) {
            ans = l1;
            ans.next = mergeTwoLists(l1.next, l2);
        } else {
            ans = l2;
            ans.next = mergeTwoLists(l1, l2.next);
        }
        return ans;
    }
}