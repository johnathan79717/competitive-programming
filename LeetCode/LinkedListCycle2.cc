/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p1 = head, *p2 = head;
        do {
            p1 = p1->next;
            if(!p2 || !p2->next)
                return NULL;
            else
                p2 = p2->next->next;
        } while(p1 != p2);
        while(p1 != head) {
            p1 = p1->next;
            head = head->next;
        }
        return p1;
    }
};