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

LL gcd(LL p, LL q) {
    if (!p) return q;
    return gcd(q % p, p);
}

struct Rational {
    LL q, p;
    Rational() {}
    Rational(LL qq, LL pp): q(qq), p(pp) {
        assert(p > 0);
        LL d = gcd(abs(q), p);
        p /= d;
        q /= d;
    }
};

Rational operator-(const Rational &r1, const Rational &r2) {
    return Rational(r1.q * r2.p - r2.q * r1.p, r1.p * r2.p);
}

Rational operator+(const Rational &r1, const Rational &r2) {
    return Rational(r1.q * r2.p + r2.q * r1.p, r1.p * r2.p);
}

bool operator>=(const Rational &r1, const Rational &r2) {
    return (__int128)r1.q * r2.p >= (__int128)r2.q * r1.p;
}

bool operator<=(const Rational &r1, const Rational &r2) {
    return (__int128)r1.q * r2.p <= (__int128)r2.q * r1.p;
}

Rational operator*(const Rational &r1, const Rational &r2) {
    return Rational(r1.q * r2.q, r1.p * r2.p);
}

Rational eval(const pair<Rational,Rational> &line, LL t) {
    Rational tt(t, 1);
    return line.F * tt + line.S;
}

struct Query
{
    LL q;
    int i;
    Rational ans;
};

// pair<Rational, Rational> dq[100001];

int main() {
    DRI(T);
    while(T--) {
        DRII(N, K);
        vector<pair<int,int>> A(N);
        REP(i, N) {
            RII(A[i].F, A[i].S);
        }
        sort(ALL(A), greater<PII>());
        // sort(ALL(A));
        deque<pair<Rational, Rational>> dq;
        int p = 0;
        FOR(a, A) {
            assert(a.F != 0);
            dq.push_front(MP(Rational(1, a.F), Rational(a.S, 1)));
            // dq[p++] = MP(Rational(1, a.F), Rational(a.S, 1));
            while (dq.size() >= 3 &&
                            (dq[0].S - dq[1].S) * (dq[2].F - dq[1].F) >= (dq[1].S - dq[2].S) * (dq[1].F - dq[0].F)) {
                dq[1] = dq[0];
                dq.pop_front();
            }
            // while (p >= 3 &&
            //                 (dq[p-3].S - dq[p-2].S) * (dq[p-1].F - dq[p-2].F) >= (dq[p-2].S - dq[p-1].S) * (dq[p-2].F - dq[p-3].F)) {
            //     dq[p-2] = dq[p-1];
            //     p--;
            // }

        }
        // PI(dq.size());
        V(Query) M(K);
        REP(i, K) {
            RL(M[i].q);
            M[i].i = i;
        }
        sort(ALL(M), [](Query const &q1, Query const &q2) {
            return q1.q < q2.q;
        });
        int j = 0;
        REP(i, K) {
            while (SZ(dq) >= 2 && eval(dq[0], M[i].q) >= eval(dq[1], M[i].q)) {
                dq.pop_front();
            }
            M[i].ans = eval(dq[0], M[i].q);
            // while (j+1 < p && eval(dq[j], M[i].q) >= eval(dq[j+1], M[i].q)) {
            //     j++;
            // }
            // M[i].ans = eval(dq[j], M[i].q);
        }
        sort(ALL(M), [](Query const &q1, Query const &q2) {
            return q1.i < q2.i;
        });
        REP(i, K) {
            assert(M[i].ans.p > 0);
            printf("%lld/%lld\n", M[i].ans.q, M[i].ans.p);
        }
    }
  return 0;
}