public class Solution {
    int[] perm;
    ArrayList<ArrayList<Integer>> ans;
    boolean used[];
    void permute1(int pos, int[] num) {
        if(pos == num.length) {
            ArrayList<Integer> a = new ArrayList<Integer>();
            for(int i : perm)
                a.add(i);
            ans.add(a);
        }
        else {
            for(int i = 0; i < num.length; i++) {
                if(!used[i]) {
                    perm[pos] = num[i];
                    used[i] = true;
                    permute1(pos + 1, num);
                    used[i] = false;
                }
            }
        }
    }
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        used = new boolean[num.length];
        perm = new int[num.length];
        ans = new ArrayList<ArrayList<Integer>>();
        permute1(0, num);
        return ans;
    }
}