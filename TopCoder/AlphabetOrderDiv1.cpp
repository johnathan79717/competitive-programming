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

#line 40 "AlphabetOrderDiv1.cpp"
#include <string>
#include <vector>
class AlphabetOrderDiv1 {
public:
  string isOrdered(vector <string> words) {

  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// The ancient civilization of Nlogonia used the same 26 letters as modern English: 'a'-'z'.
However, we do not know the order in which these letters appeared in the Nlogonian alphabet.

One particular custom in Nlogonia was that in a good word the letters appear in non-decreasing order.
For example, in English the word "ciel" is not a good word because in the alphabet 'i' is after 'e'.
The word "ceil" is a good word because 'c' <= 'e' <= 'i' <= 'l'.

You are given the vector <string> words.
Each element of words is a nonempty string of lowercase English letters.
Return "Possible" if it is possible that all elements of words were good words in Nlogonian, and "Impossible" otherwise.

In other words, return "Possible" if and only if there is at least one possible Nlogonian alphabet such that the letters of each word in words are in non-decreasing alphabetical order.

DEFINITION
Class:AlphabetOrderDiv1
Method:isOrdered
Parameters:vector <string>
Returns:string
Method signature:string isOrdered(vector <string> words)


CONSTRAINTS
-words has between 2 and 100 elements inclusive.
-The size of each element of words will be between 1 and 100 inclusive.
-Elements of words contains only English lowercase letters from 'a' to 'z'.


EXAMPLES

0)
{"single","round","match"}

Returns: "Possible"

A possible Nlogonian alphabet would be "bfjkmapqrositchundglevwxyz"

1)
{"topcoder","topcoder"}

Returns: "Impossible"

The word "topcoder" can never be a good word.
The character 'o' cannot be both before 'p' and after 'p' in the alphabet.

2)
{"algorithm", "contest"}

Returns: "Impossible"



3)
{"pink","floyd"}

Returns: "Possible"



4)
{"gimnasia","y","esgrima","la","plata"}

Returns: "Impossible"



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
		cout << "Testing AlphabetOrderDiv1 (225.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1485013837;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 225.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AlphabetOrderDiv1 _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string words[] = {"single","round","match"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string words[] = {"topcoder","topcoder"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string words[] = {"algorithm", "contest"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string words[] = {"pink","floyd"};
				_expected = "Possible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string words[] = {"gimnasia","y","esgrima","la","plata"};
				_expected = "Impossible";
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 5:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string words[] = ;
				_expected = ;
				_received = _obj.isOrdered(vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
