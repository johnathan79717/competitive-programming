public class Solution {
    public boolean isPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        s = s.toLowerCase();
        while(l < r) {
            if(s.charAt(l) < 'a' || 'z' < s.charAt(l)) l++;
            else if(s.charAt(r) < 'a' || 'z' < s.charAt(r)) r--;
            else if(s.charAt(l) != s.charAt(r)) return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
}