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
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();i++)
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
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define FST first
#define SND second
#define PQ priority_queue

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
const int INF = 1000000000;

class Student {
public:
  int index, ability, pass;
} students[100001];

struct Bug {
  int index, complexity;
} bugs[100001];

int n, m, s, ans[100001];

bool ok(int days) {
  PQ<Student, vector<Student>, function<bool(Student&,Student&)> >
    available([](Student &s1, Student &s2) {
      return s1.pass > s2.pass;
    });
  int p = 0; LL cost = 0;
  for(int bugId = 0; bugId < m; bugId += days) {
    while(p < n && students[p].ability >= bugs[bugId].complexity)
      available.push(students[p++]);
    if(available.empty()) return false;
    cost += available.top().pass;
    available.pop();
    if(cost > s) return false;
  }
  return true;
}


int main() {
  RIII(n, m, s);
  REP(j, m) {
    bugs[j].index = j;
    RI(bugs[j].complexity);
  }
  REP(i, n) {
    students[i].index = i;
    RI(students[i].ability);
  }
  REP(i, n) RI(students[i].pass);
  sort(bugs, bugs + m, [](const Bug &b1, const Bug &b2) {
    return b1.complexity > b2.complexity;
  });
  sort(students, students + n, [](const Student &s1, const Student &s2) {
    return s1.ability > s2.ability;
  });
  int lb = 0, ub = m + 1;
  while(ub - lb > 1) {
    int days = (ub + lb) / 2;
    if(ok(days)) ub = days;
    else lb = days;
  }
  if(ub > m)
    puts("NO");
  else {
    PQ<Student, vector<Student>, function<bool(const Student&,const Student&)> >
      available([](const Student &s1, const Student &s2) {
        return s1.pass > s2.pass;
      });
    puts("YES");
    int days = ub;
    int p = 0, bugId = 0;
    while(bugId < m) {
      while(p < n && students[p].ability >= bugs[bugId].complexity)
        available.push(students[p++]);
      REP(k, days) {
        if(bugId >= m) break;
        assert(!available.empty());
        ans[bugs[bugId++].index] = available.top().index;
      }
      assert(!available.empty());
      available.pop();
    }
    REP(j, m)
      printf("%d%c", ans[j] + 1, SEP(j == m-1));
  }
  return 0;
}