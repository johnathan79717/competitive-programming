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
    ListNode *copy(ListNode *l) {
        if(!l)
            return NULL;
        ListNode *ans = new ListNode(l->val);
        ListNode *ptr = ans;
        while(l->next) {
            ptr->next = new ListNode(l->next->val);
            ptr = ptr->next;
            l = l->next;
        }
        return ans;
    }
    
    void carryOver(ListNode *l) {
        if(l->val > 9) {
            int carry = l->val / 10;
            l->val %= 10;
            if(l->next)
                l->next->val += carry;
            else
                l->next = new ListNode(carry);
            carryOver(l->next);
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!l1) return copy(l2);
        if(!l2) return copy(l1);
        ListNode *ans = new ListNode(l1->val + l2->val);
        ans->next = addTwoNumbers(l1->next, l2->next);
        carryOver(ans);
        return ans;
    }
};