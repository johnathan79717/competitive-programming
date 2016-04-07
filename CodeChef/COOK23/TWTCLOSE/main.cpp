#include <cstdio>
#include <cstring>

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int open[1005], ans = 0;
    memset(open, 0, sizeof(open));
    while(K--) {
        char str[10];
        scanf("%s", str);
        if (str[2] == 'O') { // CLOSEALL
            memset(open, 0, sizeof(open));
            printf("%d\n", ans = 0);
        } else {
            int n;
            scanf("%d", &n);
            printf("%d\n", (open[n] = 1-open[n]) ? ++ans : --ans);
        }
    }
}