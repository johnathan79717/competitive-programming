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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#line 40 "TreesAndBrackets.cpp"
#include <string>
#include <vector>
class TreesAndBrackets {
public:
  string t1, t2;
  bool check(int l1, int r1, int l2, int r2) {
    if (l2 == r2) {
      return true;
    }
    if (l1 == r1) {
      return false;
    }
    int i = l1;
    int c = 0;
    do {
      if (t1[i++] == '(') {
	c++;
      } else {
	c--;
      }
    } while(c);
    c = 0;
    int j = l2;
    do {
      if (t2[j++] == '(') {
	c++;
      } else {
	c--;
      }
    } while(c);
    if (i == r1) {
      if (j == r2) {
	return check(l1+1, r1-1, l2+1, r2-1);
      } else {
	return false;
      }
    }
    if (check(l1, i, l2, j) && check(i, r1, j, r2)) {
      return true;
    }
    return check(i, r1, l2, r2);
  }
  string check(string x, string y) {
    t1.swap(x);
    t2.swap(y);
    return check(0, t1.size(), 0, t2.size()) ? "Possible" : "Impossible";
  }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// This problem is about rooted trees in which the order of children matters.
This type of trees is easily encoded using correct bracket sequences.
The code of a tree rooted at r is constructed as follows:

Write down the opening bracket '('.
For each child c of r, in order, write down the code of the subtree rooted at c.
Write down the closing bracket ')'.


For example, the code of a three-vertex tree in which the root has two children is "(()())".

You are given the strings t1 and t2 that represent two rooted trees using the encoding defined above.
You want to transform t1 into t2.


The only operation you are allowed to perform is to remove a leaf from t1.
(A leaf is a vertex with no children.)
Note that removing the child of a parent does not change the relative order of the other children of that same parent.


Return "Possible" if there is a sequence of zero or more operations that transforms t1 into t2.
Otherwise, return "Impossible".

DEFINITION
Class:TreesAndBrackets
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string t1, string t2)


CONSTRAINTS
-t1 and t2 will contain between 2 and 100 characters, inclusive.
-Each character in t1 and t2 will be either '(' or ')'.
-Both t1 and t2 will represent a correct tree.


EXAMPLES

0)
"(())"
"()"

Returns: "Possible"



1)
"()"
"()"

Returns: "Possible"



2)
"(()()())"
"((()))"

Returns: "Impossible"

Currently t1 is a tree of depth 2 in which the root has three children, while t2 is a tree of depth 3.
Clearly, you cannot increase the depth of a tree by removing some of its vertices.

3)
"((())((())())())"
"(()(())())"

Returns: "Possible"



4)
"((())((())())())"
"((()()()()()))"

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
		cout << "Testing TreesAndBrackets (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1521302403;
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
		TreesAndBrackets _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string t1 = "(())";
				string t2 = "()";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 1:
			{
				string t1 = "()";
				string t2 = "()";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 2:
			{
				string t1 = "(()()())";
				string t2 = "((()))";
				_expected = "Impossible";
				_received = _obj.check(t1, t2); break;
			}
			case 3:
			{
				string t1 = "((())((())())())";
				string t2 = "(()(())())";
				_expected = "Possible";
				_received = _obj.check(t1, t2); break;
			}
			case 4:
			{
				string t1 = "((())((())())())";
				string t2 = "((()()()()()))";
				_expected = "Impossible";
				_received = _obj.check(t1, t2); break;
			}
			/*case 5:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
			}*/
			/*case 6:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
			}*/
			/*case 7:
			{
				string t1 = ;
				string t2 = ;
				_expected = ;
				_received = _obj.check(t1, t2); break;
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
