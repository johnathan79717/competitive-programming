#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    pair<int, int> f[100003];
    for(int i = 0; i < N; ++i) {
        scanf("%d", &f[i].first);
        f[i].second = i;
    }
    sort(f, f+N);
    // for(int i = 0; i < N; ++i) {
    //     printf("%d %d\n", f[i].first, f[i].second);
    // }
    int ans = 1;
    int meal = f[0].first;
    int prev = f[0].second;
    for(int i = 0; i < N; ++i) {
        if (f[i].first != meal) {
            meal = f[i].first;
            prev = f[i].second;
            ++ans;
        }
        else if (f[i].second >= prev + K) {
            prev = f[i].second;
            ++ans;
        }
    }
    printf("%d\n", ans);
}