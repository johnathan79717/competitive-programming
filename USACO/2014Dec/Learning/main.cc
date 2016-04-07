/*
ID: johnath2
PROG: crypt1
LANG: C++11
*/
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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
using namespace std;
#define NAME "learning"
#define FOR(i,c) for(auto &i: c)
#define SZ(x) ((int)(x).size())
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
#define PLL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define EB emplace_back
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
const int INF = 2000000000;

int A, B;
int intersection(int a1, int b1) {
    return max(0, min(b1, B) - max(a1, A) + 1);
}

struct Cow {
    bool spot;
    int weight;
};

int main() {
#ifndef STDIO
  freopen(NAME".in", "r", stdin);
  freopen(NAME".out", "w", stdout);
#endif
  DRI(N);
  RII(A, B);
  V(Cow) cow(N);
  REP(i, N) {
    char s[3];
    RS(s);
    cow[i].spot = !s[1];
    RI(cow[i].weight);
  }
  sort(ALL(cow), [](const Cow &c1, const Cow &c2) {
    return c1.weight < c2.weight;
  });
  int ans = 0;
  if (cow[0].spot) {
    ans += intersection(1, cow[0].weight);
  }
  if (cow[N-1].spot) {
    ans += intersection(cow[N-1].weight, 1000000000);
  }
  REP(i, N-1) {
    if (cow[i].spot) {
        ans += intersection(cow[i].weight, (cow[i].weight + cow[i+1].weight - 1) / 2);
    }
    if (cow[i+1].spot) {
        ans += intersection((cow[i].weight + cow[i+1].weight) / 2 + 1, cow[i+1].weight);
    }
    if (cow[i].weight % 2 == cow[i+1].weight % 2 && (cow[i].spot || cow[i+1].spot)) {
        int m = (cow[i].weight + cow[i+1].weight) / 2;
        if (A <= m && m <= B)
            ans++;
    }
  }
  REP(i, N) {
    if (cow[i].spot && cow[i].weight >= A && cow[i].weight <= B)
        ans--;
  }
  PI(ans);
  return 0;
}