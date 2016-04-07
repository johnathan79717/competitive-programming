public class Solution {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1, ans = 0;
        while(l < r) {
            ans = Math.max(ans, (r - l) * Math.min(height[l], height[r]));
            if(height[l] < height[r])
                l++;
            else if(height[l] > height[r])
                r--;
            else {
                l++; r--;
            }
        }
        return ans;
    }
}