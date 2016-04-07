#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functional>
#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
using namespace std;

#define F first
#define S second
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

LL bd1[1000001], bd2[1000001];
bool set1[2000001], set2[2000001], both[2000001];

LL solve() {
	int N, M;
	scanf("%d%d", &N, &M);
	int x1, a1, b1, c1, r1, x2, a2, b2, c2, r2;
	scanf("%d%d%d%d%d%d%d%d%d%d", &x1, &a1, &b1, &c1, &r1, &x2, &a2, &b2, &c2, &r2);
	bd1[0] = x1; bd2[0] = x2;
	vector<LL> all;
	all.push_back(x1);
	all.push_back(x2);
	for(int i = 1; i < max(N, M); i++) {
		if(i < N) {
			bd1[i] = (a1 * bd1[(i-1) % N] + b1 * bd2[(i-1) % M] + c1) % r1;
			all.push_back(bd1[i]);
		}
		if(i < M) {
			bd2[i] = (a2 * bd1[(i-1) % N] + b2 * bd2[(i-1) % M] + c2) % r2;
			all.push_back(bd2[i]);
		}
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < N; i++)
		bd1[i] = lower_bound(all.begin(), all.end(), bd1[i]) - all.begin();
	for(int i = 0; i < M; i++)
		bd2[i] = lower_bound(all.begin(), all.end(), bd2[i]) - all.begin();
	int i1 = 0, i2 = 0;
	LL ans = 0;
	memset(set1, false, sizeof(set1));
	memset(set2, false, sizeof(set2));
	memset(both, false, sizeof(both));
	int cnt1 = 0, cnt2 = 0;
	while(i1 < N && i2 < M) {
		if(bd1[i1] == bd2[i2]) {
			both[bd1[i1]] = true;
			i1++; i2++;
		}
		else {
			set1[bd1[i1++]] = true;
			cnt1++;
			set2[bd2[i2++]] = true;
			cnt2++;
			while((i1 < N && cnt2) || (i2 < M && cnt1)) {
				while(i1 < N && cnt2) {
					int a = bd1[i1];
					if(!both[a]) {
						if(set2[a]) {
							set2[a] = false;
							cnt2--;
							both[a] = true;
						} else {
							if(!set1[a]) {
								set1[a] = true;
								cnt1++;
							}
						}
					}
					i1++;
				}
				while(i2 < M && cnt1) {
					int a = bd2[i2];
					if(!both[a]) {
						if(set1[a]) {
							set1[a] = false;
							cnt1--;
							both[a] = true;
						}
						else {
							if(!set2[a]) {
								set2[a] = true;
								cnt2++;
							}
						}
					}
					i2++;
				}
			}
			if(cnt1 || cnt2)
				break;
		}
		int p1 = i1, p2 = i2;
		while(i1 < N && both[bd1[i1]])
			i1++;
		while(i2 < M && both[bd2[i2]])
			i2++;
		// add to ans
		ans += (long long)(i1 - p1 + 1) * (i2 - p2 + 1);
	}
	return ans;
}

int main() {
	int T, cas = 1;
	scanf("%d", &T);
	while(T--) {
		printf("Case #%d: %lld\n", cas++, solve());
	}
}