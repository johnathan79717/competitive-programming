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

typedef vector<int> VI;
typedef long long LL;

struct Segment
{
  int l, r;
  LL a, b;
  Segment(int r): r(r) {}
  Segment(int l, int r, LL a, LL b): l(l), r(r), a(a), b(b) {}
  Segment split(int u) {
    Segment s = *this;
    l = u;
    s.r = u-1;
    return s;
  }
  LL eval(int i) { return a * i + b; }
  bool operator<(Segment const &s) const {
    return r < s.r;
  }
};

typedef deque<Segment> Envelope;

Envelope *merge(Envelope *e1, Envelope *e2) {
  Envelope *res = new Envelope;
  while(!e1->empty() && !e2->empty()) {
    Segment &s1 = e1->front(), &s2 = e2->front();
    if(s1.l == s2.l) {
      int r = min(s1.r, s2.r), l = s1.l;
      LL s1l = s1.eval(l), s2l = s2.eval(l);
      LL s1r = s1.eval(r), s2r = s2.eval(r);
      if(s1l >= s2l && s1r >= s2r)
        res->EB(l, r, s1.a, s1.b);
      else if(s1l <= s2l && s1r <= s2r)
        res->EB(l, r, s2.a, s2.b);
      else {
        Segment &left = s1l > s2l ? s1 : s2;
        Segment &right = s1r > s2r ? s1 : s2;
        // assert(&left != &right);
        LL i = (left.b - right.b) / (right.a - left.a);
        // assert(INT_MIN <= i && i <= INT_MAX);
        res->EB(l, i, left.a, left.b);
        res->EB(i+1, r, right.a, right.b);
      }
      
      if(s1.r > r)
        s1.split(r+1), e2->pop_front();
      else if(s2.r > r)
        s2.split(r+1), e1->pop_front();
      else
        e1->pop_front(), e2->pop_front();
    } else {
      Envelope *fst, *snd;
      if(s1.l < s2.l)
        fst = e1, snd = e2;
      else
        fst = e2, snd = e1;
      
      if(fst->front().r < snd->front().l)
        res->PB(fst->front()), fst->pop_front();
      else
        res->PB(fst->front().split(snd->front().l));
    }
  }
  FOR(s, *e1) res->PB(s);
  FOR(s, *e2) res->PB(s);
  assert(is_sorted(res->BG, res->ED));
  delete e1;
  delete e2;
  return res;
}

Envelope* envelopes[20];
int top;
vector<int> size;

unordered_map<int, int> num;

template<class T>
class BIT {
  vector<T> bit;
public:
  BIT() {}
  BIT(int n): bit(n+1) {}
  T sum(int i) {
    T s = 0;
    while(i > 0) {
      s += bit.at(i);
      i &= i - 1;
    }
    return s;
  }
  void add(int i, T x) {
    while(i < bit.size()) {
      bit.at(i) += x;
      i += i & -i;
    }
  }
  void resize(int n) {
    bit.resize(n+1);
  }
};

BIT<LL> bita, bitb;

LL eval(Envelope *e, int i) {
  auto seg = lower_bound(e->BG, e->ED, Segment(i));
  if(seg == e->ED || seg->l > i)
    return LLONG_MIN;
  else {
    // assert(i <= seg->r);
    return seg->eval(i);
  }
}

struct Event
{
  int t, l, r, i;
  LL a, b;
  Event(int t, int l, int r, LL a, LL b): t(t), l(l), r(r), a(a), b(b) {}
  Event(int t, int i): t(t), i(i) {}
  void process() {
    switch(t) {
      case 1: new_plan(); break;
      case 2: new_fee(); break;
      case 3: query(); break;
      // default: assert(false); break;
    }
  }
  void new_plan() {
    Envelope *e = new Envelope;
    e->EB(l, r, a, b);
    envelopes[top++] = e;
    size.PB(1);
    while(top >= 2 && size[top-1] == size[top-2]) {
      Envelope *e1 = envelopes[--top], *e2 = envelopes[--top];
      envelopes[top++] = merge(e1, e2);
      size.pop_back();
      size.back() <<= 1;
    }
  }

  void new_fee() {
    int nl = num[l], nr = num[r+1];
    bita.add(nl, a);
    bitb.add(nl, b);
    bita.add(nr, -a);
    bitb.add(nr, -b);
  }

  void query() {
    LL ans = LLONG_MIN;
    REP(j, top)
      ans = max(ans, eval(envelopes[j], i));
    if(ans == LLONG_MIN)
      puts("NA");
    else {
      LL a = bita.sum(num[i]);
      LL b = bitb.sum(num[i]);
      PL(ans + a * i + b);
      // PL(a * i + b);
    }
  }
};

V(Event) events;
VI stores;

int main() {
  DRII(N, M);
  REP(m, M) {
    DRI(type);
    switch(type) {
      case 1:
      case 2:
        DRII(l, r); DRL(a); DRL(b);
        events.EB(type, l, r, a, b - l * a);
        if(type == 2)
          stores.PB(l), stores.PB(r+1);
        break;
      case 3: DRI(i); events.EB(type, i); stores.PB(i); break;
      default: assert(false); break;
    }
  }
  sort(ALL(stores));
  stores.resize(unique(ALL(stores)) - stores.BG);
  REP(i, stores.size()) num[stores[i]] = i+1;
  bita.resize(stores.size());
  bitb.resize(stores.size());
  FOR(e, events) e.process();
  REP(i, top)
    delete envelopes[i];
  return 0;
}