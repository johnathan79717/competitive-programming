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
    class ListNodeComparator implements Comparator<ListNode> {
        @Override
        public int compare(ListNode a, ListNode b) {
            return a.val - b.val;
        }
    }
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        if(lists.size() == 0) return null;
        ListNode fake = new ListNode(0);
        ListNode tail = fake;
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(lists.size(), new ListNodeComparator());
        for(int i = 0; i < lists.size(); i++)
            if(lists.get(i) != null)
                pq.add(lists.get(i));
        while(pq.size() > 0) {
            tail = tail.next = pq.poll();
            if(tail.next != null)
                pq.add(tail.next);
        }
        return fake.next;
    }
}