#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define FOR(i,c) for(auto &i: c)
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

bool isprime[10001];

int main() {
    MS1(isprime);
    VI primes;
    REP1(p, 2, 10000) {
        if (isprime[p]) {
            primes.PB(p);
            for(int k = p*2; k <= 10000; k += p) {
                isprime[k] = false;
            }
        }
    }
    DRI(T);
    while(T--) {
        DRI(N);
        V(list<int>) f(N);
        VI u;
        REP(i, N) {
            DRI(a);
            FOR(p, primes) {
                if (p * p > a) break;
                int k = 0;
                while (a % p == 0) {
                    a /= p;
                    k++;
                }
                if (k % 2) {
                    f[i].PB(p);
                    u.PB(p);
                }
            }
            if (a > 1) {
                f[i].PB(a);
                u.PB(a);
            }
        }
        sort(ALL(u));
        u.resize(unique(ALL(u)) - u.begin());
        V(VI) A(N, VI(u.size()));
        REP(i, N) {
            FOR(p, f[i]) {
                int j = lower_bound(ALL(u), p) - u.begin();
                assert(j < u.size());
                A[i][j] = 1;
            }
        }
        int rank = 0;
        for(int i = 0; i < SZ(u); i++) {
            for(int j = rank; j < N; j++) {
                if(A[j][i]) {
                    swap(A[rank], A[j]);
                    break;
                }
            }
            if(!A[rank][i]) {
                continue;
            }
            for(int j = rank+1; j < N; j++) {
                if(A[j][i]) {
                    for(int k = i; k < SZ(u); k++)
                        A[j][k] ^= A[rank][k];
                }
            }
            rank++;
            if (rank == N) {
                break;
            }
        }
        PL(1ll << rank);
    }
  return 0;
}