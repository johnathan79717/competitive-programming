#include <cstdio>
long long one[20], other[20];
int ans = 0;
void dfs(int a, int i = 1) {
    if (i == 16) {
        ans++;
    } else {
        for (int j = 1; j <= 5; j++) {
            if (a == 1 || j == 1 || a == j) {
                dfs(j, i+1);
            }
        }
    }
}
int main() {
    //one[1] = 1;
    //other[1] = 4;
    //for (int i = 1; i < 20; i++) {
        //printf("%d %lld\n", i, one[i] + other[i]);
        //one[i+1] = one[i] + other[i];
        //other[i+1] = one[i] * 4 + other[i];
    //}
    dfs(1); dfs(2); dfs(3); dfs(4); dfs(5);
    printf("%d\n", ans);
}
