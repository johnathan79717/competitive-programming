class Solution {
public:
    int longestPalindrome(const string &s,  int i, int j) {
        while(i >= 0 && j < s.size()) {
            if(s[i] != s[j])
                break;
            i--; j++;
        }
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxL = 0, maxI;
        for(int i = 0; i < s.size(); i++) {
            int l;
            if((l = longestPalindrome(s, i, i)) > maxL) {
                maxL = l;
                maxI = i - l / 2;
            }
            if((l = longestPalindrome(s, i, i+1)) > maxL) {
                maxL = l;
                maxI = i - l / 2 + 1;
            }
        }
        return s.substr(maxI, maxL);
    }
};