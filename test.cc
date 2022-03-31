#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int B;
    int solve(int s, vector<int> &f) {
        int ans = 0;
        for (int &x : f) {
            if (x) {
                ans = max(ans, (s % B ? 0 : 1) + solve(s + x--, f));
                x++;
            }
        }
        return ans;
    }
    int maxHappyGroups(int B, vector<int>& groups) {
        this->B = B;
        vector<int> f(B);
        for (int g : groups) {
            f[g%B]++;
        }
        return solve(0, f);
    }
};

int main() {
    vector<int> g = {1, 2, 3, 4, 5, 6};
    auto ans = Solution().maxHappyGroups(3, g);
    cout << ans << endl;
}
