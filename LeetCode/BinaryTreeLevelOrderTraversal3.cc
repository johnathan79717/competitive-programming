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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int> > q;
        vector<int> currList;
        int currLevel = 1;
        q.push(make_pair(root, 1));
        while(!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(node->left != NULL)
                q.push(make_pair(node->left, level+1));
            if(node->right != NULL)
                q.push(make_pair(node->right, level+1));
            if(level > currLevel) {
                ans.push_back(currList);
                currList.clear();
                currLevel = level;
            }
            currList.push_back(node->val);
        }
        ans.push_back(currList);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};