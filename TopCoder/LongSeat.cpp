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

class LongSeat {
	public:
	vector <string> canSit(int L, vector <int> width) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In this problem we are using half-open intervals.
The half-open interval from x (inclusive) to y (exclusive) is denoted [x,y).
Formally, [x,y) is the set of all real numbers z such that x <= z < y.


When cat Snuke last traveled by train, he noticed that there was a long seat.
Whenever a passenger boarded the train, if there was enough room for the passenger somewhere on the seat, the passenger sat down somewhere.
Otherwise, the passenger had to stand.


Formally, the seat can be represented as the half-open interval [0,L).
A person of width w sitting at coordinate x covers the interval [x,x+w).
People may sometimes sit on non-integer coordinates.
For each sitting passenger the interval covered by the passenger must be a subset of the seat.
The intervals covered by different sitting passengers must be disjoint.


You are given the int L and a vector <int> width.
L is the length of the seat.
The seat is currently empty.
Elements of width are the widths of passengers in the order in which they will board the train.
You are guaranteed that each person who is able to sit down will sit down somewhere.
However, note that sometimes there can be multiple (even infinitely many) places where a person can sit.
In that case, the person may choose any of those places, and you have no information about which place they will choose.


Return a vector <string> that contains the same number of elements as width.
For each valid i, element i of your return value should be:

"Sit" if we are sure that the i-th passenger (0-based index) will have a place to sit.
"Stand" if we are sure that the i-th passenger will have to stand.
"Unsure" otherwise (i.e., if it is possible but not certain that this passenger will have a place to sit).


DEFINITION
Class:LongSeat
Method:canSit
Parameters:int, vector <int>
Returns:vector <string>
Method signature:vector <string> canSit(int L, vector <int> width)


CONSTRAINTS
-L will be between 1 and 10^9, inclusive.
-width will contain between 1 and 8 elements, inclusive.
-Each element of width will be between 1 and 10^9, inclusive.


EXAMPLES

0)
2
{1, 1}

Returns: {"Sit", "Unsure" }

The first passenger will sit down for sure.
We are unsure about the second passenger: for example, if the first passenger sits at 0 and fills the interval [0, 1), there is enough room for the second passenger to sit, however, if the first passenger sits at 0.5 and fills the interval [0.5, 1.5), the second passenger has to stand.

1)
10
{100, 2, 4, 2}

Returns: {"Stand", "Sit", "Sit", "Unsure" }



2)
37
{3, 7, 5, 6, 4, 4, 1, 3}

Returns: {"Sit", "Sit", "Sit", "Unsure", "Unsure", "Unsure", "Sit", "Unsure" }



3)
400
{92, 65, 99, 46, 24, 85, 95, 84}

Returns: {"Sit", "Sit", "Unsure", "Unsure", "Unsure", "Unsure", "Stand", "Unsure" }



4)
1000000000
{1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}

Returns: {"Sit", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }



5)
1
{1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000}

Returns: {"Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" }



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
		cout << "Testing LongSeat (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1437201039;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LongSeat _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int L = 2;
				int width[] = {1, 1};
				string __expected[] = {"Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 1:
			{
				int L = 10;
				int width[] = {100, 2, 4, 2};
				string __expected[] = {"Stand", "Sit", "Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 2:
			{
				int L = 37;
				int width[] = {3, 7, 5, 6, 4, 4, 1, 3};
				string __expected[] = {"Sit", "Sit", "Sit", "Unsure", "Unsure", "Unsure", "Sit", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 3:
			{
				int L = 400;
				int width[] = {92, 65, 99, 46, 24, 85, 95, 84};
				string __expected[] = {"Sit", "Sit", "Unsure", "Unsure", "Unsure", "Unsure", "Stand", "Unsure" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 4:
			{
				int L = 1000000000;
				int width[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				string __expected[] = {"Sit", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			case 5:
			{
				int L = 1;
				int width[] = {1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000, 1000000000};
				string __expected[] = {"Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand", "Stand" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}
			/*case 6:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int L = ;
				int width[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.canSit(L, vector <int>(width, width+sizeof(width)/sizeof(int))); break;
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
