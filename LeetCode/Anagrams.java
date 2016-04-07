public class Solution {
    public ArrayList<String> anagrams(String[] strs) {
        HashMap<List<Integer>, Integer> map = new HashMap<List<Integer>, Integer>(); 
        ArrayList<String> ans = new ArrayList<String>();
        boolean[] added = new boolean[strs.length];
        for(int j = 0; j < strs.length; j++) {
            Integer[] freq = new Integer[26];
            for(int i = 0; i < 26; i++)
                freq[i] = new Integer(0);
            for(int i = 0; i < strs[j].length(); i++)
                freq[strs[j].charAt(i) - 'a']++;
            List<Integer> list = Arrays.asList(freq);
            if(map.containsKey(list)) {
                int i = map.get(list);
                if(!added[i]) {
                    added[i] = true;
                    ans.add(strs[i]);
                }
                ans.add(strs[j]);
            } else
                map.put(list, j);
        }
        return ans;
    }
}