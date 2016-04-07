struct Char {
    int row;
    int col;
    int ch;
};

bool compare(const Char &a, const Char &b) {
  if(a.row != b.row)
    return a.row < b.row;
  else
    return a.col < b.col;
}

class Solution {
public:
    string convert(string s, int nRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(nRows == 1)
            return s;
        vector<Char> v(s.size());
        for(int i = 0; i < s.size(); i++) {
            v[i].ch = s[i];
            int cycle = 2 * nRows - 2;
            int sec = i / cycle;
            if(i % cycle < nRows) {
                v[i].col = sec * (nRows - 1);
                v[i].row = i % cycle;
            } else {
                v[i].col = sec * (nRows - 1) + i % (nRows - 1);
                v[i].row = nRows - 1 - i % (nRows - 1);
            }
        }
        sort(v.begin(), v.end(), compare);
        string ans;
        for(auto c : v)
            ans.push_back(c.ch);
        return ans;
    }
};