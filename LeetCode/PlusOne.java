public class Solution {
    public int[] plusOne(int[] digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for(int i = digits.length - 1; i >= 0; i--) {
            if(digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        int[] ans = new int[digits.length + 1];
        ans[0] = 1;
        return ans;
    }
}