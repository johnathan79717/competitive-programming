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

#include <cstring>

// 該節點上方的樹枝，儲存s[a,b)的字元。
struct Node
{
    int a, b;
    Node* l[28], *suffix, *parent;
    bool visited;
    int start1, start2, depth;
    Node(int a, int b): a(a), b(b), suffix(0), visited(false), start1(1e9), start2(1e9)
    {
        memset(l, 0, sizeof(l));
    }
};
 
Node *Ukkonen(VI &s)
{
    Node* root = new Node(0, 0);
    Node* p = root;
    int a = 0;
 
    // 逐次加入字元s[i]。包含'\0'。
  // FOR(s, v) {
    for (int i=0; i<s.size(); ++i)
    {
        Node* ant = root;
        while (a <= i)
        {
            // 往下走，直到字元s[i-1]出現。
            while (true)
            {
                if (a == i) break;
                Node* q = p->l[s[a]];
                if (a + q->b - q->a > i) break;
                a += q->b - q->a;
                p = q;
            }
 
            Node* q = p;
            if (a == i)     // s[i-1]位在樹枝末梢。
            {
                // 節點已經建立。
                if (p->l[s[i]]) break;
            }
            else if (a < i) // s[i-1]位在樹枝中間。
            {
                // 節點已經建立。
                Node* r = p->l[s[a]];
                int k = r->a + i - a;
                if (s[i] == s[k]) break;
 
                // 節點尚未建立。
                // 分裂此樹枝，以利將來插入樹葉。
                p->l[s[a]] = q = new Node(r->a, k);
                q->l[s[k]] = r; r->a = k;
            }
 
            // 建立樹葉。終身為葉。
            q->l[s[i]] = new Node(i, 1e9);
 
            // 建立上次樹葉的suffix link，連到這次樹葉。
            // 至於這次樹葉的suffix link要等到下次才知道。
            if (ant != root) ant->suffix = q;
            ant = q;
 
            // 走訪suffix link
            if (p->suffix) p = p->suffix;
            else a++;   // 次長後綴在同一個節點
        }
        if (ant != root) ant->suffix = p;
    }
  // }
    return root;
}

void clean(Node *root) {
    for(int i = 0; i < 28; i++)
        if(root->l[i])
            clean(root->l[i]);
    delete root;
}

char S1[250001], S2[250001];

int main() {
  RS(S1); RS(S2);
  VI v;
  int N1 = strlen(S1), N2 = strlen(S2);
  REP(i, N2) v.PB(S2[i]-'a');
  v.PB(27);
  REP(i, N1) v.PB(S1[i]-'a');
  v.PB(26);
  Node *r = Ukkonen(v);
  r->depth = 0;

  stack<Node*> stack;
  stack.push(r);
  int best_len = -1, best_start;
  Node *best_node;
  while(!stack.empty()) {
    Node *n = stack.top();
    if(n->visited) {
      stack.pop();
      if(n->b == 1e9) {
        if(n->a <= N2)
          n->start2 = n->a - n->depth;
        else
          n->start1 = n->a - n->depth;
      } else {
        REP(i, 28) if(n->l[i]) {
          n->start1 = min(n->start1, n->l[i]->start1);
          n->start2 = min(n->start2, n->l[i]->start2);
          if(n->start1 < 1e9 && n->start2 < 1e9) {
            int d = n->depth + n->b - n->a;
            if(d > best_len || (d == best_len && n->start2 < best_start)) {
              best_len = d;
              best_start = n->start2;
              best_node = n;
            }
          }
        }
      }
    } else {
      n->visited = true;
      REP(i, 28) if(n->l[i]) {
        stack.push(n->l[i]);
        n->l[i]->depth = n->b - n->a + n->depth;
        n->l[i]->parent = n;
      }
    }
  }
  if(best_len > 0) {
    S2[best_start + best_len] = 0;
    puts(S2 + best_start);
  }
  PI(best_len);
  clean(r);
  return 0;
}