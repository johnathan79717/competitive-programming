// Create your own template by modifying this file!

#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <deque>
#include <stack>
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

LL solve(LL k, const V(unsigned) &a) {
	int m = a.size();
	int l = 0, r = m-1;
	LL ans = 0;
	while(l < r) {
		if (a[l] + a[r] <= k) {
			l++;
		} else {
			ans += r - l;
			r--;
		}
	}
	return ans;
}

int main() {
	DRI(T);
	while(T--) {
		DRI(n);
		unsigned k;
		scanf("%u", &k);
		LL ans = 0;
		V(unsigned) A;
		while(n--) {
			DRI(m);
			V(unsigned) a(m);
			REP(i, m) {
				scanf("%u", &a[i]);
				A.PB(a[i]);
			}
			sort(ALL(a));
			ans -= solve(k, a);
			// cerr << solve(k, a) << endl;
		}
		sort(ALL(A));
		// cerr << solve(k, A) << endl;
		cout << (ans + solve(k, A)) << endl;
	}
  return 0;
}
