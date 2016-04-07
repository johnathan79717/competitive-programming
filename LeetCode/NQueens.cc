class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> perm(n);
        vector<vector<string> > ans;
        for(int i = 0; i < n; i++)
            perm[i] = i;
        do {
            if(check(perm)) {
                ans.push_back(vector<string>(n, string(n, '.')));
                for(int i = 0; i < n; i++)
                    ans.back()[i][perm[i]] = 'Q';
            }
        } while(next_permutation(perm.begin(), perm.end()));
        return ans;
    }
    
    bool check(const vector<int> &perm) {
        for(int i = 0; i < perm.size(); i++)
            for(int j = 0; j < i; j++)
                if(abs(perm[i] - perm[j]) == i - j)
                    return false;
        return true;
    }
};