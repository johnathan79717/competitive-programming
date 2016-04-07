public class Solution {
    public int[][] generateMatrix(int n) {
        int[][] ans = new int[n][n];
        int[] dc = {1, 0, -1, 0, 1};
        int[] dr = {0, 1, 0, -1, 0};
        int dir = 0;
        int r = 0, c = 0, num = 1;
        
        while(num <= n * n) {
            ans[r][c] = num++;
            r += dr[dir];
            c += dc[dir];
            if(r < 0 || r >= n || c < 0 || c >= n || ans[r][c] > 0) {
                r = r - dr[dir] + dr[dir+1];
                c = c - dc[dir] + dc[dir+1];
                dir = (dir + 1) % 4;
            }
        }
        return ans;
    }
}