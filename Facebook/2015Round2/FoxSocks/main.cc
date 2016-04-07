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
#include <sstream>
#include <bitset>
using namespace std;
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define LEN(X) strlen(X)
#define BG begin()
#define ED end()
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

const int MOD = 1000000000;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i >= 0 ? i : i + MOD) {}
  void operator +=(const Z& z) { i += z.i; if(i >= MOD) i -= MOD; }
  void operator -=(const Z& z) { i -= z.i; if(i < 0) i += MOD; }
  void operator *=(const Z& z) { i = (LL) i * z.i % MOD; }
  void operator /=(const Z& z) { (*this) *= z.inverse(); }
  Z operator +(const Z& z) const { Z ret(i); ret += z; return ret; }
  Z operator -(const Z& z) const { Z ret(i); ret -= z; return ret; }
  Z operator *(const Z& z) const { Z ret(i); ret *= z; return ret; }
  Z operator /(const Z& z) const { return (*this) * z.inverse(); }
  // Z operator -() const { return Z(-i); }
  Z inverse() const {
    int a = i, d = MOD, x = 0, s = 1;
    while(a) {
      int q = d / a, r = d % a, Data = x - q * s;
      d = a, a = r, x = s, s = Data;
    }
    if (d != 1) return -1;
    return x < 0 ? x + MOD : x;
  }
  Z pow(int b) {
    Z x=1,y=*this; // ll is taken to avoid overflow of intermediate results
    while(b > 0){
      if(b%2 == 1)
        x *= y;
      y *= y; // squaring the base
      b /= 2;
    }
    return x;
  }
};

vector<Z> factorial(1, 1), inv_factorial(1, 1);

Z inv_fact(int n) {
  while(inv_factorial.size() <= n)
    inv_factorial.push_back(inv_factorial.back() / inv_factorial.size());
  return inv_factorial.at(n);
}

Z fact(int n) {
  while(factorial.size() <= n)
    factorial.push_back(factorial.back() * factorial.size());
  return factorial.at(n);
}

Z choose(int n, int k) {
  if(n < k) return 0;
  return fact(n) * (inv_fact(k) * inv_fact(n-k));
}

struct Data {
    LL sum;
    int p[2][2];
    Data(): sum(0) {
        REP(i, 2) REP(j, 2) p[i][j] = 0;
    }
};

struct Lazy {
    LL C, D;
    bool clear;
    Lazy(): C(0), D(0), clear(false) {}
};

int S[1000001];

struct SegmentTree {
  // static Data identity;
  int n;
  vector<Data> dat;
  vector<Lazy> lazy;

  SegmentTree(int n_) {
    n = 1;
    while(n < n_) n *= 2;
    dat.resize(2*n-1);
    lazy.resize(2*n-1);
    init(0, 0, n);
  }

  void init(int k, int l, int r) {
    if(r - l == 1) {
        dat[k].sum = S[l+1];
        dat[k].p[l%2][S[l+1]%2] = 1;
    } else {
      // non-leaf
      int chl = k * 2 + 1, chr = k * 2 + 2;
      init(chl, l, (l + r) / 2);
      init(chr, (l + r) / 2, r);
      dat[k].sum = (dat[chl].sum + dat[chr].sum) % MOD;
      REP(i, 2) {
        REP(j, 2) {
            dat[k].p[i][j] = dat[chl].p[i][j] + dat[chr].p[i][j];
        }
      }
    }
  }

    void update(int a, int b, bool clear, LL c, LL d) {
        update(a, b, 0, 0, n, clear, c, d);
    }

    void propagate(int k, bool clear, LL c, LL d) {
        // propagate(k, lazy[k].clear, lazy[k].C, lazy[k].D);
        REP1(i, 2*k+1, 2*k+2) {
            if (!clear) {
                lazy[i].C += c;
                lazy[i].D += d;
            } else {
                lazy[i].clear = clear;
                lazy[i].C = c;
                lazy[i].D = d;
            }
        }
    }

    void apply(Data &dat, bool clear, LL C, LL D, int l, int r) {
      if (clear) {
          dat.sum = (C + D * l + C + D * (r-1)) * (r-l) / 2 % MOD;
          int p0 = dat.p[0][0] + dat.p[0][1], p1 = dat.p[1][0] + dat.p[1][1];
          REP(i, 2) REP(j, 2) dat.p[i][j] = 0;
          if (D % 2 == 0) {
              dat.p[0][C % 2] = p0;
              dat.p[1][C % 2] = p1;
          } else {
              dat.p[0][C % 2] = p0;
              dat.p[1][1-C%2] = p1;    
          }
      } else {
          dat.sum += (C + D * l + C + D * (r-1)) * (r-l) / 2 % MOD;
          if (D % 2 == 0) {
              if (C % 2) {
                  swap(dat.p[0][0], dat.p[0][1]);
                  swap(dat.p[1][0], dat.p[1][1]);
              }
          } else {
              if (C % 2) {
                  swap(dat.p[0][0], dat.p[0][1]);
              } else {
                  swap(dat.p[1][0], dat.p[1][1]);
              }
          }
      } 
    }

    void update(int a, int b, int k, int l, int r, bool clear, LL C, LL D) {
        // if (lazy[k]) {
        //     rotate(dat[k], lazy[k]);
        //     if (r - l > 1) {
        //         propagate(k, lazy[k]);
        //     }
        //     lazy[k] = 0;
        // }
        apply(dat[k], lazy[k].clear, lazy[k].C, lazy[k].D, l, r);
        if (r - l > 1) {
            propagate(k, lazy[k].clear, lazy[k].C, lazy[k].D);
        }
        lazy[k].clear = false;
        lazy[k].C = lazy[k].D = 0;

        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            // rotate(dat[k], d);
            apply(dat[k], clear, C, D, l, r);
            if (r - l > 1) {
                propagate(k, clear, C, D);
            }
        } else {
            update(a, b, k*2+1, l, (l+r)/2, clear, C, D);
            update(a, b, k*2+2, (l+r)/2, r, clear, D, D);
            int chl = k * 2 + 1, chr = k * 2 + 2;
            dat[k].sum = dat[chl].sum + dat[chr].sum;
            REP(i, 2) {
              REP(j, 2) {
                  dat[k].p[i][j] = dat[chl].p[i][j] + dat[chr].p[i][j];
              }
            }
        }
    }

    Data query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    Data query(int a, int b, int k, int l, int r) {
        // if [a, b) and [l, r) are disjoint
        if(r <= a || b <= l) return Data();
        apply(dat[k], lazy[k].clear, lazy[k].C, lazy[k].D, l, r);
        if (r - l > 1) propagate(k, lazy[k].clear, lazy[k].C, lazy[k].D);
        lazy[k].clear = false;
        lazy[k].C = lazy[k].D = 0;
        // if [l, r) contains [a, b)
        if(a <= l && r <= b) {
            return dat[k];
        }
        else {
            Data vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            Data vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            Data ans;
            int chl = k * 2 + 1, chr = k * 2 + 2;
            ans.sum = dat[chl].sum + dat[chr].sum;
            REP(i, 2) {
              REP(j, 2) {
                  ans.p[i][j] = dat[chl].p[i][j] + dat[chr].p[i][j];
              }
            }
            return ans;
        }
    }
};

const int MAX = 1000005;
int o[MAX], a[MAX], b[MAX], c[MAX], d[MAX];

int main() {
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d: ", cas++);
        DRII(N, M);
        DRII(S1, S2); DRIII(X, Y, Z);
        S[1] = S1, S[2] = S2;
        REP1(i, 3, N) {
            S[i] = ((LL)X * S[i-2] + (LL)Y * S[i-1] + Z) % MOD;
        }
        RII(S1, S2); RIII(X, Y, Z);
        o[1] = S1, o[2] = S2;
        REP1(i, 3, M) {
            o[i] = ((LL)X * o[i-2] + (LL)Y * o[i-1] + Z) % 4 + 1;
        }
        RII(S1, S2); RIII(X, Y, Z);
        a[1] = S1, a[2] = S2;
        REP1(i, 3, M) {
            a[i] = ((LL)X * a[i-2] + (LL)Y * a[i-1] + Z) % N + 1;
        }
        RII(S1, S2); RIII(X, Y, Z);
        b[1] = S1, b[2] = S2;
        REP1(i, 3, M) {
            b[i] = ((LL)X * b[i-2] + (LL)Y * b[i-1] + Z) % N + 1;
        }
        RII(S1, S2); RIII(X, Y, Z);
        c[1] = S1, c[2] = S2;
        REP1(i, 3, M) {
            c[i] = ((LL)X * c[i-2] + (LL)Y * c[i-1] + Z) % MOD;
        }
        RII(S1, S2); RIII(X, Y, Z);        
        d[1] = S1, d[2] = S2;
        REP1(i, 3, M) {
            d[i] = ((LL)X * d[i-2] + (LL)Y * d[i-1] + Z) % MOD;
        }
        SegmentTree st(N);
        LL ans = 0;
        REP1(i, 1, M) {
            int O = o[i], A = a[i] - 1, B = b[i] - 1;
            LL C = c[i], D = d[i];
            switch(O) {
                case 1: {
                    if (A <= B) {
                        st.update(A, B+1, false, C - D * A, D);
                        ans += ((C + C + (B-A) * D) * (B - A + 1) / 2);
                        // PL((C + C + (B-A) * D) * (B - A + 1) / 2);
                    } else {
                        st.update(A, N, false, C - D * A, D);
                        st.update(0, B+1, false, C + D * A, D);
                    }
                    break;
                }
                case 2: {
                    if (A <= B) {
                        Data dat = st.query(A, B+1);
                        // PL(dat.sum);
                        ans += (dat.sum);
                        st.update(A, B+1, true, C, 0);
                        // PL(C * (B - A + 1));
                        ans += (C * (B - A + 1));
                    } else {
                        Data dat1 = st.query(A, N), dat2 = st.query(0, B+1);
                        // PL((dat1.sum + dat2.sum));
                        ans += ((dat1.sum + dat2.sum));
                        st.update(A, N, true, C, 0);
                        st.update(0, B+1, true, C, 0);
                        // PL(C * (N-A + B+1));
                        ans += (C * (N-A + B+1));
                    }
                    break;               
                }
                case 3: {
                    if (A <= B) {
                        Data dat = st.query(A, B+1);
                        // PL(dat.sum);
                        ans += (dat.sum);
                    } else {
                        Data dat1 = st.query(A, N), dat2 = st.query(0, B+1);
                        // PL((dat1.sum + dat2.sum));
                        ans += ((dat1.sum + dat2.sum));
                    }
                    break;
                }
                case 4: {
                    if (A <= B) {
                        Data dat = st.query(A, B+1);
                        // PI(dat.p[0][1] + dat.p[1][1]);
                        ans += (dat.p[0][1] + dat.p[1][1]);
                    } else {
                        Data dat1 = st.query(A, N), dat2 = st.query(0, B+1);
                        // PI(dat1.p[0][1] + dat1.p[1][1] + dat2.p[0][1] + dat2.p[1][1]);
                        ans += (dat1.p[0][1] + dat1.p[1][1] + dat2.p[0][1] + dat2.p[1][1]);
                    }                    
                    break;
                }
                default: assert(false);
            }
            ans %= MOD;
        }
        PL(ans);
    }
}