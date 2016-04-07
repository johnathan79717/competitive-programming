public class Solution {
    public String getPermutation(int n, int k) {
        k--;
        String ans = "";
        int[] perm = new int[n];
        perm[0] = 1;
        for(int i = 1; i < n; i++)
            perm[i] = perm[i-1] * i;
        boolean[] used = new boolean[n];
        for(int i = n - 1; i >= 0; i--) {
            int pos = k / perm[i] + 1;
            int j;
            for(j = 0; j < n; j++) {
                if(!used[j])
                    pos--;
                if(pos == 0)
                    break;
            }
            used[j] = true;
            ans += (char)('1' + j);
            k %= perm[i];
        }
        return ans;
    }
}