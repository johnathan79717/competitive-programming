public class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length == 0) return 0;
        int prev_min = prices[0], ans = 0;
        for(int p : prices) {
            ans = Math.max(ans, p - prev_min);
            prev_min = Math.min(prev_min, p);
        }
        return ans;
    }
}