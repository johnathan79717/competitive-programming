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

    char s[100005+1];
    int sa[100005];
    int temp[2][100005];
    int N;
     
    struct CMP
    {
        int* rnk, n, N;
        bool operator()(const int& i, const int& j)
        {
            // 先比前半段，再比後半段。
            if (rnk[i] != rnk[j])
                return rnk[i] < rnk[j];
            int a = (i+n<N) ? rnk[i+n] : -1;
            int b = (j+n<N) ? rnk[j+n] : -1;
            return a < b;
        }
    };
     
    void suffix_array()
    {
        int* rnk = temp[0];
        int* new_rank = temp[1];
     
        for (int i=0; i<N; i++)
        {
            // 各個名次對應的後綴
            // 隨便初始化一個順序，稍後會重新排序。
            sa[i] = i;
            // 各個後綴對應的名次
            // 偷懶取巧：直接把ASCII數值當作是名次。
            rnk[i] = s[i];
        }
     
        // 鍵值長度逐步倍增
        for (int n=1; n<N; n*=2)
        {
            // 運用上一回合求得的名次，排序所有後綴。
            // 鍵值是每個後綴的前2*n個字元，
            // 先比前半段、再比後半段。
            CMP cmp = {rnk, n, N};
            sort(sa, sa+N, cmp);
     
            // 重新整理名次。
            // 相異者、排在相異名次，相同者、排在相同名次。
            int r = 0;
            new_rank[sa[0]] = r;
            for (int i=1, r=0; i<N; i++)
            {
                if (cmp(sa[i-1], sa[i])) r++;
                new_rank[sa[i]] = r;
            }
            swap(rnk, new_rank);
     
            // 如果名次皆相異，表示排序完畢，可以提早結束。
            if (r == N-1) break;
        }
    }
     
    int rnk[100005];   // 各個後綴對應的名次
    int lcpa[100005];   // longest common prefix array
     
    void lcp_array()
    {
        // 也就是各個後綴在sa當中的索引值
        // 也就是sa的反函數
        for (int i=0; i<N; ++i)
            rnk[sa[i]] = i;
     
        for (int i=0, lcp=0; i<N; i++)
            if (rnk[i] == 0)
                lcpa[0] = 0;
            else
            {
                int j = sa[rnk[i]-1];
                if (lcp > 0) lcp--;
                while (s[i+lcp] == s[j+lcp]) lcp++;
                lcpa[rnk[i]] = lcp;
            }
    }


LL f(LL a, LL b) {
  return (a + b + 1) * (b - a) / 2;
}

int main() {
  DRI(T);
  while(T--) {
    MS0(s);
    RS(s);
    DRL(K);
    K--;
    N = strlen(s);
    suffix_array();
    lcp_array();
    int i;
    for(i = 0; i < N; i++) {
      LL ff = f(lcpa[i], N - sa[i]);
      if(K < ff)
        break;
      K -= ff;
    }
    int j = lcpa[i] + 1;
    while(K >= j) {
      K -= j;
      j++;
    }
    printf("%c\n", s[sa[i] + K]);
  }
  return 0;
}