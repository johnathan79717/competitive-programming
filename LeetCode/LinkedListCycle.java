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
    public boolean hasCycle(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode n1 = head, n2 = head;
        while(n2 != null) {
            n1 = n1.next;
            n2 = n2.next;
            if(n2 == null)
                return false;
            else
                n2 = n2.next;
            if(n1 == n2)
                return true;
        }
        return false;
    }
}