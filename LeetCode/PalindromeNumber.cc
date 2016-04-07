class Solution {
public:
    bool isPalindrome(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x < 0) return false;
        long long temp = x;
        long long rev = 0;
        while(x) {
            rev = 10 * rev + x % 10;
            x /= 10;
        }
        return temp == rev;
    }
};