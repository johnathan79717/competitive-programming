public class Solution {
    public ArrayList<Integer> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(0);
        for(int i = 0; i < n; i++)
            for(int j = ans.size() - 1; j >= 0; j--)
                ans.add(ans.get(j).intValue() + (1<<i));
        return ans;
    }
}