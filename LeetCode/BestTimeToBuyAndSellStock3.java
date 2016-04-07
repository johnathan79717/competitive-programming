public class Solution {
    public int maxProfit(int[] prices) {
        int[] from = new int[prices.length];
        int[] until = new int[prices.length];
        if(prices.length == 0) return 0;
        int prev_min = prices[0];
        until[0] = 0;
        for(int i = 1; i < prices.length; i++) {
            until[i] = Math.max(until[i-1], prices[i] - prev_min);
            prev_min = Math.min(prev_min, prices[i]);
        }
        from[prices.length - 1] = 0;
        int prev_max = prices[prices.length - 1];
        for(int i = prices.length - 2; i >= 0; i--) {
            from[i] = Math.max(from[i+1], prev_max - prices[i]);
            prev_max = Math.max(prev_max, prices[i]);
        }
        int ans = Math.max(from[0], until[prices.length - 1]);
        for(int i = 1; i < prices.length - 1; i++)
            ans = Math.max(until[i]+from[i], ans);
        return ans;        
    }
}