class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!*needle)
            return haystack;
        char *p1end = haystack;
        char *p2 = needle;
        while(*++p2)
            p1end++;
        
        while(*p1end) {
            char *p1 = haystack;
            char *p2 = needle;
            while(*p1 && *p2 && *p1 == *p2) {
                p1++;
                p2++;
            }
            if(*p2 == 0)
                return haystack;
            haystack++;
            p1end++;
        }
        return NULL;
    }
};