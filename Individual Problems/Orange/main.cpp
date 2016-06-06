#include <cctype>
#include <cstdio>

int main() {
    char str[52];
    int n;
    scanf("%s%d", str, &n);
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
        if(str[i] < n + 97)
            str[i] = toupper(str[i]);
    }
    printf("%s\n", str);
}