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
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
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

const int MOD = 1000000007;
struct Z {
  int i;
  Z():i(0) {}
  Z(int i): i(i) {}
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
      int q = d / a, r = d % a, t = x - q * s;
      d = a, a = r, x = s, s = t;
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

vector<int> suffix_array(char *t, int N)
{
    int A = 128;
    vector<int> sa(N), c(max(A, N)), rank(N), sa2(N);

    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<N; ++i) c[rank[i] = t[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=N-1; i>=0; --i)
        sa[--c[t[i]]] = i;
 
    for (int n=1; n<N; n*=2)
    {
        int r = 0;
        for (int i=N-n; i<N; ++i)
            sa2[r++] = i;
 
        for (int i=0; i<N; ++i)
            if (sa[i] >= n)
                sa2[r++] = sa[i] - n;
 
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<N; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        for (int i=N-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
 
        sa2[sa[0]] = r = 0;
        for (int i=1; i<N; ++i)
        {
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            sa2[sa[i]] = r;
        }
        swap(rank, sa2);
 
        if (r == N-1) break;
        A = r + 1;
    }
    return sa;
}

 
vector<int> lcp_array(char *s, const vector<int> &sa)
{
    int N = sa.size();
    vector<int> rank(N), lcpa(N);
    for (int i=0; i<N; ++i)
        rank[sa[i]] = i;
 
    for (int i=0, lcp=0; i<N; i++)
        if (rank[i] == 0)
            lcpa[0] = 0;
        else
        {
            int j = sa[rank[i]-1];
            if (lcp > 0) lcp--;
            while (s[i+lcp] == s[j+lcp]) lcp++;
            lcpa[rank[i]] = lcp;
        }
    return lcpa;
}

char A[100001], B[100001], C[200005];

int main() {
  DRI(T);
  while(T--) {
    RS(A); RS(B);
    int lc = 0, la = strlen(A), lb = strlen(B);
    REPL(i, A) C[lc++] = A[i];
    C[lc++] = 'Z'+1;
    REPL(i, B) C[lc++] = B[i];
    C[lc++] = 'Z'+1;
    auto sa = suffix_array(C, lc);
    VI ra(la), rb(lb);
    REP(i, lc) {
      if(sa[i] < la) ra[sa[i]] = i;
      else if(0 <= sa[i] - la - 1 && sa[i] - la - 1 < lb)
        rb[sa[i] - la - 1] = i;
    }
    int a = 0, b = 0, c = 0;
    while(A[a] && B[b]) {
      if(ra[a] < rb[b])
        C[c++] = A[a++];
      else
        C[c++] = B[b++];
    }
    while(A[a]) C[c++] = A[a++];
    while(B[b]) C[c++] = B[b++];
    C[c] = 0;
    puts(C);
  }
  return 0;
}