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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        while(true) {
            TreeNode *p = q.front().first;
            int n = q.front().second;
            q.pop();
            if(!p->left && !p->right)
                return n;
            if(p->left)
                q.push(make_pair(p->left, n+1));
            if(p->right)
                q.push(make_pair(p->right, n+1));
        }
    }
};