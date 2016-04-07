public class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return combinationSum(candidates, target, candidates.length);
    }
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target, int n) {
        if(n == 0) {
            ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
            if(target == 0) 
                ret.add(new ArrayList<Integer>());
            return ret;
        }
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; target >= 0; i++) {
            ArrayList<ArrayList<Integer>> aa = combinationSum(candidates, target, n - 1);
            for(int j = 0; j < aa.size(); j++) {
                ArrayList<Integer> a = new ArrayList<Integer>(aa.get(j));
                for(int k = 0; k < i; k++)
                    a.add(candidates[n-1]);
                ans.add(a);
            }
            target -= candidates[n-1];
        }
        return ans;
    }
}