class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ans;
        ans.push_back(0);
        for(int i = 0; i < n; i++)
            for(int j = ans.size() - 1; j >= 0; j--)
                ans.push_back(ans[j] + (1 << i));
        return ans;
    }
};