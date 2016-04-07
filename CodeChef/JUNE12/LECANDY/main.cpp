#include <cstdio>
 
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, C;
        scanf("%d%d", &N, &C);
        for (int i = 0; i < N; ++i) {
            int a;
            scanf("%d", &a);
            C -= a;
        }
        puts((C<0)?"No":"Yes");
    }
} 