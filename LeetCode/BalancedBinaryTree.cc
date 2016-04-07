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
    bool isBalanced(TreeNode *root) {
        if(root == NULL) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(h(root->left)-h(root->right)) <= 1;
    }
    int h(TreeNode *root) {
        if(root == NULL) return 0;
        return 1 + max(h(root->left), h(root->right));
    }
};