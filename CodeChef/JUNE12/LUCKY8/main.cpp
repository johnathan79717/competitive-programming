#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

int ans;
long long L, R;

void check(long long a, int fix = 0) {
    // cout << "check " << a << ' ' << fix << endl;
    int four = 0;
    int seven = 0;
    do {
        if (a % 10 == 4) ++four;
        if (a % 10 == 7) ++seven;
    } while (a /= 10);
    int ret;
    if (seven >= four + fix) ret = seven*(four+fix);
    else if (four >= seven + fix) ret = four*(seven+fix);
    else {
        ret = seven + four + fix;
        ret = (ret/2) * ((ret+1)/2);
    }
    ans = max(ans, ret);
}

void solve() {
    scanf("%lld%lld", &L, &R);
    ans = 0;
    check(L);
    check(R);
    if (L == R) { cout << ans << endl; return; }
    long long l = L;
    long long r = R;
    int diff = 0;
    while (l != r) {
        ++diff;
        l /= 10;
        r /= 10;
    }
    l = L;
    r = R;
    for (int i = 0; i < diff-1; ++i) {
        // cout << "l "  << l << " r " << r << endl;
        int k = l % 10;
        if (k < 4) check(l-k+4, i);
        if (k < 7) check(l-k+7, i);
        else if (k < 9) check(l+1, i);
        l /= 10;
        k = r % 10;
        if (k > 7) check(r-k+7, i);
        if (k > 4) check(r-k+4, i);
        if (k > 0) check(r-1, i);
        r /= 10;
    }
    assert((l!=r) && r-l < 10);
    for (long long i = l+1; i < r; ++i) check(i, diff-1);
    printf("%d\n", ans);
}

int main() {
    // ans = 0;
    // L = 1; R = 100000000;
    // check(1843756, 7);
    // cout << ans << endl;
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}