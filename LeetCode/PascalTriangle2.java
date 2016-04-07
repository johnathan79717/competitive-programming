public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(1);
        long prev = 1;
        for(int i = 1; i <= rowIndex; i++) {
            prev = prev * (rowIndex - i + 1) / i;
            ans.add((int)prev);
        }
        return ans;
    }
}