/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode *& list, int start, int end) {
      if (start > end) return NULL;
      // same as (start+end)/2, avoids overflow
      int mid = start + (end - start) / 2;
      TreeNode *leftChild = sortedListToBST(list, start, mid-1);
      TreeNode *parent = new TreeNode(list->val);
      parent->left = leftChild;
      list = list->next;
      parent->right = sortedListToBST(list, mid+1, end);
      return parent;
    }
     
    TreeNode* sortedListToBST(ListNode *head) {
        int n = 0;
        ListNode *p = head;
        while(p != NULL) {
            n++;
            p = p->next;
        }
        return sortedListToBST(head, 0, n-1);
    }
};