#include <cassert>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    map<string, int> num;
    int c = 0;
    vector<vector<int>> v;
    for (int i = 0; i < K; i++) {
        int j;
        char s[15];
        scanf("%d%s", &j, s);
        string str(s);
        if (!num.count(str)) {
            num[str] = c++;
            v.resize(c);
        }
        v[num[str]].push_back(j);
    }
    for (int i = 0; i < c; i++) {
        sort(v[i].begin(), v[i].end());
    }
    int M;
    scanf("%d", &M);
    vector<int> a(M);
    for (int i = 0; i < M; i++) {
        char s[15];
        scanf("%s", s);
        a[i] = num[string(s)];
    }
    int x = 0;
    vector<int> ans;
    for (int i = 0; i < M; i++) {
        auto it = lower_bound(v[a[i]].begin(), v[a[i]].end(), x);
        if (it == v[a[i]].end()) {
            puts("impossible");
            return 0;
        }
        ans.push_back(*it);
        x = (*it);
    }
    x = N;
    for (int i = M-1; i >= 0; i--) {
        auto it = lower_bound(v[a[i]].rbegin(), v[a[i]].rend(), x, greater<int>());
        if (it == v[a[i]].rend()) {
            assert(false);
            return 0;
        }
        if (*it != ans[i]) {
            puts("ambiguous");
            return 0;
        }
        ans.push_back(*it);
        x = (*it);
    }
    puts("unique");
}
