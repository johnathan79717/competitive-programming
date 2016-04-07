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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define MS0(x) memset(x,0,sizeof(x))

#define MOD 1000000007

inline int add(int a, int b, int mod=MOD) { return a + b < mod ? a + b : a + b - mod; }
inline void addBy(int &a, int b, int mod=MOD) { a = add(a, b, mod); }

#define MAX_N 50
#define MAX_K 10

int dp[2*MAX_N+1][1 << MAX_K];

struct AlienAndSetDiv2 {
  int getNumber(int N, int K) {
  	MS0(dp);
  	dp[0][0] = 1;
  	REP(n, 2*N) {
  		REP(s, 1 << K) {
  			if(dp[n][s] == 0) continue;
  			if(s == 0)
  				addBy(dp[n+1][1], 2 * dp[n][0]);
  			else {
  				int b = 1 << (K-1);
  				while(!(s & b)) b >>= 1;
  				addBy(dp[n+1][(s ^ b) << 1], dp[n][s]);
  				if(!(s & (1 << (K-1))))
  					addBy(dp[n+1][s * 2 + 1], dp[n][s]);
  			}
  		}
  	}
  	return dp[2*N][0];
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
		cout << "Testing AlienAndSetDiv2 (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390822165;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlienAndSetDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 1;
				_expected = 4;
				_received = _obj.getNumber(N, K); break;
			}
			case 1:
			{
				int N = 3;
				int K = 1;
				_expected = 8;
				_received = _obj.getNumber(N, K); break;
			}
			case 2:
			{
				int N = 4;
				int K = 2;
				_expected = 44;
				_received = _obj.getNumber(N, K); break;
			}
			case 3:
			{
				int N = 10;
				int K = 10;
				_expected = 184756;
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
