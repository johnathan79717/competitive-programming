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
#include <cassert>
#include <climits>
#include <set>
#include <vector>
#include <functional>
#include <stack>
#include <unordered_set>
#include <unordered_map>
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
#define MAX(x, a) x = max(x, a)
#define MIN(x, a) x = min(x, a)
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "RoomPairs.cpp"
#include <string>
#include <vector>
class RoomPairs {
public:
    vector <string> construct(int R, int C, int N) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is a building. Its floor is a R times C rectangle divided into a grid of unit squares.
You are going to build walls along the sides of some unit squares.
This will divide the building into one or more rooms.
Two rooms are adjacent if they share a common wall segment.
(Touching corners are not enough.)


Can you build the walls in such a way that there will be exactly N pairs of adjacent rooms?
If yes, find and return any valid solution and return its ASCII art drawing as a vector <string>.
If no, return an empty vector <string> instead.


See the Examples for the proper output format. A formal definition is given in the Notes but should not be needed.


DEFINITION
Class:RoomPairs
Method:construct
Parameters:int, int, int
Returns:vector <string>
Method signature:vector <string> construct(int R, int C, int N)


NOTES
-The ASCII art must have 2*R+1 rows and 2*C+1 columns.
-Each character with both (0-based) coordinates even must be '+'. These characters represent corners of unit squares.
-Each character with both (0-based) coordinates odd must be ' '. These characters represent the individual unit squares.
-Each character with coordinates [even][odd] must be either ' ' (representing the absence of a wall) or '-' (representing the presence of a wall).
-Each character with coordinates [odd][even] must be either ' ' (representing the absence of a wall) or '|' (representing the presence of a wall).
-Characters on the boundary cannot be spaces. These characters represent the outer wall of the building.


CONSTRAINTS
-R will be between 1 and 30, inclusive.
-C will be between 1 and 30, inclusive.
-N will be between 0 and R*(C-1) + (R-1)*C, inclusive.


EXAMPLES

0)
2
4
1

Returns: {"+-+-+-+-+", "| |   | |", "+ + +-+ +", "|   |   |", "+-+-+-+-+" }

Formatted output:

{"+-+-+-+-+",
 "| |   | |",
 "+ + +-+ +",
 "|   |   |",
 "+-+-+-+-+"}


There are only two rooms, they form one pair of adjacent rooms.


Note that the bigger room contains one extra wall that does not change anything. This is allowed.


1)
3
3
4

Returns: {"+-+-+-+", "| | | |", "+-+ +-+", "|     |", "+-+ +-+", "| | | |", "+-+-+-+" }

Formatted output:

{"+-+-+-+",
 "| | | |",
 "+-+ +-+",
 "|     |",
 "+-+ +-+",
 "| | | |",
 "+-+-+-+"}


The big middle room is adjacent to each of the four small rooms.


2)
3
4
3

Returns: {"+-+-+-+-+", "|       |", "+ +-+-+ +", "| | | | |", "+ +-+-+ +", "|       |", "+-+-+-+-+" }



3)
4
5
31

Returns: {"+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+" }



*/
// END CUT HERE

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
		cout << "Testing RoomPairs (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1595089593;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RoomPairs _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 2;
				int C = 4;
				int N = 1;
				string __expected[] = {"+-+-+-+-+", "| |   | |", "+ + +-+ +", "|   |   |", "+-+-+-+-+" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 1:
			{
				int R = 3;
				int C = 3;
				int N = 4;
				string __expected[] = {"+-+-+-+", "| | | |", "+-+ +-+", "|     |", "+-+ +-+", "| | | |", "+-+-+-+" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 2:
			{
				int R = 3;
				int C = 4;
				int N = 3;
				string __expected[] = {"+-+-+-+-+", "|       |", "+ +-+-+ +", "| | | | |", "+ +-+-+ +", "|       |", "+-+-+-+-+" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			case 3:
			{
				int R = 4;
				int C = 5;
				int N = 31;
				string __expected[] = {"+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+", "| | | | | |", "+-+-+-+-+-+" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}
			/*case 4:
			{
				int R = ;
				int C = ;
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}*/
			/*case 5:
			{
				int R = ;
				int C = ;
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int N = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(R, C, N); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
