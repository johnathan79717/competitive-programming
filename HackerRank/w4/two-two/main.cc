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

int N = 801;   // P的個數
char T[100005];

struct TrieNode
{
  TrieNode* l[10], *suffix, *dictsuffix;
  int index;  // P的編號
 
  TrieNode()
  {
    memset(l, 0, sizeof(l));
    suffix = dictsuffix = 0;
    index = -1;
  }
} *root;
 
// 初始化
void init()
{
  root = new TrieNode();
}
 
// 砍掉整棵trie
void free(TrieNode* p = root)
{
  for (int i=0; i<10; ++i)
    if (p->l[i])
      free(p->l[i]);
  delete p;
}
 
// 把一個字串加入trie
void add(char* s, int index)
{
  TrieNode* p = root;
  for (; *s; ++s)
  {
    if (!p->l[*s - '0'])
      p->l[*s - '0'] = new TrieNode();
    p = p->l[*s - '0'];
  }
 
  // 如果此字串之前有出現，就特別紀錄起來。
  p->index = index;
}
 
// 添上suffix link和dictionary suffix link
// 以BFS順序進行
// 時間複雜度O(Σ(Pi))
TrieNode* q[100000], **qf, **qb;
void build()
{
  qf = qb = q;
  *qb++ = root;
 
  while (qf < qb)
  {
    TrieNode* p = *qf++;
    for (int i=0; i<10; ++i)
      if (p->l[i])
      {
        // 添上 suffix link
        TrieNode* q = p->suffix;
        while (q && !q->l[i]) q = q->suffix;
        if (q) p->l[i]->suffix = q->l[i];
        else   p->l[i]->suffix = root;
 
        // 添上 dictionary suffix link
        TrieNode* r = p->l[i]->suffix;
        if (r->index != -1) p->l[i]->dictsuffix = r;
        else p->l[i]->dictsuffix = r->dictsuffix;
 
        *qb++ = p->l[i];
      }
  }
}
 
// 拿trie與T進行字串匹配
// 時間複雜度O(T+K)
int match(char* s)
{
  TrieNode* p = root;
  int ans = 0;
  for (; *s; ++s)
  {
    // 不斷比對字元，直到比對成功。
    // 此部分總計時間複雜度為O(T)。
    while (p && !p->l[*s - '0']) p = p->suffix;
    if (p) p = p->l[*s - '0'];
    else p = root;
 
    // 走dictionary suffix link找到所有匹配的P。
    // 此部分總計時間複雜度為O(K)。
    for (TrieNode* q = p; q; q = q->dictsuffix)
      if (q->index != -1)
        ans++;
  }
  return ans;
}
 
char P[801][245];

void aho_corasick()
{
  init();     // 初始化
  for (int i=0; i<N; ++i) // 所有P建立trie
    add(P[i], i);
  build();    // suffix link、dictionary suffix link
  DRI(t);
  while(t--) {
    RS(T);
    PI(match(T));   // 拿trie與T進行字串匹配
  }
  free();     // 釋放記憶體空間
}


int main() {
  P[0][0] = '1';
  REP(i, 800) {
    REPL(j, P[i]) {
      if(!P[i+1][j]) P[i+1][j] = '0';
      P[i+1][j] += (P[i][j] - '0') * 2;
      if(P[i+1][j] > '9') {
        P[i+1][j] -= 10;
        P[i+1][j+1] = '1';
      }
    }
  }
  REP(i, 801) reverse(P[i], P[i]+strlen(P[i]));
  aho_corasick();
  return 0;
}