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
    public ListNode partition(ListNode head, int x) {
        ListNode h1 = new ListNode(0), h2 = new ListNode(0), p1 = h1, p2 = h2;
        ListNode p = head;
        while(p != null) {
            if(p.val < x)
                p1 = p1.next = p;
            else
                p2 = p2.next = p;
            p = p.next;
        }
        p1.next = h2.next;
        p2.next = null;
        return h1.next;
    }
}