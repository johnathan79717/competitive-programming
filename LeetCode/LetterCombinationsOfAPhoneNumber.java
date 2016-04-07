public class Solution {
    String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public ArrayList<String> letterCombinations(String digits) {
        ArrayList<String> ans = new ArrayList<String>();
        String comb = "";
        dfs(digits, 0, comb, ans);
        return ans;
    }
    public void dfs(String digits, int n, String comb, ArrayList<String> ans) {
        if(n == digits.length()) {
            ans.add(comb);
            return;
        }
        int k = digits.charAt(n) - '0';
        for(int i = 0; i < map[k].length(); i++) {
            String s = new String(comb);
            s += map[k].charAt(i);
            dfs(digits, n + 1, s, ans);
        }
    }
}