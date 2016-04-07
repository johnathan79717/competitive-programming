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
#define F first
#define S second
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct Hamberger
{
	int type, taste;
};

struct AlienAndHamburgers {
  int getNumber(vector <int> type, vector <int> taste) {

  	int Y = 0, A = 0, n = type.size();
  	bool chosen[101];
  	MS0(chosen);
  	V(Hamburger) h;
  	for(int i = 0; i < n; i++) {
  		if(taste[i] >= 0) {
  			A += taste[i];
  			if(!chosen[type[i]]) {
  				Y++;
  				chosen[type[i]] = true;
  			}
  		} else {
  			h.EB(type[i], taste[i]);
  		}
  	}
  	sort(ALL(h), [](const Hamburger&h1, const Hamburger&h2) {
  		return h1.taste > h2.taste;
  	});
  	for(auto &ham: h) {
  		if(chosen[ham.type]) continue;
  		if((Y+1)*(A+ham.taste) >= Y * A) {
  			Y++;
  			A += ham.taste;
  			chosen[ham.type] = true;
  		}
  	}
  	return Y * A;

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
		cout << "Testing AlienAndHamburgers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390310638;
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
		AlienAndHamburgers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int type[] = {1, 2};
				int taste[] = {4, 7};
				_expected = 22;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 1:
			{
				int type[] = {1, 1};
				int taste[] = {-1, -1};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 2:
			{
				int type[] = {1, 2, 3};
				int taste[] = {7, 4, -1};
				_expected = 30;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 3:
			{
				int type[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
				int taste[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
				_expected = 54;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 4:
			{
				int type[] = {30, 20, 10};
				int taste[] = {100000, -100000, 100000};
				_expected = 400000;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			/*case 5:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
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
