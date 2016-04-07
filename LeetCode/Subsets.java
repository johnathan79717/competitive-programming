public class Solution {
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        Arrays.sort(S);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < (1<<S.length); i++) {
            ArrayList<Integer> a = new ArrayList<Integer>();
            for(int j = 0; j < S.length; j++) {
                if(((i >> j) & 1) != 0)
                    a.add(S[j]);
            }
            ans.add(a);
        }
        return ans;
    }
}