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
#include <cassert>
#include <unordered_map>
using namespace std;
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define A__int128(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) __int128 x;RL(x)
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
const int INF = 1000000000;

__int128 win[27];
struct Node *r1, *r2;
int nim1, i1, i2;
char ans1[300001], ans2[300001];
VI a, b;

struct Node
{
    int lnim, rnim, a, b;
    vector<pair<int, __int128> > cnt;
    Node* l[26], *suffix;
    Node(int a, int b): lnim(0), rnim(0), a(a), b(b), suffix(0)
    {
        memset(l, 0, sizeof(l));
    }
    ~Node() {
      REP(i, 26)
        if(l[i])
          delete l[i];
    }
    void getA(__int128 k) {
      int nim = lnim;
      for(int i = a; i < b - 1; i++) {
        ans1[i1++] = 'a' + ::a[i];
        if(win[nim] >= k) {
          nim1 = nim;
          r2->getB(k);
          return;
        }
        k -= win[nim];
        nim ^= 1;
      }
      if(a < b)
        ans1[i1++] = 'a' + ::a[b-1];
      if(win[rnim] >= k) {
        nim1 = rnim;
        r2->getB(k);
        return;
      }
      k -= win[rnim];
      for(int i = 0; i < 26; i++) {
        if(l[i]) {
          __int128 temp = 0;
          FOR(p, l[i]->cnt)
            temp += p.second * win[p.first];
          if(temp >= k) {
            l[i]->getA(k);
            return;
          }
          k -= temp;
        }
      }
    }
    void getB(__int128 k) {
      int nim = lnim;
      for(int i = a; i < b - 1; i++) {
        ans2[i2++] = 'a' + ::b[i];
        if(nim != nim1) k--;
        if(!k) return;
        nim ^= 1;
      }
      if(a < b)
        ans2[i2++] = 'a' + ::b[b-1];
      if(rnim != nim1) k--;
      if(!k) return;
      for(int i = 0; i < 26; i++) {
        if(l[i]) {
          __int128 temp = 0;
          FOR(p, l[i]->cnt)
            if(p.first != nim1)
              temp += p.second;
          if(temp >= k) {
            l[i]->getB(k);
            return;
          }
          k -= temp;
        }
      }      
    }
};

unordered_map<Node*, bool> visited;

void dfs(Node *root, int N) {
    stack<Node*> stack;
    stack.push(root);
    while(!stack.empty()) {
      root = stack.top();
      if(!visited[root]) {
        REP(i, 26)
          if(root->l[i])
            stack.push(root->l[i]);
        visited[root] = true;
        continue;
      }
      stack.pop();
      __int128 c[26];
      memset(c, 0, sizeof c);
      if(root->b > N) {
        root->rnim = 0;
        root->b = N;
      } else {
        bool f[27];
        REP(i, 27) f[i] = false;
        REP(i, 26) {
          if(root->l[i]) {
            // dfs(root->l[i], N);
            f[root->l[i]->lnim] = true;
            FOR(p, root->l[i]->cnt)
              c[p.first] += p.second;
          }
        }
        root->rnim = 0;
        while(f[root->rnim]) root->rnim++;
      }
      c[root->rnim]++;
      root->lnim = root->rnim;
      if(root->b - root->a > 1) {
        if(root->rnim) {
          root->lnim = (root->b - root->a) % 2;
          c[0] += (root->b - root->a) / 2;
          c[1] += (root->b - root->a - 1) / 2;
        }
        else {
          root->lnim = 1 - (root->b - root->a) % 2;
          c[0] += (root->b - root->a - 1) / 2;
          c[1] += (root->b - root->a) / 2;
        }
      }
      REP(i, 26)
        if(c[i])
          root->cnt.EB(i, c[i]);
    }
}
 
Node *Ukkonen(const VI &s)
{
    Node* root = new Node(0, 0), *p = root;
 
    for (int a=0, i=0; i<s.size(); ++i)
    {
        Node* ant = root;
        while (a <= i)
        {
            while (true)
            {
                if (a == i) break;
                Node* q = p->l[s[a]];
                if (a + q->b - q->a > i) break;
                a += q->b - q->a;
                p = q;
            }
 
            Node* q = p;
            if (a == i)
            {
                if (p->l[s[i]]) break;
            }
            else if (a < i)
            {
                Node* r = p->l[s[a]];
                int k = r->a + i - a;
                if (s[i] == s[k]) break;
 
                p->l[s[a]] = q = new Node(r->a, k);
                q->l[s[k]] = r; r->a = k;
            }
 
            q->l[s[i]] = new Node(i, INF);
 
            if (ant != root) ant->suffix = q;
            ant = q;
 
            if (p->suffix) p = p->suffix;
            else a++;
        }
        if (ant != root) ant->suffix = p;
    }
    return root;
}

int main() {
  DRII(N, M);
  a.resize(N);
  b.resize(M);
  long long k;
  scanf("%lld", &k);
  __int128 K = k;
  char *A = new char[N+1];
  char *B = new char[M+1];
  RS(A);
  RS(B);
  REP(i, N)
    a[i] = A[i] - 'a';
  REP(j, M)
    b[j] = B[j] - 'a';
  delete[] A;
  delete[] B;
  r1 = Ukkonen(a);
  r2 = Ukkonen(b);
  dfs(r1, N);
  dfs(r2, M);
  __int128 sum = 0;
  FOR(p, r2->cnt)
    sum += p.second;
  REP(i, 27) win[i] = sum;
  FOR(p, r2->cnt)
    win[p.first] -= p.second;
  __int128 total = 0;
  FOR(p, r1->cnt)
    total += p.second * win[p.first];
  if(K > total)
    puts("no solution");
  else {
    r1->getA(K);
    puts(ans1);
    puts(ans2);
  }
  delete r1;
  delete r2;
  return 0;
}