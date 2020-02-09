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
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 41 "SelfDescFind.cpp"
#include <string>
#include <vector>

int ans[10] = {}, cnt[10] = {}, N;
string ret = "";
VI digits;

void dfs(int i, int sum) {
    if (i == N) {
	bool fail = false;
	REP(d, 10) {
	    if (ans[d] != cnt[d]) {
		fail = true;
		break;
	    }
	}
	if (!fail) {
	    VI x;
	    for (int d : digits) {
		x.push_back(ans[d] * 10 + d);
	    }
	    sort(ALL(x));
	    char s[25] = {};
	    for (int k = 0; k < N; k++) {
		s[2 * k] = x[k] / 10 + '0';
		s[2 * k + 1] = x[k] % 10 + '0';
	    }
	    if (ret.empty() || s < ret) {
		ret = s;
	    }
	}
	return;
    }
    int j = 1;
    int d = digits[i];
    while (j <= 9 && sum + j <= 2 * N) {
	ans[d] = j;
	cnt[d]++;
	cnt[j]++;
	dfs(i+1, sum + j);
	cnt[d]--;
	cnt[j]--;
	j++;
    }
}

class SelfDescFind {
public:
    string construct(vector <int> dd) {
	digits = dd;
	unordered_set<int> s;
	for (int d : digits) {
	    s.insert(d);
	}
	N = digits.size();
	dfs(0, 0);
	return ret;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The number 31143310 is self-describing because we can read it as the statement "this number contains three '1's, one '4's, three '3's, and one '0'", and that statement correctly describes the whole number.


More formally, a number is called self-describing if it satisfies the following:


It has an even number of digits. Below, we will label the individual digits a[0], b[0], a[1], b[1], ... from the left to the right.
The digits b[i] are all distinct.
For each valid i, the number contains exactly a[i] copies of the digit b[i].
The number does not contain any other digits, except for those described by the statements mentioned above.


You are given the vector <int> digits.
Find the smallest self-describing number N such that the digits that appear in N are precisely the digits in digits.
If such a number exists, return a string with its decimal representation.
Otherwise, return an empty string


DEFINITION
Class:SelfDescFind
Method:construct
Parameters:vector <int>
Returns:string
Method signature:string construct(vector <int> digits)


NOTES
-Watch out for integer overflow.


CONSTRAINTS
-digits will contain between 1 and 10 elements, inclusive.
-Each element of digits will be between 0 and 9, inclusive.
-The elements of digits will form a strictly increasing sequence.


EXAMPLES

0)
{1}

Returns: ""



1)
{2}

Returns: "22"

The smallest self-describing number is 22. It contains two '2's, and it says about itself that it contains two '2's.

2)
{0,1,3,4}

Returns: "10143133"



3)
{0,1,2,4,5,6,8,9}

Returns: ""



4)
{0,1,2,3,5,6,8,9}

Returns: "1016181923253251"



5)
{4}

Returns: ""

Note that 4444 is not a valid self-describing number.

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
		cout << "Testing SelfDescFind (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1557500428;
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
		SelfDescFind _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int digits[] = {1};
				_expected = "";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 1:
			{
				int digits[] = {2};
				_expected = "22";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 2:
			{
				int digits[] = {0,1,3,4};
				_expected = "10143133";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 3:
			{
				int digits[] = {0,1,2,4,5,6,8,9};
				_expected = "";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 4:
			{
				int digits[] = {0,1,2,3,5,6,8,9};
				_expected = "1016181923253251";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 5:
			{
				int digits[] = {4};
				_expected = "";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			case 6:
			{
				int digits[] = {0,1,2,3,4,5,6,7,8,9};
				_expected = "10141516181923273271";
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}
			/*case 7:
			{
				int digits[] = ;
				_expected = ;
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int digits[] = ;
				_expected = ;
				_received = _obj.construct(vector <int>(digits, digits+sizeof(digits)/sizeof(int))); break;
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
