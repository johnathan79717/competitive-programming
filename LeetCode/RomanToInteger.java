public class Solution {
    public int romanToInt(String s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // Note: The Solution object is instantiated only once and is reused by each test case.
        char c[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int n[] = {1000, 500, 100, 50, 10, 5, 1};
        int i = 0;
        int expected = 0;
        int ans = 0;
        while(expected < 7 && i < s.length()) {
            if(s.charAt(i) != c[expected]) {
                expected++;
            } else {
                if(expected % 2 != 0) {
                    // only appears once
                    ans += n[expected];
                    i++;
                    expected++;
                } else {
                    int cnt = 0;
                    if(expected >= 2 && i + 1 < s.length() && s.charAt(i+1) == c[expected - 2]) {
                        // IV or XC or CM
                        cnt = 9;
                        i += 2; // read 2 characters
                    } else if (expected >= 1 && i + 1 < s.length() && s.charAt(i+1) == c[expected - 1]) {
                        // IV or XL or CD
                        cnt = 4;
                        i += 2; // read 2 characters
                    } else {
                        while(i < s.length() && s.charAt(i) == c[expected]) {
                            cnt++;
                            i++;
                        }
                    }
                    ans += cnt * n[expected];
                    expected++;
                }
            }
        }
        if(i == s.length()) {
            return ans;
        } else {
            return -1;
        }
    }
}