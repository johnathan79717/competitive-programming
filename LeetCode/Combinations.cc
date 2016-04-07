typedef vector<int> vi;
typedef vector<vi> vii;

class Solution {
public:
    map<pair<int,int>,vii> m;
    vector<vector<int> > combine(int n, int k) {
        return c(n, k);
    }
    const vii &c(int n, int k) {
        if(m.count(make_pair(n, k))) return m[make_pair(n, k)];
        if(n < k) return m[make_pair(n, k)] = vii();
        if(k == 0) return m[make_pair(n, k)] = vii(1, vi());
        vii ans(c(n-1, k));
        const vii &v = c(n-1, k-1);
        for(vi vv : v) {
            vv.push_back(n);
            ans.push_back(vv);
        }
        return m[make_pair(n, k)] = ans;
    }
};