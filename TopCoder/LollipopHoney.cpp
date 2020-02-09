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

#line 41 "LollipopHoney.cpp"
#include <string>
#include <vector>
class LollipopHoney {
public:
    vector <int> count(int K, vector <int> flavor, vector <int> deliciousness) {

    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Yui loves lollipops. She has a precious collection of tasty lollipops.
Each lollipop has some flavor and some level of deliciousness. Both parameters are represented by positive integers.
You are given the information about Yui's collection in the vector <int>s flavor and deliciousness. For each i, flavor[i] and deliciousness[i] represent one lollipop in the collection.
Yui wants to give 2K lollipops to her best friend as a birthday present. She wants to satisfy the following conditions:

It must be possible to split the lollipops into K pairs such that within each pair the two lollipops have different flavors.
The total deliciousness of all 2K selected lollipops must be maximized.

If Yui cannot select K pairs of lollipops meeting the conditions, return an empty vector <int>. Otherwise, return a vector <int> with two elements: Element 0 should be the largest possible total deliciousness of selected lollipops, and element 1 should be the number of ways in which the set of 2K lollipops can be selected, modulo 1,000,000,007.

DEFINITION
Class:LollipopHoney
Method:count
Parameters:int, vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> count(int K, vector <int> flavor, vector <int> deliciousness)


NOTES
-Two ways of selecting lollipops differ if and only if there exists a lollipop which is selected in one way and not in the other way.


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-K will be between 1 and N/2, inclusive.
-flavor will contain exactly N elements.
-deliciousness will contain exactly N elements.
-Each element in flavor will be between 1 and 50, inclusive.
-Each element in deliciousness will be between 1 and 10^7, inclusive.


EXAMPLES

0)
1 
{1,1,2,2}

{10,20,30,40}


Returns: {60, 1 }

Yui must select lollipop 1 (flavor 1, deliciousness 20) and lollipop 3 (flavor 2, deliciousness 40). The total deliciousness is 20+40 = 60, and this solution is unique.

1)
2 
{1,1,1,2,2,2}

{10,10,10,20,20,20}


Returns: {60, 9 }

Yui must select two of the three lollipops with flavor 1 and two of the three lollipops with flavor 2.
Note that she cannot select three lollipops with flavor 2 and one element with flavor 1: the total deliciousness would be higher, but she would not be able to create two pairs of lollipops such that within each pair the flavors are distinct.

2)
2 
{1,1,1,1,1,2}
{10,20,30,40,50,60}


Returns: { }

Here, Yui is unable to select 2K lollipops with the desired properties.

3)
3 
{48,33,22,9,37,44,5,49,24,14,45,1}

{9,1,7,10,7,10,5,1,3,3,4,5}


Returns: {48, 2 }



4)
10 
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}

{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}


Returns: {20, 846527861 }

Please don't forget to use modulo 1,000,000,007 when computing the number of ways.

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
		cout << "Testing LollipopHoney (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1557503498;
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
		LollipopHoney _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int K = 1 ;
				int flavor[] = {1,1,2,2};
				int deliciousness[] = {10,20,30,40};
				int __expected[] = {60, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}
			case 1:
			{
				int K = 2 ;
				int flavor[] = {1,1,1,2,2,2};
				int deliciousness[] = {10,10,10,20,20,20};
				int __expected[] = {60, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}
			case 2:
			{
				int K = 2 ;
				int flavor[] = {1,1,1,1,1,2};
				int deliciousness[] = {10,20,30,40,50,60};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}
			case 3:
			{
				int K = 3 ;
				int flavor[] = {48,33,22,9,37,44,5,49,24,14,45,1};
				int deliciousness[] = {9,1,7,10,7,10,5,1,3,3,4,5};
				int __expected[] = {48, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}
			case 4:
			{
				int K = 10 ;
				int flavor[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
				int deliciousness[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int __expected[] = {20, 846527861 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}
			/*case 5:
			{
				int K = ;
				int flavor[] = ;
				int deliciousness[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int K = ;
				int flavor[] = ;
				int deliciousness[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int K = ;
				int flavor[] = ;
				int deliciousness[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(K, vector <int>(flavor, flavor+sizeof(flavor)/sizeof(int)), vector <int>(deliciousness, deliciousness+sizeof(deliciousness)/sizeof(int))); break;
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
