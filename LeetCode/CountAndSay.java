public class Solution {
    public String countAndSay(int n) {
        String prev = "1";
        for(int i = 1; i < n; i++) {
            String curr = "";
            char digit = prev.charAt(0);
            char num = '0';
            for(char c : prev.toCharArray()) {
                if(c == digit) num++;
                else {
                    curr += num;
                    curr += digit;
                    num = '1';
                    digit = c;
                }
            }
            curr += num;
            curr += digit;
            prev = curr;
        }
        return prev;
    }
}