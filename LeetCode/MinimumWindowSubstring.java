public class Solution {
    public String minWindow(String S, String T) {
        int[] target = new int[128];
        String ans = "";
        int min = S.length() + 1;
        for(int i = 0; i < T.length(); i++)
            target[T.charAt(i)]++;
        int l = 0, r = 0;
        int[] freq = new int[128];
        int distance = T.length();
        if(distance == 0) return "";
        while(true) {
            while(r < S.length() && distance > 0) {
                char c = S.charAt(r++);
                if(freq[c]++ < target[c]) distance--;
            }
            if(distance > 0)
                return ans;
            while(distance == 0) {
                if(r - l < min) {
                    min = r - l;
                    ans = S.substring(l, r);
                }
                char c = S.charAt(l++);
                if(--freq[c] < target[c]) distance++;
            }
        }
    }
}