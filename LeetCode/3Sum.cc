// #include <unordered_set>

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<pair<int, pair<int, int> > > added;
        sort(num.begin(), num.end());
        // vector<pair<int, pair<int, int> > > ans;
        vector<vector<int> > ret;
        for(int a = 0; a < num.size(); a++) {
            int b = a + 1, c = num.size() - 1;
            while(b < c) {
                if(num[b] + num[c] < -num[a])
                    b++;
                else if(num[b] + num[c] > -num[a])
                    c--;
                else {
                    if(added.count(make_pair(num[a], make_pair(num[b], num[c]))) == 0) {
                        // ans.push_back(make_pair(num[a], make_pair(num[b], num[c])));
                        ret.push_back({ num[a], num[b], num[c] });
                        added.insert(make_pair(num[a], make_pair(num[b], num[c])));
                    }
                    b++;
                    c--;
                }
            }
        }
        return ret;
    }
    //     unordered_multimap<int, int> occ;
    //     for(int i = 0; i < num.size(); i++)
    //         occ.insert(num[i], i);
    //     for(int i = 0; i < num.size(); i++)
    //         for(int j = 0; j < i; j++) {
    //             auto range = occ.equal_range(-num[i]-num[j]);
    //             for(auto it = range.first; it != range.second; it++) {
                    
    //             }
    //         }
                
    // }
};