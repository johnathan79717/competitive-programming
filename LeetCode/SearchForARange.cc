class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        auto p = equal_range(A, A+n, target);
        vector<int> ans = { p.first - A, p.second - A };
        if(ans[0] == ans[1])
            ans[0] = ans[1] = -1;
        else
            ans[1]--;
        return ans;
    }
};