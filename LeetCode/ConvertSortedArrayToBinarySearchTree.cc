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
    // TreeNode *sortedArrayToBST(vector<int> &num) {
    //     if(num.size() == 0) return NULL;
    //     TreeNode *root = new TreeNode(num[num.size() / 2]);
    //     vector<int> left(num.begin(), num.begin() + num.size() / 2);
    //     root->left = sortedArrayToBST(left);
    //     vector<int> right(num.begin() + num.size() / 2 + 1, num.end());
    //     root->right = sortedArrayToBST(right);
    //     return root;
    // }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
    }
    TreeNode *sortedArrayToBST(vector<int> &num, int l, int r) {
        if(l >= r) return NULL;
        TreeNode *root = new TreeNode(num[(l+r)/2]);
        root->left = sortedArrayToBST(num, l, (l+r)/2);
        root->right = sortedArrayToBST(num, (l+r)/2+1, r);
        return root;
    }
};