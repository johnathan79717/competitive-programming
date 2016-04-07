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

struct Node
{
  unsigned val;
  Node *child[2];
  Node() { child[0] = child[1] = 0; }
  Node(int val): val(val) { child[0] = child[1] = 0; }
  ~Node() {
    if(child[0]) delete child[0];
    if(child[1]) delete child[1];
  }
};

int main() {
  DRI(T);
  REP1(t, 1, T) {
    printf("Case #%d:\n", t);
    DRII(N, M);
    Node *root = new Node;
    while(N--) {
      unsigned K;
      scanf("%u", &K);
      Node *p = root;
      PER(i, 32) {
        assert(p);
        int bit = (K >> i) & 1;
        if(!p->child[bit]) p->child[bit] = new Node(K);
        p = p->child[bit];
      }
    }
    while(M--) {
      unsigned S;
      scanf("%u", &S);
      Node *p = root;
      PER(i, 32) {
        assert(p);
        int prefer = 1 - ((S >> i) & 1);
        if(p->child[prefer]) p = p->child[prefer];
        else p = p->child[1-prefer];
      }
      assert(p);
      printf("%u\n", p->val);
    }
    delete root;
    
  }
  return 0;
}
