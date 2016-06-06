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
// #line 40 "UnsortedSequence.cpp"
#include <string>
#include <vector>
class UnsortedSequence {
public:
    vector <int> getUnsorted(vector <int> s) {
        sort(s.begin(), s.end());
        if (next_permutation(s.begin(), s.end())) {
            return s;
        } else {
            return {};
        }
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We say that the sequence of numbers {s[0], s[1], s[2], ..., s[N-1]} is sorted in ascending order if we have s[i] <= s[i+1] for each i between 0 and N-2, inclusive.

For example, the sequences {1,2,3}, {1,1,1}, and {2,2,4,4,6,6} are sorted in ascending order, but the sequences {1,2,1}, {7,4,6}, and {3,2,1} are not.

You are given the sequence of numbers as a vector <int> s. Your task is to order the elements of this sequence into a sequence that will NOT be sorted in ascending order. Find and return the lexicographically smallest sequence we can obtain. If there is no possibility to get a sequence that is not sorted in ascending order, return an empty vector <int> instead.

DEFINITION
Class:UnsortedSequence
Method:getUnsorted
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getUnsorted(vector <int> s)


NOTES
-Sequence of numbers A is lexicographically smaller than B if A contains a smaller number on the first position on which they differ.
-The sequence s may contain duplicates.
-Note that the sequence consisting of only one element is always sorted.


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element of s will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,2}

Returns: {2, 1 }

There is only one possible sequence that is not in ascending order: {2,1}.

1)
{1,2,3}

Returns: {1, 3, 2 }

Out of all six possible sequences, five are not in ascending order. Here they are, in lexicographic order:

{1,3,2}
{2,1,3}
{2,3,1}
{3,1,2}
{3,2,1}


2)
{7,2,2}

Returns: {2, 7, 2 }

Remember, that the given sequence may contain duplicates.

3)
{1000}

Returns: { }

As mentioned in the Notes section, the sequence consisting of only one element is always sorted. So there is no possibility to unsort this sequence. 

4)
{1,1}

Returns: { }

There are also some longer sequences that cannot be unsorted.

5)
{1,2,4,3}

Returns: {1, 2, 4, 3 }



6)
{2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10}

Returns: {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 }



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
		cout << "Testing UnsortedSequence (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463326016;
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
		UnsortedSequence _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int s[] = {1,2};
				int __expected[] = {2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 1:
			{
				int s[] = {1,2,3};
				int __expected[] = {1, 3, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 2:
			{
				int s[] = {7,2,2};
				int __expected[] = {2, 7, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 3:
			{
				int s[] = {1000};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 4:
			{
				int s[] = {1,1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 5:
			{
				int s[] = {1,2,4,3};
				int __expected[] = {1, 2, 4, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			case 6:
			{
				int s[] = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
				int __expected[] = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}
			/*case 7:
			{
				int s[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int s[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int s[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getUnsorted(vector <int>(s, s+sizeof(s)/sizeof(int))); break;
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
