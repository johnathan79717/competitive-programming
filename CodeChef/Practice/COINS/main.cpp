#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1000001

long long a[MAX];

long long f(long long n) {
    // cout << n << endl;
    if (n < 12) return n;
    long long ans;
    if (n < MAX && a[n] > 0)
        return (ans = a[n]);
    ans = max(n, f(n/2) + f(n/3) + f(n/4));
    // cout << ans << endl;
    if (n < MAX)
        a[n] = ans;
    return ans;
}

int main() {
    long long n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < 12; ++i)
        a[i] = i;
    while(cin >> n)
        cout << f(n) << endl;
}