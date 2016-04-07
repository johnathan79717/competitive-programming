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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define MP make_pair
#define V(T) vector<T >

struct AlbertoTheAviator {
  int MaximumFlights(int F, vector <int> duration, vector <int> refuel) {
  	int N = duration.size();
  	vector<pair<int, int> > v(N);
  	REP(i, N) v[i] = MP(refuel[i], duration[i]);
  	sort(ALL(v), greater<pair<int, int> >());
  	V(V(int)) dp(N+1, V(int)(N+1, -1));
  	dp[0][0] = F;
  	REP(i, N) REP1(m, 0, N) {
  		dp[i+1][m] = max(dp[i+1][m], dp[i][m]);
  		if(m < N && dp[i][m] >= v[i].second)
  			dp[i+1][m+1] = max(dp[i+1][m+1], dp[i][m] - v[i].second + v[i].first);
  	}
  	int ans = N;
  	while(dp[N][ans] < 0) ans--;
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
		cout << "Testing AlbertoTheAviator (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1393381626;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlbertoTheAviator _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int F = 10;
				int duration[] = {10};
				int refuel[] = {0};
				_expected = 1;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 1:
			{
				int F = 10;
				int duration[] = {8, 4};
				int refuel[] = {0, 2};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 2:
			{
				int F = 12;
				int duration[] = {4, 8, 2, 1};
				int refuel[] = {2, 0, 0, 0};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 3:
			{
				int F = 9;
				int duration[] = {4, 6};
				int refuel[] = {0, 1};
				_expected = 2;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 4:
			{
				int F = 100;
				int duration[] = {101};
				int refuel[] = {100};
				_expected = 0;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			case 5:
			{
				int F = 1947;
				int duration[] = {2407, 2979, 1269, 2401, 3227, 2230, 3991, 2133, 3338, 356, 2535, 3859, 3267, 365};
				int refuel[] = {2406, 793, 905, 2400, 1789, 2229, 1378, 2132, 1815, 355, 72, 3858, 3266, 364};
				_expected = 3;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}
			/*case 6:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int F = ;
				int duration[] = ;
				int refuel[] = ;
				_expected = ;
				_received = _obj.MaximumFlights(F, vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(refuel, refuel+sizeof(refuel)/sizeof(int))); break;
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
