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


int main() {
	DRI(T);
	while (T--) {
		DRI(N);
		VI A(N);
		REP(i, N) {
			RI(A[i]);
		}
		V(PII) dp(N, MP(1, 1));
		REP1(i, 1, N-1) {
			REP(j, i) {
				if (A[j] < A[i]) {
					if (dp[i].first == dp[j].first + 1) {
						dp[i].second += dp[j].second;
					} else if (dp[j].first + 1 > dp[i].first) {
						dp[i].first = dp[j].first + 1;
						dp[i].second = dp[j].second;
					}
				}
			}
		}
		REP1(i, 1, N-1) {
			int j = i-1;
			if (dp[i].first == dp[j].first) {
				dp[i].second += dp[j].second;
			} else if (dp[j].first > dp[i].first) {
				dp[i].first = dp[j].first;
				dp[i].second = dp[j].second;
			}
		}
		if (dp[N-1].second == 1) {
			PI(dp[N-1].first - 1);
		} else {
			PI(dp[N-1].first);
		}
	}
  return 0;
}
