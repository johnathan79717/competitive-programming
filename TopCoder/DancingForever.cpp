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

class DancingForever {
	public:
	vector <int> getStablePairs(string x) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There are n boys and n girls in a dancing room.
Boys are numbered 0 through n-1.
Girls are also numbered 0 through n-1.
Each boy loves one or more girls.
You are given a string x with n*n characters.
For each i and j, x[i*n+j] is either 'Y' or 'N'.
Here, 'Y' means that boy i loves girl j and 'N' means that he does not love her.


Whenever a song starts playing, some couples go dance.
Obviously, all couples dancing in the same dance must be pairwise disjoint.
Each dancing couple must consist of a boy and a girl the boy loves.

After a dance, each boy who danced looks at all the girls that did not dance.
If that set of girls contains some girls he loves, he will choose one such girl G.
The boy will then abandon his current dance partner and he will go ask girl G for the next dance.

We are interested in a dance with the following properties:

There was at least one dancing couple.
After the dance, none of the boys wanted to change their dance partners.


If there is no such dance, return {-1}.
(Formally, return a vector <int> containing a single element: the value -1.)
Otherwise, choose any valid dance and output its description in the format specified below.
Any valid solution will be accepted.

A dance can be described by a sequence of dancing pairs, each in the order (boy,girl).
The correct return value is a vector <int> obtained by concatenating these pairs.
For example, the return value {4, 7, 0, 1} represents a dance where boy 4 danced with girl 7 and boy 0 danced with girl 1.

DEFINITION
Class:DancingForever
Method:getStablePairs
Parameters:string
Returns:vector <int>
Method signature:vector <int> getStablePairs(string x)


CONSTRAINTS
-n will be between 1 and 100, inclusive.
-x will contain exactly n*n characters.
-Each character in x will be 'Y' or 'N'.
-For each i, at least one of the characters x[n*i] to x[n*(i+1)-1] will be 'Y'.


EXAMPLES

0)
"YYNNNYYNNNYYYNNY"

Returns: {0, 0, 1, 1, 2, 2, 3, 3 }

Whenever a perfect matching exists, it is a valid solution: as all girls are dancing, no boy will want to change his partner.

1)
"YNNNYYNNYYNNNNYY"

Returns: {1, 0, 2, 1 }

There are multiple valid solutions.
Here are some of them:
{0, 0}, {0, 0, 1, 1}, {0, 0, 2, 1}, {1, 0, 2, 1}, and {1, 1, 2, 0}.

2)
"YNYYNYYNY"

Returns: {1, 0, 2, 2 }

Note that there may be girls who aren't loved by any boy.

3)
"YYYNNYYYNNNNNYYNNNYYNNNYY"

Returns: {3, 3, 4, 4 }



4)
"Y"

Returns: {0, 0 }



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
		cout << "Testing DancingForever (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1430839265;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 850.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DancingForever _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x = "YYNNNYYNNNYYYNNY";
				int __expected[] = {0, 0, 1, 1, 2, 2, 3, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 1:
			{
				string x = "YNNNYYNNYYNNNNYY";
				int __expected[] = {1, 0, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 2:
			{
				string x = "YNYYNYYNY";
				int __expected[] = {1, 0, 2, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 3:
			{
				string x = "YYYNNYYYNNNNNYYNNNYYNNNYY";
				int __expected[] = {3, 3, 4, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			case 4:
			{
				string x = "Y";
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}
			/*case 5:
			{
				string x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}*/
			/*case 6:
			{
				string x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
			}*/
			/*case 7:
			{
				string x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getStablePairs(x); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
