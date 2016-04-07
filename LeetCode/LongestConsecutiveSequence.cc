class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> upto, downto;
        unordered_set<int> visited;
        int ans = 0;
        for(int i : num) {
            if(visited.count(i)) continue;
            visited.insert(i);
            int up = i, down = i;
            if(visited.count(i+1))
                up = upto[i+1];
            if(visited.count(i-1))
                down = downto[i-1];
            ans = max(ans, up - down + 1);
            upto[down] = up;
            downto[up] = down;
        }
        return ans;
    }
};