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
 
typedef long long LL;

struct PowerOfThree {
  string ableToGet(int x, int y) {
    string yes = "Possible", no = "Impossible";
    x = abs(x); y = abs(y);
    while(x || y) {
    	int a = x % 3;
    	int b = y % 3;
      if((a && b) || (!a && !b))
      	return no;
      if(a == 2) x = (x + 1) / 3;
      else x /= 3;
      if(b == 2) y = (y + 1) / 3;
      else y /= 3;
    }
    return yes;
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
		cout << "Testing PowerOfThree (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389712286;
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
		PowerOfThree _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 1;
				int y = 3;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 1:
			{
				int x = 0;
				int y = 2;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 2:
			{
				int x = 1;
				int y = 9;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 3:
			{
				int x = 3;
				int y = 0;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 4:
			{
				int x = 1;
				int y = 1;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 5:
			{
				int x = -6890;
				int y = 18252;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 6:
			{
				int x = 1000000000;
				int y = -1000000000;
				_expected = "Impossible";
				_received = _obj.ableToGet(x, y); break;
			}
			case 7:
			{
				int x = 0;
				int y = 0;
				_expected = "Possible";
				_received = _obj.ableToGet(x, y); break;
			}
			/*case 8:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
			}*/
			/*case 9:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
			}*/
			/*case 10:
			{
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.ableToGet(x, y); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
