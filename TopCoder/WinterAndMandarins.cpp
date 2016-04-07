#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <deque>
#include <climits>
#include <set>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define SZ size()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define FST first
#define SND second
 
typedef long long LL;

class WinterAndMandarins {
public:
  int getNumber(vector <int> bags, int K) {
    sort(ALL(bags));
    int ans = INT_MAX;
    REP1(i, 0, bags.SZ - K)
      ans = min(ans, bags[i+K-1] - bags[i]);
    return ans;
  }
};

// BEGIN CUT HERE
int main() {
  WinterAndMandarins test;

  cout << test.getNumber() << endl;
}
// END CUT HERE
