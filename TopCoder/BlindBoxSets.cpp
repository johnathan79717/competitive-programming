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

#line 41 "BlindBoxSets.cpp"
#include <string>
#include <vector>
class BlindBoxSets {
public:
    double expectedPurchases(int numSets, int numItems) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A common selling trick for collectibles is the "blind box" format, in which there are multiple different designs for a certain collectible.
The outer packaging of the collectible does not indicate which design will be inside. 
Thus, collecting a complete set of designs means that a little bit of luck and persistence is required.
And getting all the designs will often involve getting several duplicates as well, which is precisely the point of this selling trick.



You want to collect numSets complete sets of designs of one particular collectible.
There are numItems different designs.
You are purchasing the collectibles one at a time, and each purchase will yield a design chosen uniformly at random.
What is the expected total number of purchases you will make until you collect at least numSets copies of each design?


DEFINITION
Class:BlindBoxSets
Method:expectedPurchases
Parameters:int, int
Returns:double
Method signature:double expectedPurchases(int numSets, int numItems)


NOTES
-Returned value must be within 1e-9 absolute or relative error of the reference output to be considered correct.


CONSTRAINTS
-numSets will be between 1 and 4, inclusive.
-numItems will be between 1 and 50, inclusive.


EXAMPLES

0)
1
1

Returns: 1.0

There is exactly one item, and you want one set of it. If you buy an item, you're guaranteed to get the one you're looking for.

1)
1
2

Returns: 3.0

There are two different designs and you want to have both of them. If you are lucky, two purchases are enough but sometimes you will need more. For example, with probability 1/8 the second and the third box you'll purchase will contain the same design as the first box, and only the fourth box will yield the other design.
On average, you will need to purchase exactly three boxes.

2)
2
1

Returns: 2.0

Since there's only one unique design, simply buying two items gets you two "complete sets".

3)
2
2

Returns: 5.5

After we buy two items, we have an even chance of either of two scenarios:

We already have two copies of the same design and we need two copies of the other. On average, this requires four more purchases.
We already have one copy of each design and we need one more copy of each design. This is the same situation as in Example #1 and thus on average it requires three more purchases.


So, on average, we need 2 + (4+3) / 2 = 5.5 total purchases.


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
		cout << "Testing BlindBoxSets (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1587227061;
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
		BlindBoxSets _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int numSets = 1;
				int numItems = 1;
				_expected = 1.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 1:
			{
				int numSets = 1;
				int numItems = 2;
				_expected = 3.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 2:
			{
				int numSets = 2;
				int numItems = 1;
				_expected = 2.0;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			case 3:
			{
				int numSets = 2;
				int numItems = 2;
				_expected = 5.5;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}
			/*case 4:
			{
				int numSets = ;
				int numItems = ;
				_expected = ;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			/*case 5:
			{
				int numSets = ;
				int numItems = ;
				_expected = ;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			/*case 6:
			{
				int numSets = ;
				int numItems = ;
				_expected = ;
				_received = _obj.expectedPurchases(numSets, numItems); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
