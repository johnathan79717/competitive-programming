class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for(auto it = digits.rbegin(); it != digits.rend(); it++)
            if(*it < 9) {
                ++*it;
                return digits;
            } else {
                *it = 0;
            }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};