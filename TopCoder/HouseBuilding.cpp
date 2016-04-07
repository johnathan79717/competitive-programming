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
#define V(T) vector<T >

struct HouseBuilding {
  int getMinimum(vector <string> area) {
    int ans = INT_MAX;
    for(char t = '0'; t < '9'; t++) {
      int cost = 0;
      FOR(s, area) FOR(c, s) {
        if(c <= t) cost += (t - c);
        else cost += (c - (t+1));
      }
      ans = min(ans, cost);
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
		cout << "Testing HouseBuilding (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396367835;
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
		HouseBuilding _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string area[] = {"10",
				                 "31"};
				_expected = 2;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 1:
			{
				string area[] = {"54454",
				                 "61551"};
				_expected = 7;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 2:
			{
				string area[] = {"989"};
				_expected = 0;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 3:
			{
				string area[] = {"90"};
				_expected = 8;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			case 4:
			{
				string area[] = {"5781252",
				                 "2471255",
				                 "0000291",
				                 "1212489"};
				_expected = 53;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}
			/*case 5:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string area[] = ;
				_expected = ;
				_received = _obj.getMinimum(vector <string>(area, area+sizeof(area)/sizeof(string))); break;
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
