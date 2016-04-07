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
#include <cassert>
#include <list>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define ALL(x) (x).begin(),(x).end()
#define FOR(i, c) for(auto &i: c)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define V(T) vector<T >
#define EB emplace_back
#define SZ(x) (x).size()
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class JanuszTheBusinessman {
	public:
	int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
		V(VI) arr(366), dep(366);
		REP(i, SZ(arrivals)) {
			arr[arrivals[i]].PB(i);
		}
		REP(i, SZ(departures)) {
			dep[departures[i]].PB(i);
		}
		VI curr;
		int ans = 0, until = 0;
		REP1(i, 1, 365) {
			if (i <= until) continue;
			FOR(a, arr[i]) {
				curr.PB(a);
			}
			FOR(a, curr) {
				if (find(ALL(dep[i]), a) != dep[i].end()) {
					int m = -1;
					assert(!curr.empty());
					FOR(j, curr) {
						m = max(m, departures[j]);
					}
					ans++;
					until = m;
					curr.clear();
					break;
				}
			}
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Janusz owns a hotel.
He has already received some reservations for the upcoming year.
The days in the year are numbered 1 through 365.
For each valid i, there is a guest who will arrive on day arrivals[i] and depart on day departures[i].

Janusz can give some guests a special promotion.
Any guest that gets the special promotion will leave a good review.
Additionally, all guests that meet a guest with promotion will also leave a good review.
(Here we assume that two guests meet if and only if they are in the hotel on the same day, including the situation when one of them departs on the same day the other one arrives.)

Janusz wants to make sure that all his guests leave good reviews.
You are given the vector <int>s arrivals and departures.
Return the smallest possible number of special promotions sufficient to make sure that all guests leave good reviews.


DEFINITION
Class:JanuszTheBusinessman
Method:makeGuestsReturn
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int makeGuestsReturn(vector <int> arrivals, vector <int> departures)


CONSTRAINTS
-arrivals and departures will have the same number of elements.
-arrivals will have between 2 and 50 elements, inclusive.
-Each element of arrivals and departures will be between 1 and 365, inclusive.
-For each valid i arrivals[i] will be less than departures[i].


EXAMPLES

0)
{2, 10, 6}	
{6, 11, 9}

Returns: 2

One promotion is not enough.
One optimal solution is to give promotions to the guest who arrives on day 2 and to the guest who arrives on day 10.
The third guest will meet the first guest on day 6.

1)
{2, 10, 23, 34, 45, 123, 1}
{25, 12, 40, 50, 48, 187, 365}

Returns: 1

One guest is going to stay for the whole season so Janusz can give the promotion only to him.

2)
{8, 12, 20, 30, 54, 54, 68, 75}
{13, 31, 30, 53, 55, 70, 80, 76}

Returns: 3



3)
{124, 328, 135, 234, 347, 124, 39, 99, 116, 148}
{237, 335, 146, 246, 353, 213, 197, 215, 334, 223}

Returns: 2



4)
{154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}
{159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}

Returns: 14



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
		cout << "Testing JanuszTheBusinessman (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421078664;
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
		JanuszTheBusinessman _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int arrivals[] = {2, 10, 6}	;
				int departures[] = {6, 11, 9};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 1:
			{
				int arrivals[] = {2, 10, 23, 34, 45, 123, 1};
				int departures[] = {25, 12, 40, 50, 48, 187, 365};
				_expected = 1;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 2:
			{
				int arrivals[] = {8, 12, 20, 30, 54, 54, 68, 75};
				int departures[] = {13, 31, 30, 53, 55, 70, 80, 76};
				_expected = 3;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 3:
			{
				int arrivals[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148};
				int departures[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223};
				_expected = 2;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			case 4:
			{
				int arrivals[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6};
				int departures[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13};
				_expected = 14;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}
			/*case 5:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int arrivals[] = ;
				int departures[] = ;
				_expected = ;
				_received = _obj.makeGuestsReturn(vector <int>(arrivals, arrivals+sizeof(arrivals)/sizeof(int)), vector <int>(departures, departures+sizeof(departures)/sizeof(int))); break;
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
