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

struct EllysLamps {
  int getMin(string lamps) {
  	int i = 0, ans = 0;
  	while(i+1 < lamps.size()) {
  		if(lamps[i] != lamps[i+1]) {
  			ans++;
  			i += 2;
  		} else if(lamps[i] == 'Y') {
  			if(i + 2 < lamps.size()) {
  				ans++;
  				i += 3;
  			} else {
  				break;
  			}
  		} else {
  			i++;
  		}
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Elly has a row of N lamps, conveniently numbered from 0 to 
N-1. Some of them are initially lit and the rest are not. 
She can control the lamps using a controller. On the 
controller there is a row of N buttons. Clicking the 
button with index i changes the state of lamp i: it goes 
off, if it was on, and it goes on if it was off.

Unfortunately the controller has some defects. Each of the 
buttons correctly changes the state of the corresponding 
lamp. However, it is possible that some of the buttons 
also change the state of one or both adjacent lamps as 
well. This means that pressing the button with index i has 
the following effects:

The state of lamp i changes.
If there is a lamp with index i-1, its state might change.
If there is a lamp with index i+1, its state might change.

The girl does not initially know which lamps change their 
state when each of the buttons is pressed. She knows, 
however, that every time she clicks a particular button, 
the same set of lamps will change their states.

Elly wants to reach a configuration in which the number of 
lamps that are turned on is minimized. Help her determine 
how many of them will remain lit in the worst possible 
case. (That is, for the worst possible way how the buttons 
change the state of the lamps.) She can use each of the 
buttons as many times as she likes, in any order she likes.

You will be given a string lamps, which gives information 
about the initial state of the lamps. The i-th character 
of lamps will be 'Y' if the i-th lamp is lit, and 'N', if 
it is not. Return the minimal number of lit lamps the girl 
can get in the worst possible case.

DEFINITION
Class:EllysLamps
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string lamps)


NOTES
-The defects in the switches might not be symmetric. This 
means that if a lamp with index i happens to change the 
state of lamp i+1, this does not necessarily mean that the 
using the switch of lamp i+1 changes the state of lamp i.


CONSTRAINTS
-lamps will contain between 1 and 50 elements, inclusive.
-Each element of lamps will be either 'Y' or 'N'.


EXAMPLES

0)
"YNNYN"

Returns: 2

In this case Elly will only make things worse (or the 
same) by pressing buttons. For example, suppose that:

buttons 0 and 1 each change the state of both lamps 0 and 1
buttons 2 and 3 each change the state of both lamps 2 and 3
button 4 only changes the state of lamp 4

In this situation, Elly cannot reach any configuration 
with fewer than two lit lamps.

1)
"NNN"

Returns: 0

Obviously, with no initially lit lamps, Elly can just sit 
and relax.

2)
"YY"

Returns: 0

If one of the lamps influences the other one, then Elly 
can use it and turn both off with one button press. 
Otherwise, each button changes the state of its lamp only, 
thus Elly can turn them both off by pressing both buttons.

3)
"YNYYYNNNY"

Returns: 3



4)
"YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"

Returns: 13



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
		cout << "Testing EllysLamps (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1397319735;
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
		EllysLamps _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string lamps = "YNNYN";
				_expected = 2;
				_received = _obj.getMin(lamps); break;
			}
			case 1:
			{
				string lamps = "NNN";
				_expected = 0;
				_received = _obj.getMin(lamps); break;
			}
			case 2:
			{
				string lamps = "YY";
				_expected = 0;
				_received = _obj.getMin(lamps); break;
			}
			case 3:
			{
				string lamps = "YNYYYNNNY";
				_expected = 3;
				_received = _obj.getMin(lamps); break;
			}
			case 4:
			{
				string lamps = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY";
				_expected = 13;
				_received = _obj.getMin(lamps); break;
			}
			case 5:
			{
				string lamps = "NNN";
				_expected = 0;
				_received = _obj.getMin(lamps); break;
			}
			/*case 6:
			{
				string lamps = ;
				_expected = ;
				_received = _obj.getMin(lamps); break;
			}*/
			/*case 7:
			{
				string lamps = ;
				_expected = ;
				_received = _obj.getMin(lamps); break;
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
