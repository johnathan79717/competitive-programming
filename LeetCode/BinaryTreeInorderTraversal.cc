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
    TreeNode *p;
    stack<TreeNode*> path;
    void goLeft() {
        path.push(p);
        p = p->left;
    }
    void goRight() {
        path.push(p);
        p = p->right;
    }
    void goUp() {
        p = path.top();
        path.pop();
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        p = root;
        while(!path.empty()) path.pop();
        if(!p) {
            return ans;
        }
        while(p->left) {
            goLeft();
        }

        do {
            ans.push_back(p->val);
        } while(next());
        return ans;
    }
    
    bool next() {
        if(p->right) {
            goRight();
            while(p->left) {
                goLeft();
            }
            return true;
        } else {
            while(!path.empty() && p == path.top()->right) {
                goUp();
            }
            if(path.empty()) {
                return false;
            } else {
                goUp();
                return true;
            }
        }
    }
};