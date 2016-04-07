public class Solution {
    public String intToRoman(int num) {
        int[] value = {1000, 500, 100, 50, 10, 5, 1};
        char[] symbol = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        String ans = new String();
        for(int i = 0; i < 7; i++) {
            if(num / value[i] == 1 && i < 6 && num / value[i+1] == 9) {
                ans += symbol[i+1];
                ans += symbol[i-1];
                num -= 9 * value[i+1];
            }
            if(num / value[i] == 4) {
                ans += symbol[i];
                ans += symbol[i-1];
                num -= 4 * value[i];
            }
            while(num >= value[i]) {
                num -= value[i];
                ans += symbol[i];
            }
        }
        return ans;
    }
}