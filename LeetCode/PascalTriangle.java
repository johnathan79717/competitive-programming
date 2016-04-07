public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>(numRows);
        if(numRows == 0) return ans;
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(1);
        ans.add(a);
        for(int i = 1; i < numRows; i++) {
            ArrayList<Integer> b = new ArrayList<Integer>();
            b.add(1);
            for(int j = 1; j < a.size(); j++)
                b.add(a.get(j) + a.get(j-1));
            b.add(1);
            ans.add(b);
            a = b;
        }
        return ans;
    }
}