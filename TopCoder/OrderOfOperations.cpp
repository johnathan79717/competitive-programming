#include <cassert>
#include <list>
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

class OrderOfOperations {
public:
    int minTime(vector <string> s) {

    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Cat Noku has just finished writing his first computer program.
Noku's computer has m memory cells.
The cells have addresses 0 through m-1.
Noku's program consists of n instructions.
The instructions have mutually independent effects and therefore they may be executed in any order.
The instructions must be executed sequentially (i.e., one after another) and each instruction must be executed exactly once.



You are given a description of the n instructions as a vector <string> with n elements.
Each instruction is a string of m characters.
For each i, character i of an instruction is '1' if this instruction accesses memory cell i, or '0' if it does not.



Noku's computer uses caching, which influences the time needed to execute an instruction.
More precisely, executing an instruction takes k^2 units of time, where k is the number of new memory cells this instruction accesses.
(I.e., k is the number of memory cells that are accessed by this instruction but have not been accessed by any previously executed instruction.
Note that k may be zero, in which case the current instruction is indeed executed in 0 units of time.)



Noku's instructions can be executed in many different orders.
Clearly, different orders may lead to a different total time of execution.
Find and return the shortest amount of time in which it is possible to execute all instructions.


DEFINITION
Class:OrderOfOperations
Method:minTime
Parameters:vector <string>
Returns:int
Method signature:int minTime(vector <string> s)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-m will be between 1 and 20, inclusive.
-s will have exactly n elements.
-Each element of s will have exactly m characters.
-Each character of s[i] will be either '0' or '1' for all valid i.


EXAMPLES

0)
{
 "111",
 "001",
 "010"
}

Returns: 3

Cat Noku has 3 instructions.
The first instruction ("111") accesses all three memory cells.
The second instruction ("001") accesses only memory cell 2.
The third instruction ("010") accesses only memory cell 1.
If Noku executes these three instructions in the given order, it will take 3^2 + 0^2 + 0^2 = 9 units of time.
However, if he executes them in the order "second, third, first", it will take only 1^2 + 1^2 + 1^2 = 3 units of time.
This is one optimal solution.
Another optimal solution is to execute the instructions in the order "third, second, first".


1)
{
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}

Returns: 9



2)
{
  "11111111111111111111"
}

Returns: 400

A single instruction that accesses all 20 memory cells.

3)
{
  "1000",
  "1100",
  "1110"
}

Returns: 3



4)
{
  "111",
  "111",
  "110",
  "100"
}

Returns: 3



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
		cout << "Testing OrderOfOperations (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1441983637;
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
		OrderOfOperations _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s[] = {
				              "111",
				              "001",
				              "010"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 1:
			{
				string s[] = {
				              "11101",
				              "00111",
				              "10101",
				              "00000",
				              "11000"
				             };
				_expected = 9;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 2:
			{
				string s[] = {
				               "11111111111111111111"
				             };
				_expected = 400;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 3:
			{
				string s[] = {
				               "1000",
				               "1100",
				               "1110"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			case 4:
			{
				string s[] = {
				               "111",
				               "111",
				               "110",
				               "100"
				             };
				_expected = 3;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}
			/*case 5:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string s[] = ;
				_expected = ;
				_received = _obj.minTime(vector <string>(s, s+sizeof(s)/sizeof(string))); break;
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
