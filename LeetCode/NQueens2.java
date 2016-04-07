public class Solution {
    boolean used[];
    int ans;
    int[] perm;
    public int totalNQueens(int n) {
        used = new boolean[n];
        ans =  0;
        perm = new int[n];
        dfs(0);
        return ans;
    }
    public boolean checkDiagonal(int n) {
        for(int i = 0; i < n; i++)
            if(Math.abs(perm[i] - perm[n]) == n - i)
                return false;
        return true;
    }
    public void dfs(int n) {
        if(n == perm.length) {
            ans++;
            return;
        }
        for(int i = 0; i < perm.length; i++) {
            if(used[i]) continue;
            perm[n] = i;
            if(checkDiagonal(n)) {
                used[i] = true;
                dfs(n + 1);
                used[i] = false;
            }
        }
    }
}