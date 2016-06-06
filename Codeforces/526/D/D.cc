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
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <stack>
#include <functional>
#include <cassert>
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
#define GET_4TH(_1, _2, _3, NAME, ...) NAME
#define RI(argv...) GET_4TH(argv, RI3, RI2, RI1)(argv)
#define RI1(x) scanf("%d",&x)
#define RI2(x,y) RI1(x), RI1(y)
#define RI3(x,y,z) RI1(x), RI2(y, z)
#define DRI(argv...) int argv;RI(argv)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#ifdef ONLINE_JUDGE
    #define PL(x) printf("%I64d\n",x);
#else
    #define PL(x) printf("%lld\n",x)
#endif
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x>
#define DRA(A, N) VI A(N); REP(i, N) RI(A[i])
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;

#define MAX_N 1500000
// int sa[MAX_N];
// int c[MAX_N];
// int temp[2][MAX_N];

// void suffix_array(char *t, int N)
// {
//     int A = 128;            // 計數排序法數值範圍
//     int* rank = temp[0];    // 各個後綴對應的名次
//     int* sa2 = temp[1];     // 各個名次對應的後綴後半段
 
//     // 各個後綴第一個字元，實施計數排序法。
//     // 然後累計次數，直接得到名次。
//     // 從索引值最高的後綴開始處理，得到各個後綴對應的名次。
//     // （偷懶取巧：直接把ASCII數值當作是名次。）
//     for (int i=0; i<A; ++i) c[i] = 0;
//     for (int i=0; i<N; ++i) c[rank[i] = t[i]]++;
//     for (int i=1; i<A; ++i) c[i] += c[i-1];
//     for (int i=N-1; i>=0; --i)
//         sa[--c[t[i]]] = i;
 
//     // 鍵值長度逐步倍增
//     for (int n=1; n<N; n*=2)
//     {
//         // sa 是各個名次對應的後綴前半段
//         // sa2是各個名次對應的後綴後半段
//         // rank是各個後綴前半段對應的名次
 
//         // sa與rank在上一回合就計算好了，現在要計算sa2。
//         // 最後n個後綴的後半段，肯定都是空字串，名次最高。
//         // 各個空字串依照索引值由小到大進行排名。
//         int r = 0;  // 名次
//         for (int i=N-n; i<N; ++i)
//             sa2[r++] = i;
 
//         // 其它的後綴的後半段，運用sa求得。
//         for (int i=0; i<N; ++i)
//             // 位置大於等於k，實際上才有前半段。
//             if (sa[i] >= n)
//                 sa2[r++] = sa[i] - n;
 
//         // 使用各個後綴的名次，實施計數排序法。
//         // 從名次最高的後綴後半段開始處理，得到正確名次。
//         for (int i=0; i<A; ++i) c[i] = 0;
//         for (int i=0; i<N; ++i) c[rank[i]]++;
//         for (int i=1; i<A; ++i) c[i] += c[i-1];
//         for (int i=N-1; i>=0; --i)
//             sa[--c[rank[sa2[i]]]] = sa2[i];
 
//         // 暫且以sa2來儲存本回合的rank，
//         // 然後計算下一回合的rank。
//         int*& new_rank = sa2;
//         new_rank[sa[0]] = r = 0;
//         for (int i=1; i<N; ++i)
//         {
//             // 相異者、排在相異名次，相同者、排在相同名次。
//             // （偷懶取巧：因為最後n個後綴，
//             // 上個回合就已經排序完畢，
//             // 這些後綴長度不等、名次一定都相異，
//             // 所以不會遇到sa[i-1]+n和sa[i]+n溢位。）
//             if (!(rank[sa[i-1]] == rank[sa[i]] &&
//                 sa[i-1]+n < N &&
//                 rank[sa[i-1]+n] == rank[sa[i]+n]))
//                 r++;
//             new_rank[sa[i]] = r;
//         }
//         swap(rank, sa2);
 
//         // 如果名次皆相異，表示排序完畢，可以提早結束。
//         if (r == N-1) break;
//         // 修正一下計數排序法數值範圍
//         A = r + 1;
//     }
// }

// int lcpa[MAX_N];
 
// void lcp_array(char *s, int N)
// {
//     // 也就是各個後綴在sa當中的索引值
//     // 也就是sa的反函數
//     int *rank = temp[0];
//     for (int i=0; i<N; ++i)
//         rank[sa[i]] = i;
 
//     for (int i=0, lcp=0; i<N; i++)
//         if (rank[i] == 0)
//             lcpa[0] = 0;
//         else
//         {
//             int j = sa[rank[i]-1];
//             if (lcp > 0) lcp--;
//             while (s[i+lcp] == s[j+lcp]) {
//                 // assert(max(i, j) + lcp < N);
//                 lcp++;
//             }
//             lcpa[rank[i]] = lcp;
//         }
// }

int z[MAX_N];

void z_algorithm(char *s, int n) {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
}

char s[MAX_N];
int ans[MAX_N];

int main() 
{
    DRI(N, K);
    RS(s);
    if (K == 1) {
        REP(i, N) {
            s[i] = '1';
        }
        puts(s);
        return 0;
    }

    z_algorithm(s, N);
    REP1(p, 1, N-1) {
        int lcp = z[p];
        if ((LL)p * K <= p + lcp) {
            ans[p * K - 1]++;
            ans[min(p + lcp, p * (K+1))]--;
        }
    }

    // auto sa = suffix_array(s, N);
    // auto lcpa = lcp_array(s, sa);
    // suffix_array(s, N);
    // lcp_array(s, N);
    // int i = 0;
    // while (i < N) {
    //     if (sa[i] == 0)
    //         break;
    //     i++;
    // }
    // int j = i+1, lcp = N;
    // while (j < N) {
    //     lcp = min(lcp, lcpa[j]);
    //     LL p = sa[j];
    //     // REP1(k, p * K - 1, min(p + lcp - 1, p * (K+1) - 1)) {
    //     //     ans[k] = 1;
    //     // }
    //     if (p * K <= p + lcp) {
    //         ans[p * K - 1]++;
    //         ans[min(p + lcp, p * (K+1))]--;
    //     }
    //     j++;
    // }
    // j = i-1, lcp = N;
    // while (j >= 0) {
    //     lcp = min(lcp, lcpa[j+1]);
    //     LL p = sa[j];
    //     // REP1(k, p * K - 1, min(p + lcp - 1, p * (K+1) - 1)) {
    //     //     ans[k] = 1;
    //     // }
    //     if (p * K <= p + lcp) {
    //         ans[p * K - 1]++;
    //         ans[min(p + lcp, p * (K+1))]--;
    //     }
    //     j--;
    // }

    REP(i, N) {
        // ans[i] += '0';
        assert(ans[i] >= 0);
        ans[i+1] += ans[i];
        if (ans[i])
            s[i] = '1';
        else
            s[i] = '0';
    }
    puts(s);
    return 0;
}

