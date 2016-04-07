class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        bool occur[256];
        memset(occur, false, sizeof(occur));
        auto left = s.begin(), right = s.begin();
        int ans = 0;
        while(right != s.end()) {
            while(occur[*right])
                occur[*(left++)] = false;
            occur[*(right++)] = true;
            ans = max(ans, right - left);
        }
        return ans;
    }
};