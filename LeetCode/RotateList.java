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
    public ListNode rotateRight(ListNode head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(head == null || n == 0) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode p = dummy;
        for(int i = 0; i < n; i++) {
            p = p.next;
            if(p == null) {
                n %= i;
                break;
            }
        }
        p = dummy;
        for(int i = 0; i < n; i++)
            p = p.next;
        if(p.next == null) return head;
        ListNode q = dummy;
        while(p.next != null) {
            q = q.next;
            p = p.next;
        }
        p.next = dummy.next;
        dummy.next = q.next;
        q.next = null;
        return dummy.next;
    }
}