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
    ListNode *partition(ListNode *head, int x) {
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);
        ListNode *p1 = h1, *p2 = h2, *p = head;
        while(p) {
            if(p->val < x)
                p1 = p1->next = p;
            else
                p2 = p2->next = p;
            p = p->next;
        }
        p1->next = h2->next;
        p2->next = NULL;
        ListNode *ans = h1->next;
        delete h1;
        delete h2;
        return ans;
    }
};