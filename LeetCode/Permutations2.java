public class Solution {
    HashMap<Integer, Integer> used;
    HashMap<Integer, Integer> occ;
    ArrayList<Integer> perm;
    ArrayList<ArrayList<Integer>> ans;
    Set<Integer> set;
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        used = new HashMap<Integer, Integer>();
        occ = new HashMap<Integer, Integer>();
        perm = new ArrayList<Integer>();
        ans = new ArrayList<ArrayList<Integer>>();
        for(int i : num) {
            used.put(i, 0);
            if(occ.containsKey(i))
                occ.put(i, 1 + occ.get(i));
            else
                occ.put(i, 1);
        }
        set = occ.keySet();
        dfs(num.length);
        return ans;
    }
    public void dfs(int n) {
        if(n == 0) {
            ans.add(new ArrayList<Integer>(perm));
            return;
        }
        Iterator<Integer> it = set.iterator();
        while(it.hasNext()) {
            Integer i = it.next();
            Integer u = used.get(i);
            if(u < occ.get(i)) {
                perm.add(i);
                used.put(i, u + 1);
                dfs(n - 1);
                perm.remove(perm.size() - 1);
                used.put(i, u);
            }
        }
    }
}