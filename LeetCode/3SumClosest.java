public class Solution {
    public int threeSumClosest(int[] num, int target) {
        Arrays.sort(num);
        int ans = 0;
        int diff = Integer.MAX_VALUE;
        for(int i = 0; i < num.length; i++) {
            int l = 0, r = num.length - 1;
            while(l < r) {
                if(l == i) { l++; continue; }
                if(r == i) { r--; continue; }
                if(Math.abs(num[l] + num[r] + num[i] - target) < diff) {
                    ans = num[l] + num[r] + num[i];
                    diff = Math.abs(ans - target);
                }
                if(num[l] + num[r] + num[i] < target)
                    l++;
                else if(num[l] + num[r] + num[i] > target)
                    r--;
                else
                    return target;
            }
        }
        return ans;
    }
}