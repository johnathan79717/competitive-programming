public class Solution {
    ArrayList<String> ans;
    String s;
    ArrayList<String> tmp;
    public ArrayList<String> restoreIpAddresses(String s) {
        ans = new ArrayList<String>();
        this.s = s;
        tmp = new ArrayList<String>();
        dfs(0);
        return ans;
    }
    public void dfs(int n) {
        if(tmp.size() == 4) {
            if(n == s.length()) {
                String sol = new String();
                sol += tmp.get(0);
                sol += '.';
                sol += tmp.get(1);
                sol += '.';
                sol += tmp.get(2);
                sol += '.';
                sol += tmp.get(3);
                ans.add(sol);
            }
            return;
        }
        if(n == s.length())
            return;
        tmp.add(s.substring(n, n + 1));
        dfs(n + 1);
        tmp.remove(tmp.size() - 1);
        if(s.charAt(n) != '0' && n + 1 < s.length()) {
            tmp.add(s.substring(n, n + 2));
            dfs(n + 2);
            tmp.remove(tmp.size() - 1);
            if(n + 2 < s.length() && (s.charAt(n) == '1' || s.charAt(n) == '2' && (s.charAt(n+1) <= '4' || s.charAt(n+1) == '5' && s.charAt(n+2) <= '5'))) {
                tmp.add(s.substring(n, n + 3));
                dfs(n + 3);
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}