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
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(head == null) return head;
        ListNode first = head, p = head.next;
        while(p != null) {
            if(p.val != first.val) {
                first.next = p;
                first = p;
            }
            p = p.next;
        }
        first.next = p;
        return head;
    }
}