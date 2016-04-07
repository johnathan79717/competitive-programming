#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define rep(i,n) for(int i = 0; i < n; ++i)

int m[101][101];
int R, C;

int main() {
	cin >> R >> C;
	rep(i, R) rep(j, C) cin >> m[i][j];
	int maxmin = -INT_MAX;
	int colmax[101];
	rep(j, C) colmax[j] = -INT_MAX;
	rep(i, R) {
		int rowmin = INT_MAX;
		rep(j, C) {
			rowmin = min(rowmin, m[i][j]);
			colmax[j] = max(colmax[j], m[i][j]);
		}
		maxmin = max(maxmin, rowmin);
	}
	int minmax = INT_MAX;
	rep(j, C) minmax = min(minmax, colmax[j]);
	if (minmax == maxmin)
		cout << minmax << endl;
	else
		cout << "GUESS" << endl;
}