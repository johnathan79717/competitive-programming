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
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define V(T) vector<T >
 
typedef long long LL;
typedef V(int) VI;

struct MinimumSquare {

	bool ok(VI &x1, VI&y1, VI&x, VI&y, int K, LL m) {
  	int N = x.size();
	  FOR(xx, x1) FOR(yy, y1) {
			int cnt = 0;
			REP(i, N) {
				if(xx <= x[i] && x[i] <= xx + m && yy <= y[i] && y[i] <= yy + m) {
					cnt++;
				}
			}
			if(cnt >= K)
				return true;
		}
		return false;
	}

  long long minArea(vector <int> x, vector <int> y, int K) {
  	VI x1 = x, y1 = y;
  	sort(ALL(x1)); sort(ALL(y1));
  	LL lb = -1, ub = 2000000000;
  	while(ub - lb > 1) {
  		LL m = (ub + lb) / 2;
  		if(ok(x1, y1, x, y, K, m))
  			ub = m;
  		else
  			lb = m;
  	}
  	return (ub + 2) * (ub + 2);
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
		cout << "Testing MinimumSquare (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396108808;
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
		MinimumSquare _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {0, 3};
				int y[] = {0, 7};
				int K = 2;
				_expected = 81LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 1:
			{
				int x[] = {-4, 3, 1};
				int y[] = {3 , -1, -2};
				int K = 2;
				_expected = 16LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 2:
			{
				int x[] = {0, 0, 1, 1, 2, 2};
				int y[] = {0, 1, 0, 1, 0, 1};
				int K = 4;
				_expected = 9LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 3:
			{
				int x[] = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
				int y[] = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
				int K = 3;
				_expected = 4000000008000000004LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			case 4:
			{
				int x[] = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
				int y[] = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
				int K = 8;
				_expected = 1695545329LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int y[] = ;
				int K = ;
				_expected = LL;
				_received = _obj.minArea(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int)), K); break;
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
