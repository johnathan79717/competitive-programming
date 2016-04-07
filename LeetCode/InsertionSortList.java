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
    public ListNode insertionSortList(ListNode head) {
        ListNode fake = new ListNode(0);
        fake.next = head;
        ListNode i = head, prev = fake;
        while(i != null) {
            ListNode p = fake;
            while(p.next.val <= i.val && p != prev)
                p = p.next;
            if(p == prev) {
                prev = prev.next;
                i = i.next;
            } else {
                prev.next = i.next;
                i.next = p.next;
                p.next = i;
                i = prev.next;
            }
        }
        return fake.next;
    }
}