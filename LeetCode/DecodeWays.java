public class Solution {
    public int numDecodings(String s) {
        if(s.length() == 0) return 0;
        int[] dp = new int[1 + s.length()];
        dp[s.length()] = 1;
        if(s.charAt(s.length()-1) != '0')
            dp[s.length() - 1] = 1;
            
        for(int i = s.length() - 2; i >= 0; i--) {
            if(s.charAt(i) != '0') {
                dp[i] += dp[i+1];
                if(s.charAt(i) == '1' || s.charAt(i) == '2' && s.charAt(i+1) <= '6')
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
}