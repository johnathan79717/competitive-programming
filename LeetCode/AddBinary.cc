class Solution {
public:
    string addBinary(string a, string b) {
        string c(max(a.size(), b.size()), '0');
        auto ai = a.rbegin(), bi = b.rbegin(), ci = c.rbegin();
        int carry = 0;
        while(ai != a.rend() && bi != b.rend() && ci != c.rend()) {
            int d = carry + (*ai - '0') + (*bi - '0');
            carry = d / 2;
            *ci = '0' + d % 2;
            ai++;
            bi++;
            ci++;
        }
        while(ai != a.rend()) {
            int d = carry + (*ai - '0');
            carry = d / 2;
            *ci = '0' + d % 2;
            ai++;
            ci++;
        }
        while(bi != b.rend()) {
            int d = carry + (*bi - '0');
            carry = d / 2;
            *ci = '0' + d % 2;
            bi++;
            ci++;
        }
        if(carry > 0)
            c.insert(0, "1");
        return c;
    }
};