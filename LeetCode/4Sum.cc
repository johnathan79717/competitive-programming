class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        multimap<int, pair<int, int> > two;
        set<pair<pair<int, int>, pair<int, int> > >occ;
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++)
            for(int j = 0; j < i; j++)
                two.insert(make_pair(num[i] + num[j], make_pair(j, i)));
        for(auto &p : two) {
            auto range = two.equal_range(target-p.first);
            for(auto it = range.first; it != range.second; it++)
                if(p.second.second < it->second.first) {
                    vector<int> a = {num[p.second.first], num[p.second.second], num[it->second.first], num[it->second.second]};
                    sort(a.begin(), a.end());
                    if(occ.count(make_pair(make_pair(a[0], a[1]), make_pair(a[2], a[3]))))
                        continue;
                    occ.insert(make_pair(make_pair(a[0], a[1]), make_pair(a[2], a[3])));
                    ans.push_back(a);
                }
        }
        // for(auto &v : occ)
        //     ans.push_back(v);
        // ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        return ans;
    }
};