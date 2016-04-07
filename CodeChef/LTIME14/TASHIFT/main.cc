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
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

char A[1000001], B[2000001];
int T[1000001];

void kmp_table(char *W, int *T) {
  int pos = 2, cnd = 0;
  T[0] = -1, T[1] = 0;
  int N = strlen(W);
  while(pos < N) {
    if(W[pos-1] == W[cnd]) {
      cnd++;
      T[pos] = cnd;
      pos++;
    } else if(cnd > 0) {
      cnd = T[cnd];
    } else {
      T[pos] = 0;
      pos++;
    }
  }
}

int maxi = -1, maxm;

int kmp_search(char *S, char *W, int *T) {
  int m = 0, i = 0;
  int ls = strlen(S), lw = strlen(W);
  while(m + i < ls) {
    if(W[i] == S[m+i]) {
      if(i == lw-1) return m;
      i++;
    } else {
      if(T[i] > -1) {
        i = T[i];
        m = m + i - T[i];
      } else {
        i = 0;
        m++;
      }
    }
    if(i > maxi) {
      maxi = i;
      maxm = m;
    }
  }
  return ls;
}

int main() {
  DRI(N);
  RS(A); RS(B);
  REP(i, N) B[i+N] = B[i];
  kmp_table(A, T);
  // REP(i, N) PI(T[i]);
  kmp_search(B, A, T);
  // PI(maxi);
  PI(maxm);
  return 0;
}
