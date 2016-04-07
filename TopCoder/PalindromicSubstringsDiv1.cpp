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
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define MS0(x) memset(x,0,sizeof(x))
 
typedef long long LL;

double dp[5001][5001];

struct PalindromicSubstringsDiv1 {
  double expectedPalindromes(vector <string> S1, vector <string> S2) {
  	string S;
  	FOR(s, S1) S += s;
  	FOR(s, S2) S += s;
  	MS0(dp);
  	int N = S.size();
  	REP(i, N) dp[i][0] = dp[i][1] = 1.0;
  	double ans = N;
  	REP1(l, 2, N) REP(i, N-l+1) {
  		if(S[i] == '?' || S[i+l-1] == '?')
  			dp[i][l] = dp[i+1][l-2] / 26;
  		else if(S[i] == S[i+l-1])
  			dp[i][l] = dp[i+1][l-2];
  		ans += dp[i][l];
  	}
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
		cout << "Testing PalindromicSubstringsDiv1 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391428811;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PalindromicSubstringsDiv1 _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S1[] = {"a","a",""};
				string S2[] = {"a"};
				_expected = 6.0;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 1:
			{
				string S1[] = {"z??"};
				string S2[] = {};
				_expected = 3.115384615384615;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 2:
			{
				string S1[] = {"ab","c"};
				string S2[] = {"??","a?"};
				_expected = 7.315088757396449;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 3:
			{
				string S1[] = {};
				string S2[] = {"?"};
				_expected = 1.0;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			case 4:
			{
				string S1[] = {"ab?def","?"};
				string S2[] = {"f??a"};
				_expected = 12.545971779699588;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}
			/*case 5:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string S1[] = ;
				string S2[] = ;
				_expected = ;
				_received = _obj.expectedPalindromes(vector <string>(S1, S1+sizeof(S1)/sizeof(string)), vector <string>(S2, S2+sizeof(S2)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
