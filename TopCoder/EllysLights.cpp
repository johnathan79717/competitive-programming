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
#define MP make_pair
#define PB push_back
#define V(T) vector<T >
 
typedef long long LL;

LL stoi(string &s) {
	LL ans = 0;
	REP(i, s.size())
		if(s[i] == 'Y')
			ans |= (1LL << i);
	return ans;
}

struct EllysLights {

	void add(unordered_map<LL, int> &map, pair<LL, int> pr) {
		if(map.count(pr.first))
			map[pr.first] = min(map[pr.first], pr.second);
		else
			map[pr.first] = pr.second;
	}

  int getMinimum(string initial, vector <string> switches) {
  	int N = initial.size();
  	// cout << switches.size() << endl;
  	vector<unordered_map<LL, int> > map(N+1);
  	map[0].emplace(stoi(initial), 0);
  	V(LL) sw;
  	FOR(s, switches) sw.PB(stoi(s));
  	V(bool) decided(switches.size());
  	REP(i, N) {
  		V(LL) can;
  		REP(j, sw.size()) {
  			if((sw[j] & (1ll<<i)) && !decided[j]) {
  				can.PB(sw[j]);
  				decided[j] = true;
  			}
  		}
  		FOR(pr, map[i]) {
  			if(pr.first & (1ll << i)) {
  				FOR(c, can)
  					add(map[i+1], MP(pr.first ^ c, pr.second + 1));
  			} else {
  				add(map[i+1], MP(pr.first, pr.second));
  				if(can.size() == 2)
  					add(map[i+1], MP(pr.first ^ can[0] ^ can[1], pr.second+2));
  			}
  		}
  	}
  	int ans = INT_MAX;
  	FOR(s, map[N]) ans = min(ans, s.second);
  	return ans != INT_MAX ? ans : -1;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly's house has a number of light bulbs. Some of them are 
turned on, some of them are not. She wants to switch all 
of them off for the upcoming Earth Hour.

Unfortunately, her house has a strange system of light 
switches. Each switch changes the state of some of the 
bulbs (possibly none or all of them). This means that if 
she uses the switch, all bulbs that are connected to it go 
off if they were on, and go on if they were off. She also 
knows that each bulb is connected to at most two switches. 
Help Elly determine what is the minimal number of switches 
she must use in order to turn off all the lights.

You are given a string initial and a vector <string> 
switches. Each character in initial represents one light 
bulb: if the i-th light bulb (0-based index) is initially 
on, the i-th character of initial is 'Y', otherwise it is 
'N'. Each element of switches represents one switch: if 
the i-th switch toggles the j-th light bulb, switches[i]
[j] is 'Y', otherwise it is 'N'.

Find and return the smallest nonnegative integer X such 
that there is a sequence of X switches such that if Elly 
toggles those switches in the given order, all light bulbs 
will be turned off at the end. If no such X exists, return 
-1.

DEFINITION
Class:EllysLights
Method:getMinimum
Parameters:string, vector <string>
Returns:int
Method signature:int getMinimum(string initial, vector 
<string> switches)


NOTES
-It is possible that none or all of the bulbs are turned 
on initially.
-Elly is allowed to toggle the same switch more than once.


CONSTRAINTS
-initial will contain between 1 and 50 characters, 
inclusive.
-Each character of initial will be either 'Y' or 'N'.
-switches will contain between 1 and 50 elements, inclusive.
-Each element of switches will contain the same number of 
characters as initial.
-Each character of each element of switches will be either 
'Y' or 'N'.
-For each index of initial there will be at most two 
elements of switches that will have 'Y' at that index.


EXAMPLES

0)
"YNYNNN"
{"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"}

Returns: 2

There are multiple ways how to turn off all the lights.
For example, she can first use switch 0, then switch 4, 
and finally switch 1.
The shortest solutions only use two switches.
For example, it is enough to flip the switch 2 followed by 
the switch 3.

1)
"YNYNYN"
{"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"}

Returns: 4

Some of the switches might change the state of none or all 
of the bulbs. Some of the bulbs might be influenced by 
less than 2 switches.


2)
"YYN"
{"YNY", "NYN"}

Returns: -1

Sometimes there might be no way to switch off all the 
bulbs. In this case return -1.


3)
"NNYNYNYYYNNYYYYN"
{"NYNYNYNYNYNYNYNY",
 "YNYNYNYNYNYNYNYN",
 "NNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNN",
 "NNNNYNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNN",
 "NNNNNNYNNNNNNNNN",
 "NNNNNNNYNNNNNNNN",
 "NNNNNNNNYNNNNNNN",
 "NNNNNNNNNYNNNNNN",
 "NNNNNNNNNNYNNNNN",
 "NNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNYNNN",
 "NNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNYN",
 "NNNNNNNNNNNNNNNY"}

Returns: 6

There are 9 lit bulbs initially. We can turn them off one 
by one, but it will be faster to use one of the complex 
switches and then to toggle the ones that are still lit.

4)
"NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY"
{"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
 "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
 "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
 "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"}

Returns: 7



5)
"NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN"
{"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
 "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
 "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
 "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
 "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
 "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
 "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
 "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
 "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"}

Returns: -1



*/
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
		cout << "Testing EllysLights (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1396695507;
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
		EllysLights _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string initial = "YNYNNN";
				string switches[] = {"YNNYNY", "NYYYNN", "YNYNYN", "NNNNYN", "NYNNNY"};
				_expected = 2;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 1:
			{
				string initial = "YNYNYN";
				string switches[] = {"NNNNNN", "YYYYYY", "NYNNNN", "NNNYNN", "NNNNNY"};
				_expected = 4;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 2:
			{
				string initial = "YYN";
				string switches[] = {"YNY", "NYN"};
				_expected = -1;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 3:
			{
				string initial = "NNYNYNYYYNNYYYYN";
				string switches[] = {"NYNYNYNYNYNYNYNY",
				                     "YNYNYNYNYNYNYNYN",
				                     "NNNNNNNNNNNNNNNN",
				                     "YNNNNNNNNNNNNNNN",
				                     "NYNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNN",
				                     "NNNNYNNNNNNNNNNN",
				                     "NNNNNYNNNNNNNNNN",
				                     "NNNNNNYNNNNNNNNN",
				                     "NNNNNNNYNNNNNNNN",
				                     "NNNNNNNNYNNNNNNN",
				                     "NNNNNNNNNYNNNNNN",
				                     "NNNNNNNNNNYNNNNN",
				                     "NNNNNNNNNNNYNNNN",
				                     "NNNNNNNNNNNNYNNN",
				                     "NNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNNNYN",
				                     "NNNNNNNNNNNNNNNY"};
				_expected = 6;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 4:
			{
				string initial = "NYNYNYYYNNYYYNNYNNYYYYYNNYNYYYY";
				string switches[] = {"NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
				                     "NNNNNNNNYNNNYNNNNYYNYNNNNYNNNNN",
				                     "NNNNNNNNNYNNNNNNNNNNNNYNNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NYNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNYYNNNNNNNNNNNNNNNY",
				                     "NNNNNNYNNNNNNNNNNNNYNNNNNYNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "YNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNNNYYNNNNNN",
				                     "NYNNNNNNNNNNYNNNNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNY",
				                     "NNNNNNNNNNYNNNNNNNNNYYYNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNNNNNNNYNNN",
				                     "NNNNNNNNYNNNNNNNNNNNNNNNYNNNNNN",
				                     "YNNNYNNNNNNNNNNNNNNNNNNNNNNYNNN",
				                     "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNYNNYNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNYNNNYNNNNNNNNNNNNNYN"};
				_expected = 7;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 5:
			{
				string initial = "NYNYYNYNYYYYNNYNYNNYYNNNNNYNYNNNNNYNNNYN";
				string switches[] = {"NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNYNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN",
				                     "NNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNYNNNNYNNNNNNNYNNNNNNN",
				                     "NNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNYNNNNNNNNYNNNYNNNNNYNN",
				                     "NNNNNNNNNNYNNNNNNNNNNNNNNYNNNNNYNNYNNNNN",
				                     "NNNNNYNNYNNYNNNNNNNNNNNNNNNNNNNNNYNNNNNN",
				                     "YNNNYNNNNNNNNNNNNNYNNNYNNYNNNNNNNYNNNNNN",
				                     "NNNNNNNNNYYNNNNNNNNNNNNYNNNNYNNNNNNNNNNN",
				                     "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNY",
				                     "NNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNYNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNY",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN",
				                     "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN",
				                     "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NYNNNNYNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
				                     "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNN",
				                     "NNNNNNNNNNNNYNNYYNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                     "NNNYNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN",
				                     "NNNNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
				                     "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNNNNNNYNNN"};
				_expected = -1;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			case 6:
			{
				string initial = "YNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYNYN";
				string switches[] = {"YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "YYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY"};
				_expected = 25;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}
			/*case 7:
			{
				string initial = ;
				string switches[] = ;
				_expected = ;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string initial = ;
				string switches[] = ;
				_expected = ;
				_received = _obj.getMinimum(initial, vector <string>(switches, switches+sizeof(switches)/sizeof(string))); break;
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
