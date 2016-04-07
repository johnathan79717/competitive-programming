/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null) return null;
        ListNode p1 = head, p2 = head;
        do {
            p1 = p1.next;
            if(p2 != null)
                p2 = p2.next;
            else
                return null;
            if(p2 != null)
                p2 = p2.next;
            else
                return null;
        } while(p1 != p2);
        while(p1 != head) {
            p1 = p1.next;
            head = head.next;
        }
        return p1;
    }
}