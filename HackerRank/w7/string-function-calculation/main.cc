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

struct CMP
{
    int *rank, n, N;
    CMP(int *r, int n, int N): rank(r), n(n), N(N) {}
    bool operator()(const int& i, const int& j)
    {
        // 先比前半段，再比後半段。
        if (rank[i] != rank[j])
            return rank[i] < rank[j];
        int a = (i+n<N) ? rank[i+n] : -1;
        int b = (j+n<N) ? rank[j+n] : -1;
        return a < b;
    }
};
     
vector<int> suffix_array(char *t, int N)
{
    // int* rank = temp[0];
    // int* new_rank = temp[1];
    int *rank = new int[N], *new_rank = new int[N];
    vector<int> sa(N);
 
    for (int i=0; i<N; i++)
    {
        // 各個名次對應的後綴
        // 隨便初始化一個順序，稍後會重新排序。
        sa[i] = i;
        // 各個後綴對應的名次
        // 偷懶取巧：直接把ASCII數值當作是名次。
        rank[i] = t[i];
    }
 
    // 鍵值長度逐步倍增
    for (int n=1; n<N; n*=2)
    {
        // 運用上一回合求得的名次，排序所有後綴。
        // 鍵值是每個後綴的前2*n個字元，
        // 先比前半段、再比後半段。
        CMP cmp(rank, n, N);
        sort(sa.begin(), sa.end(), cmp);
        // for(int i = 0; i < sa.size(); i++) printf("%d\n", sa[i]);
        // 重新整理名次。
        // 相異者、排在相異名次，相同者、排在相同名次。
        int r = 0;
        new_rank[sa[0]] = r;
        for (int i=1, r=0; i<N; i++)
        {
            if (cmp(sa[i-1], sa[i])) r++;
            new_rank[sa[i]] = r;
        }
        swap(rank, new_rank);
 
        // 如果名次皆相異，表示排序完畢，可以提早結束。
        if (r == N-1) break;
    }
    delete rank;
    delete new_rank;
    return move(sa);
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

char s[100005];

int main() {
  RS(s);
  int N = strlen(s);
  auto sa = suffix_array(s, N);
  // suffix_array();
  // lcp_array();
  auto lcpa = lcp_array(s, sa);
  stack<pair<int, int> > stack;
  LL ans = N;
  REP(i, N) {
    while(!stack.empty() && stack.top().F >= lcpa[i]) {
      int h = stack.top().F;
      stack.pop();
      if(stack.empty()) {
        ans = max(ans, (LL)h * (i));
      } else {
        ans = max(ans, (LL)h * (i - stack.top().S));
      }
    }
    stack.emplace(lcpa[i], i);
  }
  while(!stack.empty()) {
    int h = stack.top().F;
    stack.pop();
    if(stack.empty()) {
      ans = max(ans, (LL)h * N);
    } else {
      ans = max(ans, (LL)h * (N - stack.top().S));
    }
  }
  PL(ans);
  return 0;
}