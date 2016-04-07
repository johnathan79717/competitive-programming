public class Solution {
    public String longestCommonPrefix(String[] strs) {
        String ans = new String();
        if(strs.length == 0) return ans;
        int i = 0;
        while(true) {
            if(i >= strs[0].length())
                return ans;
            char c = strs[0].charAt(i);
            for(String str : strs) {
                if(i >= str.length() || str.charAt(i) != c)
                    return ans;
            }
            ans += c;
            i++;
        }
    }
}