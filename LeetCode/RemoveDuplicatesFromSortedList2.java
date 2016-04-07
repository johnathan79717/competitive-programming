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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null) return null;
        ListNode fake = new ListNode(0);
        fake.next = head;
        ListNode prev = fake, p = prev.next;
        while(p != null) {
            while(p.next != null && p.next.val == prev.next.val)
                p = p.next;
            if(prev.next != p)
                p = prev.next = p.next;
            else {
                prev = p;
                p = p.next;
            }
        }
        return fake.next;
    }
}