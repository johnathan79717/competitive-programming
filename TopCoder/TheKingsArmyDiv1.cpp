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
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

class TheKingsArmyDiv1 {
	public:
	int getNumber(vector <string> state) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
The King of Byteland has an army.
The army consists of 2N soldiers.
The King has arranged the soldiers into 2 rows by N columns.
Two soldiers are neighbors if they are located next to each other in a row or in a column.




Currently, some of the soldiers are happy and some are sad.
You are given the current states of all soldiers in a vector <string> state.
For each i and j, state[i][j] is 'H' if soldier in row i, column j is happy, or 'S' if that soldier is sad.
(All indices are 0-based.)




The King knows that a happy army is a strong army, therefore he wants all his soldiers to be happy.
The soldiers can talk to other soldiers.
Whenever soldier X talks to soldier Y, soldier Y changes his state to the state of soldier X.
For example, if X is currently sad, Y becomes sad as well.
The state of soldier X does not change when X talks to Y.




You can now give some soldiers orders to talk to other soldiers.
There are three types of valid orders:

Choose a single soldier and call him X. Choose a single neighbor of X and call him Y. X will talk to Y.
Choose any contiguous group of soldiers in one of the rows. Each of these soldiers will talk to their neighbor in the other row.
Choose any column A. Choose any column B adjacent to column A. Each soldier in column A will talk to their neighbor in column B.





You are given the vector <string> state.
Return the smallest non-negative integer X such that there is a sequence of X valid orders such that after the orders are executed, one after another, all the soldiers will be happy.
If there is no such sequence of orders, return -1 instead.


DEFINITION
Class:TheKingsArmyDiv1
Method:getNumber
Parameters:vector <string>
Returns:int
Method signature:int getNumber(vector <string> state)


CONSTRAINTS
-N will be between 1 and 200, inclusive.
-state will contain exactly 2 elements.
-Each element of state will contain exactly N characters.
-Each element of state will consist of characters 'H' and 'S'.


EXAMPLES

0)
{"HSH", 
 "SHS"}

Returns: 2

Here is one optimal solution:
First, give an order of the first type, choosing the soldier in row 1, column 1 (0-based indices) as X and the soldier in row 0, column 1 as Y.
Next, give an order of the second type, choosing the entire row 0.

1)
{"HH", 
 "HH"}

Returns: 0

All soldiers are already happy, hence the answer is 0.

2)
{"HHHHH", 
 "HSHSH"}

Returns: 1

One optimal solution is to give an order of the second type, choosing soldiers in columns 1 through 3 in row 0.

3)
{"S", 
 "S"}

Returns: -1

It is impossible to achieve the goal in this case.

4)
{"HSHHSHSHSHHHSHSHSH", 
 "SSSSHSSHSHSHHSSSSH"}

Returns: 8



5)
{"HS",
 "HS"}

Returns: 1



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
		cout << "Testing TheKingsArmyDiv1 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1420120989;
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
		TheKingsArmyDiv1 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string state[] = {"HSH", 
				                  "SHS"};
				_expected = 2;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 1:
			{
				string state[] = {"HH", 
				                  "HH"};
				_expected = 0;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 2:
			{
				string state[] = {"HHHHH", 
				                  "HSHSH"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 3:
			{
				string state[] = {"S", 
				                  "S"};
				_expected = -1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 4:
			{
				string state[] = {"HSHHSHSHSHHHSHSHSH", 
				                  "SSSSHSSHSHSHHSSSSH"};
				_expected = 8;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			case 5:
			{
				string state[] = {"HS",
				                  "HS"};
				_expected = 1;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}
			/*case 6:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string state[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <string>(state, state+sizeof(state)/sizeof(string))); break;
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
