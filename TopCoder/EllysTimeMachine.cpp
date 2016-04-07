#include <string>
#include <cassert>
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
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "EllysTimeMachine.cpp"
#include <string>
#include <vector>
class EllysTimeMachine {
public:
    string getTime(string time) {
       int hour = (time[0] - '0') * 10 + (time[1] - '0');
      int minute = (time[3] - '0') * 10 + (time[4] - '0');
        char ans[10];
       sprintf(ans, "%02d:%02d", minute / 5 ? minute / 5 : 12, hour * 5); 
       return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Elly has invented a simple time machine!
Unfortunately, it cannot change the time by more than several hours.
But sometimes several hours is all a person needs...


The time machine has a wall clock with two hands: a small hand that shows the hour and a large hand that shows the minutes.
Both hands move in discrete steps.
The minute hand moves to show the correct time whenever the number of minutes reaches a multiple of 5.
The hour hand moves to show the correct time each whole hour.
This means that at any moment, the hour hand points to one of the numbers 01, 02, 03, ..., 11, and 12.
Additionally, at any moment, the minute hand also points to one of those numbers, but we interpret them as minutes: :05, :10, :15, ..., :55, and :00.


The time machine behaves in a peculiar way: when activated, it jumps to such a time that the two hands on the clock switch positions.
For example, suppose the current time is 11:20.
On the clock, the hour hand points to 11 and the minute hand points to 04 (that represents :20).
As Elly activated the time machine, the hands switched positions: now the hour hand points to 04 and the minute hand points to 11.
Thus, the time machine jumped to the time 04:55. See the sample test cases for other examples of how the time machine works.


You are given the current time in the string time in the format "HH:MM", where HH are the hours (a two-digit number between 01 and 12, inclusive), and MM are the minutes (a two-digit number between 00 and 55, inclusive).
Compute the new time after the time machine is activated.
Return that time in the same format.

DEFINITION
Class:EllysTimeMachine
Method:getTime
Parameters:string
Returns:string
Method signature:string getTime(string time)


NOTES
-Please note that the required time formatting always requires two digits both for the hour and the minutes (i.e. the numbers are padded with leading zeroes when needed).


CONSTRAINTS
-time will contain exactly 5 characters and will be formatted as "HH:MM".
-HH will be one of {01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12}.
-MM will be one of {00, 05, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55}.


EXAMPLES

0)
"11:20"

Returns: "04:55"

The example from the problem statement.

1)
"02:25"

Returns: "05:10"



2)
"06:30"

Returns: "06:30"



3)
"05:55"

Returns: "11:25"



4)
"03:45"

Returns: "09:15"



5)
"01:00"

Returns: "12:05"



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
		cout << "Testing EllysTimeMachine (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1459008004;
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
		EllysTimeMachine _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "11:20";
				_expected = "04:55";
				_received = _obj.getTime(time); break;
			}
			case 1:
			{
				string time = "02:25";
				_expected = "05:10";
				_received = _obj.getTime(time); break;
			}
			case 2:
			{
				string time = "06:30";
				_expected = "06:30";
				_received = _obj.getTime(time); break;
			}
			case 3:
			{
				string time = "05:55";
				_expected = "11:25";
				_received = _obj.getTime(time); break;
			}
			case 4:
			{
				string time = "03:45";
				_expected = "09:15";
				_received = _obj.getTime(time); break;
			}
			case 5:
			{
				string time = "01:00";
				_expected = "12:05";
				_received = _obj.getTime(time); break;
			}
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
			}*/
			/*case 7:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
			}*/
			/*case 8:
			{
				string time = ;
				_expected = ;
				_received = _obj.getTime(time); break;
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
