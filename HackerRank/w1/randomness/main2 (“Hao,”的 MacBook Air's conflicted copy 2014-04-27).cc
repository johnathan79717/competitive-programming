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
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

vector<int> suffix_array(char *t, int N)
{
    int A = 128;            // 計數排序法數值範圍
    vector<int> sa(N);
    vector<int> c(max(A, N)); // 計數排序法的計數陣列
    vector<int> rank(N); // 各個後綴對應的名次
    vector<int> sa2(N); // 各個名次對應的後綴後半段

    // 各個後綴第一個字元，實施計數排序法。
    // 然後累計次數，直接得到名次。
    // 從索引值最高的後綴開始處理，得到各個後綴對應的名次。
    // （偷懶取巧：直接把ASCII數值當作是名次。）
    for (int i=0; i<A; ++i) c[i] = 0;
    for (int i=0; i<N; ++i) c[rank[i] = t[i]]++;
    for (int i=1; i<A; ++i) c[i] += c[i-1];
    for (int i=N-1; i>=0; --i)
        sa[--c[t[i]]] = i;
 
    // 鍵值長度逐步倍增
    for (int n=1; n<N; n*=2)
    {
        // sa 是各個名次對應的後綴前半段
        // sa2是各個名次對應的後綴後半段
        // rank是各個後綴前半段對應的名次
 
        // sa與rank在上一回合就計算好了，現在要計算sa2。
        // 最後n個後綴的後半段，肯定都是空字串，名次最高。
        // 各個空字串依照索引值由小到大進行排名。
        int r = 0;  // 名次
        for (int i=N-n; i<N; ++i)
            sa2[r++] = i;
 
        // 其它的後綴的後半段，運用sa求得。
        for (int i=0; i<N; ++i)
            // 位置大於等於k，實際上才有前半段。
            if (sa[i] >= n)
                sa2[r++] = sa[i] - n;
 
        // 使用各個後綴的名次，實施計數排序法。
        // 從名次最高的後綴後半段開始處理，得到正確名次。
        for (int i=0; i<A; ++i) c[i] = 0;
        for (int i=0; i<N; ++i) c[rank[i]]++;
        for (int i=1; i<A; ++i) c[i] += c[i-1];
        for (int i=N-1; i>=0; --i)
            sa[--c[rank[sa2[i]]]] = sa2[i];
 
        // 暫且以sa2來儲存本回合的rank，
        // 然後計算下一回合的rank。
        // vector<int>& new_rank = sa2;
        sa2[sa[0]] = r = 0;
        for (int i=1; i<N; ++i)
        {
            // 相異者、排在相異名次，相同者、排在相同名次。
            // （偷懶取巧：因為最後n個後綴，
            // 上個回合就已經排序完畢，
            // 這些後綴長度不等、名次一定都相異，
            // 所以不會遇到sa[i-1]+n和sa[i]+n溢位。）
            if (!(rank[sa[i-1]] == rank[sa[i]] &&
                rank[sa[i-1]+n] == rank[sa[i]+n]))
                r++;
            sa2[sa[i]] = r;
        }
        swap(rank, sa2);
 
        // 如果名次皆相異，表示排序完畢，可以提早結束。
        if (r == N-1) break;
        // 修正一下計數排序法數值範圍
        A = r + 1;
    }
    return sa;
}

 
vector<int> lcp_array(char *s, const vector<int> &sa)
{
    int N = sa.size();
    vector<int> rank(N); // 各個後綴對應的名次
    // 也就是各個後綴在sa當中的索引值
    // 也就是sa的反函數
    vector<int> lcpa(N); // longest common prefix array
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

char S[75001];

LL get(int j, int i) {
  LL ret = 0;
  REP1(k, j, i)
    ret = (ret << 5) | (S[k] - 'a' + 1);
  return ret;
}

int main() {
  DRII(N, Q);
  RS(S);
  const int d = 6;
  VI suffix = suffix_array(S, N);
  VI lcp = lcp_array(S, suffix);
  LL ans = 0;
  REP(i, N)
    ans += (N - suffix[i] - lcp[i]);
  unordered_map<LL, int> map;
  REP(i, N) {
    REP1(j, max(i-d, 0), i) {
      map[get(j, i)]++;
    }
  }
  while(Q--) {
    DRI(P);
    char C[2]; RS(C);
    P--;
    REP1(j, max(0, P-d), P) {
      LL h = get(j, P-1);
      REP1(i, P, min(j + d, N-1)) {
        h = (h << 5) | (S[i] - 'a' + 1);
        if(--map[h] == 0)
          ans--;
      }
    }
    S[P] = C[0];
    REP1(j, max(0, P-d), P) {
      LL h = get(j, P-1);
      REP1(i, P, min(j + d, N-1)) {
        h = (h << 5) | (S[i] - 'a' + 1);
        if(map[h]++ == 0)
          ans++;
      }
    }
    PL(ans);
  }
  return 0;
}