class Solution {
public:
    int totalNQueens(int n) {
        vector<int> perm(n);
        int ans;
        for(int i = 0; i < n; i++)
            perm[i] = i;
        do {
            if(check(perm)) {
                ans++;
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