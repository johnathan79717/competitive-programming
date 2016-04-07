#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define ull unsigned long long

int n;
ull A[131];

int main() {
	scanf("%d", &n);
	if (n >= 130) {
		puts("Yes");
		return 0;
	}
	for(int i = 0; i < n; ++i)
		scanf("%llu", A+i);	
	for(int i4 = 0; i4 < n; ++i4) {
		for(int i3 = 0; i3 < i4; ++i3) {
			for(int i2 = 0; i2 < i3; ++i2) {
				for(int i1 = 0; i1 < i2; ++i1) {
					if((A[i1]^A[i2]^A[i3]^A[i4]) == 0) {
						puts("Yes");
						return 0;
					}
				}
			}
		}
	}
	puts("No");
	return 0;
}