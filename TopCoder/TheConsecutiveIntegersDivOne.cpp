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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class TheConsecutiveIntegersDivOne {
	public:
	int find(vector <int> numbers, int k) {
		int ans = 1e9;
		sort(ALL(numbers));
		REP(i, numbers.size()) {
			REP(j, k) {
				if (i < j) continue;
				if (i - j + k-1 >= numbers.size()) continue;
				int tmp = 0;
				REP(l, k) {
					tmp += abs(numbers[i-j+l] - (numbers[i] - j + l));
				}
				ans = min(ans, tmp);
			}
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// John and Brus have some integers.
You are given these integers in a vector <int> numbers.
In one operation they can pick a number and increase/decrease it by 1.
They want to have at least k consecutive integers.
The order in which those integers appear in numbers does not matter.
Return the minimal number of operations required to achieve the goal.


DEFINITION
Class:TheConsecutiveIntegersDivOne
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> numbers, int k)


CONSTRAINTS
-numbers will contain between 2 and 47 elements, inclusive.
-Each element of numbers will be between -10,000,000 and 10,000,000, inclusive.
-All elements of numbers will be distinct.
-k will be between 1 and the number of elements in numbers, inclusive.


EXAMPLES

0)
{4, 7, 47}
2

Returns: 2

There are three optimal strategies:

Increase 4 two times to obtain {6,7,47}.
Decrease 7 two times to obtain {4,5,47}.
Increase 4 and decrease 7 to obtain {5,6,47}.



1)
{1, 100}
1

Returns: 0

No operation is needed.

2)
{-96, -53, 82, -24, 6, -75}
2

Returns: 20



3)
{64, -31, -56}
2

Returns: 24



4)
{-96, -53, 82, -24, 6, -75}
4

Returns: 90



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
		cout << "Testing TheConsecutiveIntegersDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1421374285;
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
		TheConsecutiveIntegersDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numbers[] = {4, 7, 47};
				int k = 2;
				_expected = 2;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 1:
			{
				int numbers[] = {1, 100};
				int k = 1;
				_expected = 0;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 2:
			{
				int numbers[] = {-96, -53, 82, -24, 6, -75};
				int k = 2;
				_expected = 20;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 3:
			{
				int numbers[] = {64, -31, -56};
				int k = 2;
				_expected = 24;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			case 4:
			{
				int numbers[] = {-96, -53, 82, -24, 6, -75};
				int k = 4;
				_expected = 90;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}
			/*case 5:
			{
				int numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}*/
			/*case 6:
			{
				int numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
			}*/
			/*case 7:
			{
				int numbers[] = ;
				int k = ;
				_expected = ;
				_received = _obj.find(vector <int>(numbers, numbers+sizeof(numbers)/sizeof(int)), k); break;
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
