#include <iostream>

using namespace std;

int masks[] = {
	1, 2, 4,
	8, 16, 32,
	64, 128, 256,
	3, 6,
	24, 48,
	192, 384,
	9, 18, 36,
	72, 144, 288,
	7,
	56,
	448,
	73, 146, 292,
	11, 22,
	88, 176,
	19, 38,
	152, 304,
	25, 50,
	200, 400,
	26, 52,
	208, 416,
};

int main() {
	int ans = 0;
	for (int i: masks) {
		for (int j: masks) {
			if (i & j) continue;
			for (int k: masks) {
				if (k & i || k & j) continue;
				for (int l: masks) {
					if (l & i || l & j || l & k) continue;
					if ((i | j | k | l) == (1 << 9) - 1) {
						cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}