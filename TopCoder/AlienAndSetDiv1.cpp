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
#include <list>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define MS0(x) memset(x,0,sizeof(x))
#define MOD 1000000007

inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }

#define MAX_N 50
#define MAX_K 10

int dp[2*MAX_N+1][2*MAX_N][1<<(MAX_K-1)];

struct AlienAndSetDiv1 {
  int getNumber(int N, int K) {
    MS0(dp);
    dp[0][0][0] = 1;
    REP(n, 2*N) {
      REP(unmatched, 2*N) {
        REP(state, 1 << (K-1)) {
          if(!dp[n][unmatched][state]) continue;
          if(unmatched == 0 && state == 0) {
            if(K == 1)
              addBy(dp[n+1][1][0], 2 * dp[n][0][0]);
            else
              addBy(dp[n+1][0][1 << (K-2)], 2 * dp[n][0][0]);
          } else {
            if(K == 1)
              addBy(dp[n+1][unmatched+1][0], dp[n][unmatched][0]);
            else
              addBy(dp[n+1][unmatched + (state & 1)][(state >> 1) ^ (1 << (K-2))],
                  dp[n][unmatched][state]);
            if(unmatched > 0)
              addBy(dp[n+1][unmatched - 1 + (state & 1)][state >> 1],
                    dp[n][unmatched][state]);
          }
        }
      }
    }
    return dp[2*N][0][0];
  }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
  if (argc == 1) 
  {
    cout << "Testing AlienAndSetDiv1 (450.0 points)" << endl << endl;
    for (int i = 0; i < 20; i++)
    {
      ostringstream s; s << argv[0] << " " << i;
      int exitCode = system(s.str().c_str());
      if (exitCode)
        cout << "#" << i << ": Runtime Error" << endl;
    }
    int T = time(NULL)-1390824635;
    double PT = T/60.0, TT = 75.0;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << endl;
    cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
    cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
  }
  else
  {
    int _tc; istringstream(argv[1]) >> _tc;
    AlienAndSetDiv1 _obj;
    int _expected, _received;
    time_t _start = clock();
    switch (_tc)
    {
      case 0:
      {
        int N = 2;
        int K = 2;
        _expected = 2;
        _received = _obj.getNumber(N, K); break;
      }
      case 1:
      {
        int N = 3;
        int K = 1;
        _expected = 20;
        _received = _obj.getNumber(N, K); break;
      }
      case 2:
      {
        int N = 4;
        int K = 2;
        _expected = 14;
        _received = _obj.getNumber(N, K); break;
      }
      case 3:
      {
        int N = 10;
        int K = 7;
        _expected = 40;
        _received = _obj.getNumber(N, K); break;
      }
      /*case 4:
      {
        int N = ;
        int K = ;
        _expected = ;
        _received = _obj.getNumber(N, K); break;
      }*/
      /*case 5:
      {
        int N = ;
        int K = ;
        _expected = ;
        _received = _obj.getNumber(N, K); break;
      }*/
      /*case 6:
      {
        int N = ;
        int K = ;
        _expected = ;
        _received = _obj.getNumber(N, K); break;
      }*/
      default: return 0;
    }
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
    if (_received == _expected)
      cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
    else
    {
      cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
      cout << "           Expected: " << _expected << endl;
      cout << "           Received: " << _received << endl;
    }
  }
}

// END CUT HERE
