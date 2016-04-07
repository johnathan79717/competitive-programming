typedef long long ll;

class Solution {
public:
    int atoi(const char *str) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        while(*str == ' ') str++;
        if(isdigit(*str))
            return getAbs(str, INT_MAX);
        else if(*str == '-')
            return -getAbs(str + 1, -ll(INT_MIN));
        else if(*str == '+')
            return getAbs(str + 1, INT_MAX);
        else
            return 0;
    }
    
    ll getAbs(const char *str, ll limit) {
        ll ans = 0;
        while(isdigit(*str)) {
            ans = ans * 10 + ((*str) - '0');
            if(ans > limit)
                return limit;
            str++;
        }
        return ans;
    }
};