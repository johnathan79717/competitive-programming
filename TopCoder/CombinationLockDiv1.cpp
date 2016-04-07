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
#define FOR(i, c) for(auto &i: c)
#define REP(i,n) for(int i=0;i<(n);i++)
#define V(T) vector<T >
 
typedef V(int) VI;

int steps(char a, char b) {
	int d = b - a;
	if(d < 0) d += 10;
	return min(d, 10 - d);
}

#define MAX_R 50

struct CombinationLockDiv1 {
  int minimumMoves(vector <string> P, vector <string> Q) {
  	string S, T;
  	FOR(p, P) S += p;
  	FOR(q, Q) T += q;
  	int N = S.size();
  	V(V(VI)) dp(N+1, V(VI)(MAX_R, VI(MAX_R, 1000000000)));
  	dp[0][0][0] = 0;
  	REP(i, N) {
  		REP(j, MAX_R) REP(k, MAX_R) {
  			if((S[i] + j - k) % 10 != T[i] % 10)
  				continue;
  			REP(j1, MAX_R) REP(k1, MAX_R) {
  				dp[i+1][j][k] =
  					min(dp[i+1][j][k], dp[i][j1][k1] + max(0, j - j1) + max(0, k - k1));
  			}
  		}
  	}
  	int ans = 1000000000;
  	REP(j, MAX_R) REP(k, MAX_R) ans = min(ans, dp[N][j][k]);
  	return ans;
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
		cout << "Testing CombinationLockDiv1 (475.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391430097;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 475.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CombinationLockDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string P[] = {"123"};
				string Q[] = {"112"};
				_expected = 1;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			case 1:
			{
				string P[] = {"1"};
				string Q[] = {"7"};
				_expected = 4;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			case 2:
			{
				string P[] = {"6","07"};
				string Q[] = {"","60","7"};
				_expected = 0;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			case 3:
			{
				string P[] = {"1234"};
				string Q[] = {"4567"};
				_expected = 3;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			case 4:
			{
				string P[] = {"020"};
				string Q[] = {"909"};
				_expected = 2;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			case 5:
			{
				string P[] = {"4423232218340"};
				string Q[] = {"6290421476245"};
				_expected = 18;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}
			/*case 6:
			{
				string P[] = ;
				string Q[] = ;
				_expected = ;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string P[] = ;
				string Q[] = ;
				_expected = ;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string P[] = ;
				string Q[] = ;
				_expected = ;
				_received = _obj.minimumMoves(vector <string>(P, P+sizeof(P)/sizeof(string)), vector <string>(Q, Q+sizeof(Q)/sizeof(string))); break;
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
