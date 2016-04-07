public class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int min = Integer.MAX_VALUE, ans = 0, sum = 0;
        for(int i = 0; i < gas.length; i++) {
            sum += (gas[i] - cost[i]);
            if(sum < min) {
                min = sum;
                ans = i + 1;
            }
        }
        if(sum >= 0)
            return ans % gas.length;
        else
            return -1;
    }
}