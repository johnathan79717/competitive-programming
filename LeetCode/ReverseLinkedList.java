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
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m >= n) return head;
        ListNode fake = new ListNode(0);
        fake.next = head;
        ListNode before = fake;
        for(int i = 0; i < m - 1; i++)
            before = before.next;
        ListNode tail = null;
        ListNode p = before.next;
        for(int i = m; i <= n; i++) {
            ListNode after = p.next;
            p.next = tail;
            tail = p;
            p = after;
        }
        before.next = tail;
        while(tail.next != null) tail = tail.next;
        tail.next = p;
        return fake.next;
    }
}