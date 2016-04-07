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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)

struct MysticAndCandies {
  int minBoxes(int C, int X, vector <int> low, vector <int> high) {
  	sort(ALL(low));
  	sort(ALL(high));
  	int sum = 0;
  	int N = low.size();
  	int ans = N;
  	PER(i, N) {
  		sum += low[i];
  		// cout << i << ' ' << sum << endl;
  		if(sum >= X) {
  			ans = min(ans, N - i);
  			break;
  		}
  	}
  	// cout << ans << endl;
  	sum = 0;
  	PER(i, N) sum += high[i];
  	PER(i, N) {
  		sum -= high[i];
  		// cout << i << ' ' << C - sum << endl;
  		if(C - sum >= X) {
  			ans = min(ans, N - i);
  			break;
  		}
  	}
  	// cout << ans << endl;
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
		cout << "Testing MysticAndCandies (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391788804;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MysticAndCandies _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int C = 15;
				int X = 12;
				int low[] = {1, 2, 3, 4, 5};
				int high[] = {1, 2, 3, 4, 5};
				_expected = 3;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 1:
			{
				int C = 60;
				int X = 8;
				int low[] = {5, 2, 3};
				int high[] = {49, 48, 47};
				_expected = 2;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 2:
			{
				int C = 58;
				int X = 30;
				int low[] = {3, 9, 12, 6, 15};
				int high[] = {8, 12, 20, 8, 15};
				_expected = 2;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 3:
			{
				int C = 207581165;
				int X = 172146543;
				int low[] = {4725448, 2753824, 6019698, 4199708, 4070001, 3589497, 5358499, 3637585, 5393667, 2837466,
				            2747807, 2918199, 3638042, 5199002, 3072044, 3858909, 3762101, 3657754, 3218704, 3888861,
				            3195689, 4768935, 3137633, 4124272, 4125056, 6087486, 3632970, 3620489, 2748765, 5917493,
				            3958996, 3335021, 3517186, 5543440, 2951006, 3403270, 3299481, 3093204, 4092331};
				int high[] = {5702812, 6805664, 6823687, 5337687, 4286533, 4999849, 6567411, 4563235, 6618139, 6260135,
				             6249469, 3821449, 5963157, 6385012, 4255959, 5786920, 6112817, 4103918, 6371537, 4231698,
				             3409172, 6806782, 5623563, 4511221, 6407338, 6491490, 5209517, 6076093, 6530132, 6111464,
				             5833839, 6253088, 5595160, 6236805, 5772388, 5285713, 5617002, 4650978, 5234740};
				_expected = 31;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			case 4:
			{
				int C = 43873566;
				int X = 32789748;
				int low[] = {2053198, 2175819, 4260803, 1542497, 1418952, 5000015, 1381849, 2462882, 6466891, 1827580, 6943641, 5775477};
				int high[] = {2827461, 3726335, 5410505, 4781355, 4925909, 5621160, 7325774, 5025476, 7876037, 8072075, 6979462, 6647628};
				_expected = 7;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}
			/*case 5:
			{
				int C = ;
				int X = ;
				int low[] = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int C = ;
				int X = ;
				int low[] = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int C = ;
				int X = ;
				int low[] = ;
				int high[] = ;
				_expected = ;
				_received = _obj.minBoxes(C, X, vector <int>(low, low+sizeof(low)/sizeof(int)), vector <int>(high, high+sizeof(high)/sizeof(int))); break;
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
