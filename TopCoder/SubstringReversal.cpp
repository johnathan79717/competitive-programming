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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
 
typedef vector<int> VI;

struct SubstringReversal {
  vector <int> solve(string S) {
  	int N = S.size();
  	string smallest(N, 127);
  	// cout << S << endl;
  	PER(i, N-1) {
  		smallest[i] = min(smallest[i+1], S[i+1]);
  		// cout << smallest[i] << endl;
  	}
  	vector<int> ans = {0, 0};
  	string best = S;
  	REP(i, N) {
  		if(S[i] <= smallest[i]) continue;
  		REP1(j, i+1, N-1) {
  			if(S[j] == smallest[i]) {
  				string tmp = S;
  				int l = i, r = j;
  				while(l < r) swap(tmp[l++], tmp[r--]);
  				if(tmp < best || (tmp == best && ans > VI({i, j}))) {
  					best = tmp;
  					ans = {i, j};
  				}
  			}
  		}
  		break;
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

You are given a string S. The string can have up to 2500 
characters.


You have to reverse exactly one substring of S. Formally, 
you have to choose two 0-based indices {x,y} such that x 
<= y, and then you have to reverse the order of the 
letters with indices x through y, inclusive. That is, S[x]S
[x+1]...S[y] becomes S[y]...S[x+1]S[x].


For example, if S="abcdefg", you can choose the indices 
{2,5} to obtain "abfedcg", the indices {0,1} to obtain 
"bacdefg", or the indices {3,3} to obtain "abcdefg". (In 
the last example, only one letter was selected, so the 
string did not change.)


Your goal is to produce the lexicographically smallest 
string possible. Return a vector <int> containing two 
elements: the optimal indices x and y.
If there are multiple optimal choices, find the one with 
the smallest x.
If there are still multiple optimal choices, find the one 
with the smallest y.


DEFINITION
Class:SubstringReversal
Method:solve
Parameters:string
Returns:vector <int>
Method signature:vector <int> solve(string S)


NOTES
-Given two strings A and B of equal length, we say that A 
is lexicographically smaller than B if A has a smaller 
character than B at the first position where they differ.


CONSTRAINTS
-S will contain between 1 and 2500 elements, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"abdc"

Returns: {2, 3 }

Reverse "dc" to "cd".

1)
"aabbcc"

Returns: {0, 0 }

Nothing to reverse here, you cannot produce a 
lexicographically smaller string.

2)
"misof"

Returns: {0, 4 }

Reverse the entire string.

3)
"ivan"

Returns: {0, 2 }

Reverse "iva" to bring 'a' to the beginning.

4)
"thisseemstobeaneasyproblem"

Returns: {0, 13 }



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
		cout << "Testing SubstringReversal (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1404576006;
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
		SubstringReversal _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "abdc";
				int __expected[] = {2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}
			case 1:
			{
				string S = "aabbcc";
				int __expected[] = {0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}
			case 2:
			{
				string S = "misof";
				int __expected[] = {0, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}
			case 3:
			{
				string S = "ivan";
				int __expected[] = {0, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}
			case 4:
			{
				string S = "thisseemstobeaneasyproblem";
				int __expected[] = {0, 13 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}
			/*case 5:
			{
				string S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}*/
			/*case 6:
			{
				string S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
			}*/
			/*case 7:
			{
				string S = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.solve(S); break;
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
