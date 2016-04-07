public class Solution {
    public int ladderLength(String start, String end, HashSet<String> dict) {
        dict.remove(start);
        dict.remove(end);
        Queue<String> qs = new LinkedList<String>();
        Queue<Integer> qi = new LinkedList<Integer>();
        qs.offer(start);
        qi.offer(1);
        while(qi.peek() != null) {
            int len = qi.poll();
            char[] chs = qs.poll().toCharArray();
            for(int i = 0; i < chs.length; i++) {
                char original = chs[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == original) continue;
                    chs[i] = c;
                    String str = String.valueOf(chs);
                    if(str.equals(end))
                        return len + 1;
                    if(dict.contains(str)) {
                        dict.remove(str);
                        qs.offer(str);
                        qi.offer(len + 1);
                    }
                }
                chs[i] = original;
            }
        }
        return 0;
    }
}