#line 2 "NextOlympics.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class NextOlympics {
public:
    int countDays(string today) {
	return 0;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Tokyo Olympics 2021 is scheduled to start from the opening ceremony in July 23rd, 2021.



Suzuki, a man who lives in Japan, is looking forward to seeing the opening ceremony.
Now, he wants to calculate how many days are remaining to the opening ceremony.
(For example, if the opening ceremony were tomorrow, there would be 1 day remaining.)



Today's date is given as a string today in the format "YYYY.MM.DD". Day and month numbers have an extra leading zero if necessary. Some examples:

If today's date is July 24th, 2020, today will be "2020.07.24".
If today's date is November 9th, 2020, today will be "2020.11.09".
If today's date is February 25th, 2021, today will be "2021.02.25".




For Suzuki, calculate and return how many days are remaining to the opening ceremony of Tokyo Olympics 2021.


DEFINITION
Class:NextOlympics
Method:countDays
Parameters:string
Returns:int
Method signature:int countDays(string today)


NOTES
-In this problem, you will implement the class "NextOlympics" with a public function named "countDays" which takes a string today as a parameter and returns an integer value.
-If you do not know about how to compete or how to write/compile/test/submit solutions, please refer to https://www.topcoder.com/community/competitive-programming/how-to-compete for detailed information about competing in SRM.
-And, don't forget testing at least on the example cases! In Applet Arena, you can test all example cases at once using "Batch Test". In Web Arena, you can test all example cases by checking all of them in the Test Panel.
-For testing on custom cases or attempting challenges in the Challenge Phase, the string you input should be enclosed in double quotes (""). For example, you can input "2020.07.24" including the quotes.


CONSTRAINTS
-The string today will represent a valid date (in Gregorian Calendar) from July 24th 2020 to July 23rd 2021, inclusive.


EXAMPLES

0)
"2020.07.24"

Returns: 364


TopCoder SRM 788 is taking place in July 24th, 2020. Here, Tokyo Olympics 2021 is less than one year from now!
Given this, 364 days are remaining to the opening ceremony of the Olympics.

By the way, July 24th, 2020 is a holiday in Japan called "Sports Day". It's a holiday to celebrate the Olympics.


1)
"2020.11.09"

Returns: 256


In this example, "today" is November 9th, 2020. Here, 256 days are remaining until the Olympics begin.
So, you should return 256 for this example. Suzuki has to wait 256 days for the opening ceremony.


2)
"2021.02.25"

Returns: 148


In this example, "today" is February 25th, 2021. Here, 148 days are remaining until the opening ceremony.
Suzuki has to wait 148 days for the opening ceremony.


3)
"2021.07.23"

Returns: 0


In this example, "today" is July 23rd, 2021. It's the day of the opening ceremony of the Tokyo Olympics 2021.
For this case, since there are 0 days remaining to the opening ceremony, you should return 0.


4)
"2020.12.31"

Returns: 204


In this example, "today" is December 31st, 2020. There are 204 days remaining to the opening ceremony.


5)
"2021.01.01"

Returns: 203


In this example, "today" is January 1st, 2021. There are 203 days remaining to the opening ceremony.


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
		cout << "Testing NextOlympics (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595628943;
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
		NextOlympics _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string today = "2020.07.24";
				_expected = 364;
				_received = _obj.countDays(today); break;
			}
			case 1:
			{
				string today = "2020.11.09";
				_expected = 256;
				_received = _obj.countDays(today); break;
			}
			case 2:
			{
				string today = "2021.02.25";
				_expected = 148;
				_received = _obj.countDays(today); break;
			}
			case 3:
			{
				string today = "2021.07.23";
				_expected = 0;
				_received = _obj.countDays(today); break;
			}
			case 4:
			{
				string today = "2020.12.31";
				_expected = 204;
				_received = _obj.countDays(today); break;
			}
			case 5:
			{
				string today = "2021.01.01";
				_expected = 203;
				_received = _obj.countDays(today); break;
			}
			/*case 6:
			{
				string today = ;
				_expected = ;
				_received = _obj.countDays(today); break;
			}*/
			/*case 7:
			{
				string today = ;
				_expected = ;
				_received = _obj.countDays(today); break;
			}*/
			/*case 8:
			{
				string today = ;
				_expected = ;
				_received = _obj.countDays(today); break;
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
