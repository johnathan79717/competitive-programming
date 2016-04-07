public class Solution {
    boolean[][] dp;
    String s;
    ArrayList<String> part;
    ArrayList<ArrayList<String>> ans;
    public ArrayList<ArrayList<String>> partition(String s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        dp = new boolean[s.length()][s.length()];
        this.s = s;
        part = new ArrayList<String>();
        ans = new ArrayList<ArrayList<String>>();
        for(int i = 0; i < s.length(); i++)
            dp[i][i] = true;
        for(int i = 1; i < s.length(); i++)
            if(s.charAt(i-1) == s.charAt(i))
                dp[i-1][i] = true;
        for(int d = 2; d < s.length(); d++)
            for(int i = 0; i + d < s.length(); i++)
                if(dp[i+1][i+d-1] && s.charAt(i) == s.charAt(i + d))
                    dp[i][i+d] = true;
        dfs(0);
        return ans;
    }
    public void dfs(int n) {
        if(n == s.length()) {
            ans.add(new ArrayList<String>(part));
            return;
        }
        for(int i = n; i < s.length(); i++)
            if(dp[n][i]) {
                part.add(s.substring(n, i+1));
                dfs(i + 1);
                part.remove(part.size() - 1);
            }
    }
}