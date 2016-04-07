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

char S[200005];

int main() {
  DRI(T);
  REP(t, T) {
    RS(S);
    
  }
  return 0;
}
