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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode before = dummy;
        while(true) {
            ListNode p = before;
            for(int i = 0; i < k; i++) {
                p = p.next;
                if(p == null)
                    return dummy.next;
            }
            ListNode tail = p.next;
            p = before.next;
            for(int i = 0; i < k; i++) {
                ListNode after = p.next;
                p.next = tail;
                tail = p;
                p = after;
            }
            ListNode temp = before.next;
            before.next = tail;
            before = temp;
        }
    }
}