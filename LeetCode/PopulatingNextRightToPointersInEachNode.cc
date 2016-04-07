/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return;
        connect(root->left);
        TreeLinkNode *l = root->left, *r = root->right;
        while(l) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        connect(root->right);        
    }
};