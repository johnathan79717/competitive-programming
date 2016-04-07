class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty()) return 0;
        int prev_min = prices[0];
        int ans = 0;
        for(int p : prices) {
            ans = max(ans, p - prev_min);
            prev_min = min(prev_min, p);
        }
        return ans;
    }
};