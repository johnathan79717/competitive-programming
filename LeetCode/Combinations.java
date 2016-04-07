public class Solution {
    public int numOnes(int n) {
        int ans = 0;
        for(int bit = 1; bit != bit << 1; bit <<= 1)
            if((n & bit) != 0)
                ans++;
        return ans;
    }
    
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < (1<<n); i++) {
            ArrayList<Integer> a = new ArrayList<Integer>();
            if(numOnes(i) == k)
                for(int j = 0; j < n; j++)
                    if(((i >> j) & 1) != 0)
                        a.add(i + 1);
            ans.add(a);
        }
        return ans;
    }
}