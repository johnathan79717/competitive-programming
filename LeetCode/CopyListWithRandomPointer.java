/**
 * Definition for singly-linked list with a random pointer.
 * class RandomListNode {
 *     int label;
 *     RandomListNode next, random;
 *     RandomListNode(int x) { this.label = x; }
 * };
 */
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        if(head == null) return null;
        RandomListNode ans = new RandomListNode(head.label);
        HashMap<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();
        RandomListNode p1 = ans, p2 = head;
        map.put(head, ans);
        while(p2.next != null) {
            p2 = p2.next;
            p1 = p1.next = new RandomListNode(p2.label);
            map.put(p2, p1);
        }
        p1 = ans; p2 = head;
        while(p2 != null) {
            p1.random = map.get(p2.random);
            p1 = p1.next;
            p2 = p2.next;
        }
        return ans;
    }
}