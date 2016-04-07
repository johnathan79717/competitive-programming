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

char t[100001];   // 要處理的字串
char s[100001 * 2]; // 中間插入特殊字元的t。
int Z[100001 * 2], L, R;  // Gusfield's Algorithm
int N;

// 由a往左、由b往右，對稱地作字元比對。
int match(int a, int b)
{
  int i = 0;
  while (a-i>=0 && b+i<N && s[a-i] == s[b+i]) i++;
  return i;
}

void longest_palindromic_substring()
{
  // 在t中插入特殊字元，存放到s。
  memset(s, '.', N*2+1);
  for (int i=0; i<N; ++i) s[i*2+1] = t[i];
  N = N*2+1;

  // modified Gusfield's lgorithm
  Z[0] = 1;
  L = R = 0;
  for (int i=1; i<N; ++i)
  {
    int ii = L - (i - L); // i的映射位置
    int n = R + 1 - i;

    if (i > R)
    {
      Z[i] = match(i, i);
      L = i;
      R = i + Z[i] - 1;
    }
    else if (Z[ii] == n)
    {
      Z[i] = n + match(i-n, i+n);
      L = i;
      R = i + Z[i] - 1;
    }
    else
    {
      Z[i] = min(Z[ii], n);
    }
  }

  // // 尋找最長迴文子字串的長度。
  // int n = 0, p = 0;
  // for (int i=0; i<N; ++i)
  //   if (Z[i] > n)
  //     n = Z[p = i];

  // // 記得去掉特殊字元。
  // cout << "最長迴文子字串的長度是" << (n-1) / 2;

  // // 印出最長迴文子字串，記得別印特殊字元。
  // for (int i=p-Z[p]+1; i<=p+Z[p]-1; ++i)
  //   if (i & 1)
  //     cout << s[i];
}

int main() {
  while(scanf("%s", t) != EOF) {
    N = strlen(t);
    longest_palindromic_substring();
    int M = (N-1) / 2;
    bool success = false;
    REP1(i, 1, M-1) {
      int l1 = Z[i]-1;
      int l2 = Z[N-1-(M-i)]-1;
      if(l1 + l2 == M)
        success = true;
    }
    if(success)
      puts("www");
    else
      puts("vvvvvv");
  }
  return 0;
}
