class Solution {
public:
    int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<bool> > p(s.size());
        for(int diff = 0; diff < s.size(); diff++) {
            p[diff].resize(s.size() - diff);
            for(int i = 0; i + diff < s.size(); i++) {
                if(diff == 0)
                    p[0][i] = true;
                else if(diff == 1)
                    p[1][i] = (s[i] == s[i+1]);
                else
                    p[diff][i] = (p[diff-2][i+1] && s[i] == s[i+diff]);
            }
        }
        vector<int> dp(s.size(), INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            if(p[i][0]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i-1] + 1;
            for(int j = 1; j < i; j++) {
                if(p[i-j][j]) // if s[j..i] is palindrome
                    dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
        return dp[s.size() - 1];
    }
};