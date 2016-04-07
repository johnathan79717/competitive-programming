public class Solution {
    HashMap<Integer, Integer> occ;
    ArrayList<ArrayList<Integer>> ans;
    ArrayList<Integer> perm;
    Integer[] set;
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        occ = new HashMap<Integer, Integer>();
        perm = new ArrayList<Integer>();
        ans = new ArrayList<ArrayList<Integer>>();
        for(int i : num) {
            if(occ.containsKey(i))
                occ.put(i, 1 + occ.get(i));
            else
                occ.put(i, 1);
        }
        set = occ.keySet().toArray(new Integer[0]);
        dfs(0, target);
        return ans;
    }
    public void dfs(int n, int target) {
        if(target < 0)
            return;
        if(n == set.length) {
            if(target == 0)
                ans.add(new ArrayList<Integer>(perm));
            return;
        }
        for(int i = 0; i <= occ.get(set[n]); i++) {
            dfs(n + 1, target - i * set[n]);
            perm.add(set[n]);
        }
        for(int i = 0; i <= occ.get(set[n]); i++)
            perm.remove(perm.size() - 1);
    }
}