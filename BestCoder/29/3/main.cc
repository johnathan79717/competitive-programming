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
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
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
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

const int B = 1000;

struct Query
{
    int L, R, i;
    bool ans;
};

VI A;
int freq[1000001];
// set<int> all;

// index starts with 1
template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    i = min(i, (int)bit.size()-1);
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

BIT<int> occur;

void add(int i) {
    int a = A[i];
    if (freq[a] == 0) {
        occur.add(a, 1);
    }
    // all.insert(a);
    freq[a]++;
}

void remove(int i) {
    int a = A[i];
    freq[a]--;
    if (freq[a] == 0) {
        occur.add(a, -1);
    }
    // all.erase(a);
}

bool cp1(const Query &q1, const Query &q2) {
    if (q1.L / B != q2.L / B) {
        return q1.L / B < q2.L / B;
    } else if (q1.L / B % 2) {
        return q1.R > q2.R;
    }
    return q1.R < q2.R;
}

bool cp2(const Query &q1, const Query &q2) {
    return q1.i < q2.i;
}

int main() {
    int N, M;
    while (RII(N, M) != EOF) {
        A = VI(N+1);
        MS0(freq);
        occur = BIT<int>(N);
        // all.clear();
        REP1(i, 1, N) RI(A[i]);
        V(Query) query(M);
        REP(i, M) {
            RII(query[i].L, query[i].R);
            query[i].i = i;
        }
        sort(ALL(query), cp1);
        int l = 1, r = 0;
        FOR(q, query) {
            while(r < q->R) {
                add(++r);
            }
            while(l > q->L) {
                add(--l);
            }
            while(r > q->R) {
                remove(r--);
            }
            while(l < q->L) {
                remove(l++);
            }
            q->ans = occur.sum(q->R - q->L + 1) == q->R - q->L + 1;
        }
        sort(ALL(query), cp2);
        FOR(q, query) {
            puts(q->ans ? "YES" : "NO");
        }
    }
    return 0;
}
