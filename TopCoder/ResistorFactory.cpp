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

void cmd(VI &ans, int a, int b, int op) {
    ans.PB(a);
    ans.PB(b);
    ans.PB(op);
}

void check(const VI& ans, long long original) {
    V(double) p = { 1000000000 };
    int N = ans.size();
    assert(N % 3 == 0);
    for (int i = 0; i < N; i += 3) {
	double a = p[ans[i]], b = p[ans[i+1]], op = ans[i+2];
	cout << a << ' ' << b << ' ' << op << endl;
	if (op == 0) {
	    p.push_back(a + b);
	} else {
	    p.push_back(a * b / (a + b));
	}
	cout << p.back() << endl;
    }
    assert(p.back() == original);
}

#line 40 "ResistorFactory.cpp"
#include <string>
#include <vector>
class ResistorFactory {
public:
    vector <int> construct(long long nanoOhms) {
	//long long original = nanoOhms;
	long long unit = 1e9;
	VI ans;
	int k = 0;
	while (unit > 1) {
	    cmd(ans, k, k, 1); // k+1 => 1/2
	    cmd(ans, k+1, k+1, 1); // k+2 => 1/4
	    cmd(ans, k+2, k+2, 1); // k+3 => 1/8
	    cmd(ans, k+3, k+1, 1); // k+4 => 1/10
	    k += 4;
	    unit /= 10;
	}
	int i = k;
	while (unit * 2 <= nanoOhms) {
	    cmd(ans, i, i, 0);
	    i++;
	    unit *= 2;
	}
	int previous = i--;
	nanoOhms -= unit;
	unit /= 2;
	while(nanoOhms) {
	    if (nanoOhms & unit) {
		nanoOhms -= unit;
		cmd(ans, previous, i, 0);
		previous++;
	    }
	    i--;
	    unit /= 2;
	}

	//check(ans, original);

	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You have just inherited a resistor factory. The factory is fully robotized but the automated production lines lack programming. Currently the only thing they know how to manufacture is "product zero": a 1 Ohm resistor.


After some research you have discovered that you can define new products by combining previously defined products.
As you don't want to risk anything too complicated, you opted to only use the two simplest ways to combine resistors: either in series or in parallel.


Two resistors in series look as follows:


   +----+   +----+
---| R1 |---| R2 |---
   +----+   +----+


If the two components used have resistance R1 and R2, the resistance of the entire product is R = R1 + R2.


Two resistors in parallel look as follows:


      +----+  
   +--| R1 |--+
   |  +----+  |
 --+          +--
   |  +----+  |
   +--| R2 |--+
      +----+  


If the two components used have resistance R1 and R2, the resistance R of the entire product satisfies the equation 1/R = 1/R1 + 1/R2.


You just got insider information that the new "whyPhone" will require an awful number of resistors whose resistance is (nanoOhms * 10-9) Ohms.
Of course, this being real hardware, there is some tolerance, so any resistors whose resistance is reasonably close to the desired value will be OK.
Now only one thing stands between you and profit: you need to program the assembly line to produce such resistors.


Formally, the program is an ordered sequence of zero or more commands.
The commands are numbered 1, 2, 3, and so on.
Command i defines product i.
Each triple has the form (p1,p2,op) where p1 and p2 are the numbers of two already defined products (i.e., p1 and p2 must be between 0 and i-1, inclusive) and op is either 0 (meaning that the products p1 and p2 should be put in series) or 1 (meaning in parallel).


Return a vector <int> that is the concatenation of all commands in your program.
You may return any valid program with at most 1000 commands.
If you return an empty program, the final product is defined to be product zero.
Otherwise, the final product is the product defined by the last command in your program.
Your program will be accepted if the resistance of the final product is close enough to the required resistance.
More precisely, the resistance of your final product (expressed as a real number in Ohms) must have an absolute or a relative error at most 1e-9.


DEFINITION
Class:ResistorFactory
Method:construct
Parameters:long long
Returns:vector <int>
Method signature:vector <int> construct(long long nanoOhms)


CONSTRAINTS
-nanoOhms will be between 1 and 10^18, inclusive.


EXAMPLES

0)
3000000000

Returns: {0, 0, 0, 0, 1, 0 }


We want a resistor whose resistance is exactly 3 Ohms. This is easy: just take three 1 Ohm resistors in series. 


More precisely, we first define that product 1 consists of two products 0 in series, and then we say that product 2 is a product 0 and a product 1 in series.


1)
1200000000

Returns: {0, 0, 0, 1, 0, 0, 1, 2, 1 }

This time we want a resistor with resistance 1.2 Ohms.
Again, this is easy to achieve precisely.
One possibility is to take a 2 Ohm and a 3 Ohm resistor and connect them in parallel.

2)
1428571428

Returns: {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 }

The resistor we want this time should have 1.428571428 Ohms. Instead of producing it precisely, we will produce a resistor with resistance 10/7 Ohms. As 10/7 = 1.4285714285714285714..., we are well within the required tolerance.

3)
12000000001

Returns: {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 }



4)
333333333

Returns: {0, 0, 1, 0, 1, 1 }



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
		cout << "Testing ResistorFactory (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1543527747;
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
		ResistorFactory _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long nanoOhms = 3000000000LL;
				int __expected[] = {0, 0, 0, 0, 1, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}
			case 1:
			{
				long long nanoOhms = 1200000000LL;
				int __expected[] = {0, 0, 0, 1, 0, 0, 1, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}
			case 2:
			{
				long long nanoOhms = 1428571428LL;
				int __expected[] = {0, 0, 0, 0, 1, 0, 1, 2, 0, 3, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}
			case 3:
			{
				long long nanoOhms = 12000000001LL;
				int __expected[] = {0, 0, 0, 0, 1, 0, 2, 2, 0, 3, 3, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}
			case 4:
			{
				long long nanoOhms = 333333333LL;
				int __expected[] = {0, 0, 1, 0, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}
			/*case 5:
			{
				long long nanoOhms = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}*/
			/*case 6:
			{
				long long nanoOhms = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
			}*/
			/*case 7:
			{
				long long nanoOhms = LL;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(nanoOhms); break;
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
