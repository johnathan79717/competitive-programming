public class Solution {
    ArrayList<ArrayList<Integer>> ans;
    public ArrayList<ArrayList<Integer>> subsetsWithDup(int[] num) {
        Arrays.sort(num);
        ans = new ArrayList<ArrayList<Integer>>();
        dfs(num, 0, new ArrayList<Integer>());
        return ans;
    }
    public void dfs(int[] num, int pos, ArrayList<Integer> subset) {
        if(pos == num.length) {
            ans.add(new ArrayList<Integer>(subset));
            return;
        }
        int end = pos;
        while(end < num.length && num[end] == num[pos]) end++;
        dfs(num, end, subset);
        for(int i = 0; i < end - pos; i++) {
            subset.add(num[pos]);
            dfs(num, end, subset);
        }
        for(int i = 0; i < end - pos; i++)
            subset.remove(subset.size() - 1);
    }
}