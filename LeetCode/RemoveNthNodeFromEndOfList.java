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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = head;
        while(n-- > 0)
            p = p.next;
        if(p == null) {
            return head.next;
        }
        ListNode h = head;
        while(p.next != null) {
            h = h.next;
            p = p.next;
        }
        h.next = h.next.next;
        return head;
    }
}