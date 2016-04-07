class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        l = r = ans = 0
        n = len(s)
        occ = set()
        while r < n:
            while s[r] in occ:
                occ.remove(s[l])
                l += 1
            occ.add(s[r])
            r += 1
            ans = max(ans, r - l)
        return ans