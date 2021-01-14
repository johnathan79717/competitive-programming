#line 2 "RowAcross.cpp"
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <deque>
#include <stack>
#include <functional>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define PB emplace_back
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

class RowAcross {
public:
    vector <string> row(int N, int C) {
	set<PII> here, there;
	vector<string> ans;
	for (int i = 0; i < N; i++) {
	    here.emplace(0, i);
	}
	while (here.size()) {
	    ans.PB("");
	    REP(i, C) {
		if (here.size()) {
		    auto it = here.begin();
		    auto pr = *it;
		    here.erase(it);
		    if (i == 0) {
			pr.F++;
		    }
		    there.insert(pr);
		    ans.back().push_back('A' + pr.S);
		}
	    }
	    if (here.size()) {
		auto it = there.begin();
		auto pr = *it;
		there.erase(it);
		pr.F++;
		here.insert(pr);
		ans.PB(1, 'A' + pr.S);
	    }
	}
	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A group of N people just reached a river they want to cross.
The only means they can use to cross the river is a nearby boat with a single paddle.
The boat can carry at most C people.
Paddling the boat across the river takes one minute (regardless of how many people are in the boat).
Each time the boat goes from one river bank to the other, exactly one person has to paddle.
It is not allowed to change the person who paddles while crossing the river.


Get all people across the river as quickly as possible.


Let the strain on a person be the number of times they paddled across the river.
Among all shortest schedules, pick any one that minimizes the maximum strain.


Return the schedule as a vector <string>.
Use the first N uppercase English letters to represent the people.
For each trip across the river, return a string with the people in the boat, with the person who paddles the boat listed first.


DEFINITION
Class:RowAcross
Method:row
Parameters:int, int
Returns:vector <string>
Method signature:vector <string> row(int N, int C)


CONSTRAINTS
-N will be between 1 and 26, inclusive.
-C will be between 2 and 26, inclusive.


EXAMPLES

0)
13
4

Returns: {"ABCD", "B", "EFGH", "H", "IJKL", "K", "MBKH" }


Four people go to the other side ('A' paddles), then 'B' brings the boat back. The same thing is repeated two more times.


After six minutes, we have nine people at the desired bank of the river and four are still on the original bank.
These four are 'B', 'H', 'K', and 'M'.
Out of them, 'M' is the only person who hasn't paddled yet, so we have them take everyone else to the other side and we are done.


Note that the maximum strain for this solution is 1: nobody had to paddle more than once.


1)
8
6

Returns: {"ACGHEF", "FAC", "DABCF" }

In the returned solution two people ('A' and 'C') make unnecessary trips back and forth, but that does not matter. Three minutes is the optimal time, and the returned solution also clearly minimizes the maximum strain.

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
		cout << "Testing RowAcross (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1601725067;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		RowAcross _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 13;
				int C = 4;
				string __expected[] = {"ABCD", "B", "EFGH", "H", "IJKL", "K", "MBKH" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.row(N, C); break;
			}
			case 1:
			{
				int N = 8;
				int C = 6;
				string __expected[] = {"ACGHEF", "FAC", "DABCF" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.row(N, C); break;
			}
			/*case 2:
			{
				int N = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.row(N, C); break;
			}*/
			/*case 3:
			{
				int N = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.row(N, C); break;
			}*/
			/*case 4:
			{
				int N = ;
				int C = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.row(N, C); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
