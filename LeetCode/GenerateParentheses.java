public class Solution {
    ArrayList<ArrayList<String>> dp;
    public ArrayList<String> generateParenthesis(int n) {
        if(dp == null) dp = new ArrayList<ArrayList<String>>();
        while(dp.size() < n + 1)
            dp.add(new ArrayList<String>());
        if(dp.get(n).size() > 0) return dp.get(n);
        ArrayList<String> ans = new ArrayList<String>();
        if(n == 0)
            ans.add("");
        else {
            for(int i = 0; i < n; i++) {
                ArrayList<String> ai = generateParenthesis(i);
                ArrayList<String> bi = generateParenthesis(n-1-i);
                for(String s1 : ai)
                    for(String s2 : bi)
                        ans.add("(" + s1 + ")" + s2);
            }
        }
        dp.set(n, ans);
        return ans;
    }
}