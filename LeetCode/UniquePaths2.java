public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int[][] dp = new int[obstacleGrid.length][obstacleGrid[0].length];
        if(obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        for(int i = 1; i < dp.length; i++)
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        for(int j = 1; j < dp[0].length; j++)
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        for(int i = 1; i < dp.length; i++) {
            for(int j = 1; j < dp[0].length; j++) {
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[dp.length-1][dp[0].length-1];
    }
}