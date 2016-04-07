public class Solution {
    public int longestConsecutive(int[] num) {
        HashMap<Integer, Integer> upto = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> downto = new HashMap<Integer, Integer>();
        HashSet<Integer> visited = new HashSet<Integer>();
        int ans = 0;
        for(int i : num) {
            if(visited.contains(i)) continue;
            visited.add(i);
            Integer up = upto.get(i+1);
            Integer down = downto.get(i-1);
            if(up == null) up = i;
            if(down == null) down = i;
            ans = Math.max(ans, up - down + 1);
            upto.put(down, up);
            downto.put(up, down);
        }
        return ans;
    }
}