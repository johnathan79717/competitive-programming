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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode *buildTree(vector<int> &preorder, int a1, int n1, vector<int> &inorder, int a2, int n2) {
        if(n1 == 0)
            return NULL;
        if(n1 == 1)
            return new TreeNode(preorder[a1]);
        TreeNode *root = new TreeNode(preorder[a1]);
        int i;
        for(i = 0; i < n2; i++) {
            if(inorder[a2 + i] == root->val)
                break;
        }
        root->left = buildTree(preorder, a1 + 1, i, inorder, a2, i);
        root->right = buildTree(preorder, a1 + 1 + i, n1 - i - 1, inorder, a2 + i + 1, n2 - i - 1);
        
        return root;
    }
};