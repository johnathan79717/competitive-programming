class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        if(*p == 0) return *s == 0;
        if(p[1] == '*') {
            do {
                if(isMatch(s, p + 2))
                    return true;
            } while(*s != 0 && (*p == *(s++) || *p == '.'));
            return false;
        } else {
            if(*s != 0 && (*p == *s || *p == '.'))
                return isMatch(s + 1, p + 1);
            else
                return false;
        }
    }
};