class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i+1] += dp[j] * dp[i-j];
            }
        }
        return dp[n];
    }
};