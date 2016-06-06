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
// #line 40 "ZigZag.cpp"
#include <string>
#include <vector>
class ZigZag {
public:
    int longestZigZag(vector <int> sequence) {
        int N = sequence.size();
        vector<int> up(N), down(N);
        up[0] = down[0] = 1;
        int ans = 1;
        for (int i = 1; i < N; i++) {
            up[i] = down[i] = 1;
            for (int j = 0; j < i; j++) {
                if (sequence[j] < sequence[i]) {
                    up[i] = max(up[i], down[j] + 1);
                } else if (sequence[j] > sequence[i]) {
                    down[i] = max(down[i], up[j] + 1);
                }
            }
            ans = max(ans, max(up[i], down[i]));
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A sequence of numbers is called a zig-zag sequence if the differences
between successive numbers strictly alternate between positive and negative.  The
first difference (if one exists) may be either positive or negative.  A sequence with
fewer than two elements is trivially a zig-zag sequence.



For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences
(6,-3,5,-7,3) are alternately positive and negative.  In contrast, 1,4,7,2,5
and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and
the second because its last difference is zero.



Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is
a zig-zag sequence.  A subsequence is obtained by deleting some number of
elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.



DEFINITION
Class:ZigZag
Method:longestZigZag
Parameters:vector <int>
Returns:int
Method signature:int longestZigZag(vector <int> sequence)


CONSTRAINTS
-sequence contains between 1 and 50 elements, inclusive.
-Each element of sequence is between 1 and 1000, inclusive.


EXAMPLES

0)
{ 1, 7, 4, 9, 2, 5 }

Returns: 6

The entire sequence is a zig-zag sequence.

1)
{ 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }

Returns: 7

There are several subsequences that achieve this length.  One is 1,17,10,13,10,16,8.

2)
{ 44 }

Returns: 1

3)
{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }

Returns: 2

4)
{ 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }

Returns: 8

5)
{ 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }


Returns: 36

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
		cout << "Testing ZigZag (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463309089;
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
		ZigZag _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int sequence[] = { 1, 7, 4, 9, 2, 5 };
				_expected = 6;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 1:
			{
				int sequence[] = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
				_expected = 7;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 2:
			{
				int sequence[] = { 44 };
				_expected = 1;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 3:
			{
				int sequence[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
				_expected = 2;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 4:
			{
				int sequence[] = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
				_expected = 8;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			case 5:
			{
				int sequence[] = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
				                 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
				                 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
				                 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
				                 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
				_expected = 36;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}
			/*case 6:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int sequence[] = ;
				_expected = ;
				_received = _obj.longestZigZag(vector <int>(sequence, sequence+sizeof(sequence)/sizeof(int))); break;
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
