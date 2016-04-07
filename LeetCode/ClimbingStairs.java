public class Solution {
    public int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int prev1 = 0, prev2 = 1, ans = 0;
        for(int i = 0; i < n; i++) {
            ans = prev1 + prev2;
            prev1 = prev2;
            prev2 = ans;
        }
        return ans;
    }
}