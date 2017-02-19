#include <bits/stdc++.h>

using namespace std;

int INF = 100000000;

int go1(int x, int y, int k) {
	if (x < 2 * k + 3) return INF;
	if (y <= k) return INF;
	return y / k + ((y % k == 0) ? 0 : 1);
}

int go2(int x, int y, int k) {
	if (k == 1) {
		if (x < 5 || y < 3) return INF;
		return 5;
	}
	if (x < 3 * k + 1) return INF;
	if (y < 2 * k + 1) return INF;
	return 4;
}

int go(int x, int y, int k) {
	return min(go1(x, y, k), go2(x, y, k));
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int x, y, k;
		cin >> x >> y >> k;
		int ans = min(go(x, y, k), go(y, x, k));
		if (ans == INF) ans = -1;
		printf("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}

