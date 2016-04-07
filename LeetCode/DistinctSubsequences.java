public class Solution {
    public int numDistinct(String S, String T) {
        int[][] dp = new int[S.length()+1][T.length()+1];
        for(int i = 0; i <= S.length(); i++)
            dp[i][T.length()] = 1;
        for(int i = S.length() - 1; i >= 0; i--)
            for(int j = T.length() - 1; j >= 0; j--) {
                dp[i][j] = dp[i+1][j];
                if(S.charAt(i) == T.charAt(j))
                    dp[i][j] += dp[i+1][j+1];
            }
        return dp[0][0];
    }
}