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

int N = 1000;   // P的個數
int M;
char T[100+1];
char P[1000][100+1];
 
bool occur[1000];   // 紀錄各個P有沒有出現在T當中
 
struct TrieNode
{
  TrieNode *suffix, *dictsuffix;
  list<pair<pair<int,int> >, TrieNode*> l;
  int index;  // P的編號
 
  TrieNode(): l()
  {
    // memset(l, 0, sizeof(l));
    suffix = dictsuffix = 0;
    index = -1;
  }
} pool[1000005], *root;
 
TrieNode *getNode() {
    static int i = 0;
    return pool[i++];
}

// 初始化
void init()
{
  memset(occur, false, sizeof(occur));
  REP(i, 1000005) {
    pool[i] = TrieNode();
  }
  // root = new TrieNode();
  root = getNode();
}
 
// 砍掉整棵trie
// void free(TrieNode* p = root)
// {
//   for (int i=0; i<26; ++i)
//     if (p->l[i])
//       free(p->i[i]);
//   delete p;
// }
 
// 把一個字串加入trie
void add(char* s, int index)
{
  TrieNode* p = root;
  for (; *s; ++s)
  {
    if (!p->l[*s - 'A'])
      p->l[*s - 'A'] = new TrieNode();
    p = p->l[*s - 'A'];
  }
 
  // 如果此字串之前有出現，就特別紀錄起來。
  if (p->index == -1)
    p->index = index;
  else
    equiv[index] = p->index;
}
 
// 添上suffix link和dictionary suffix link
// 以BFS順序進行
// 時間複雜度O(Σ(Pi))
void build()
{
  TrieNode* q[100000], **qf, **qb;
  qf = qb = q;
  *qb++ = root;
 
  while (qf < qb)
  {
    TrieNode* p = *qf++;
    for (int i=0; i<26; ++i)
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
void match(char* s)
{
  TrieNode* p = root;
  for (; *s; ++s)
  {
    // 不斷比對字元，直到比對成功。
    // 此部分總計時間複雜度為O(T)。
    while (p && !p->l[*s - 'A']) p = p->suffix;
    if (p) p = p->l[*s - 'A'];
    else p = root;
 
    // 走dictionary suffix link找到所有匹配的P。
    // 此部分總計時間複雜度為O(K)。
    for (TrieNode* q = p; q; q = q->dictsuffix)
      if (q->index != -1)
        occur[q->index] = true;
  }
}
 
void aho_corasick()
{
  init();     // 初始化
  for (int i=0; i<N; ++i) // 所有P建立trie
    add(P[i], i);
  build();    // suffix link、dictionary suffix link
  match(T);   // 拿trie與T進行字串匹配
  free();     // 釋放記憶體空間
 
  for (int i=0; i<N; ++i)
    // 匹配到P，或者之前出現過、匹配到P。
    if (occur[i] ||
      equiv[i] != -1 && occur[equiv[i]])
      cout << "第" << i << "個字串有出現";
    else
      cout << "第" << i << "個字串沒出現";
}

int main() {
    CASET {
        RII(N, M);
        VI A(N);
        REP(i, N) RI(A[i]);
    }
    return 0;
}
