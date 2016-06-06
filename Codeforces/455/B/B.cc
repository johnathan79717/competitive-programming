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
#define LB lower_bound
#define UB upper_bound
#define BG begin()
#define ED end()
#define PQ priority_queue
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
const int INF = 1000000000;

struct TrieNode {
  TrieNode *child[26];
};

int main() {
  vector<TrieNode> pool(100000);
  auto getNode = [&pool]() {
    TrieNode *ret = &pool.back();
    pool.pop_back();
    return ret;
  };
  TrieNode *root = getNode();
  DRII(n, k);
  while(n--) {
    char str[100001];
    RS(str);
    TrieNode *p = root;
    REPL(i, str) {
      if(!p->child[str[i]-'a'])
        p->child[str[i]-'a'] = getNode();
      p = p->child[str[i]-'a'];
    }
  }
  function<pair<bool, bool>(TrieNode*)> game;
  game = [&game](TrieNode* p) {
    bool v1 = false, v2 = false, leaf = true;
    REP(i, 26) {
      if(p->child[i]) {
        leaf = false;
        auto g = game(p->child[i]);
        v1 = v1 || !g.first;
        v2 = v2 || !g.second;
      }
    }
    if(leaf) {
      return MP(false, true);
    } else {
      return MP(v1, v2);
    }
  };
  auto v = game(root);
  cerr << v.first << ' ' << v.second << endl;
  [v, k]() {
    if(v.first) { // first can win
      if(k == 1)
        return true;
      // have to lose at k-1
      if(v.second) { // first can lose
        // have to lose at k-2
        return true;
      } else { // second can lose
        // have to win at k-2
        return k%2 == 1;
      }
    }
    else { // second can win
      return false;
    }
  }() ? puts("First") : puts("Second");
  return 0;
}
