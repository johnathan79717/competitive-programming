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
using namespace std;
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 2000000000;

struct Gang {
  int start, end;
  Gang(int s, int e): start(s), end(e) {}
  bool operator<(const Gang &g) const {
    return end < g.end;
  }
};

enum EventType {
  START, END
};

struct Event {
  int gang, time, type;
  Event(int g, int t, EventType tp): gang(g), time(t), type(tp) {}
};

int main() {
  DRI(T);
  while(T--) {
    DRII(N, X);
    vector<Gang> gangs;
    vector<Event> events;
    REP(i, N) {
      DRII(S, E);
      gangs.EB(S, E);
      events.EB(i, S, START);
      events.EB(i, E, END);
    }
    sort(ALL(event), [](const Event &e1, const Event &e2) {
      if(e1.time != e2.time) return e1.time < e2.time;
      return e1.type == START || e2.type == END;
    });

    int ans = 0;
    multiset<Gang> mark;
    multiset<Gang> unmark;
    for(const auto &e : event) {
      if(e.type == START) {
        unmark.insert(gangs[e.gang]);
        if(unmark.size() == X) {
          auto last = unmark.end();
          --last;
          mark.insert(*last);
          unmark.erase(last);
        }
      }        
    }

    for(int t = 0; t < event.size(); t++) {
      while(it != gangs.end() && it->start == t) {
        unmark.insert(*it);
        it++;
      }
      while(unmark.size() >= X) {
        auto jt = unmark.end();
        jt--;
        mark.insert(*jt);
        unmark.erase(jt);
        ans++;
      }
      while(unmark.begin()->end == t)
        unmark.erase(unmark.begin());
      while(mark.begin()->end == t)
        mark.erase(mark.begin());
    }
    PI(ans);
  }
  return 0;
}