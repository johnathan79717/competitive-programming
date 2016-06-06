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

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "LCMGCD.cpp"
#include <string>
#include <vector>
class LCMGCD {
public:
    int get(int n, int p) {
        int ans = 0;
        while (n % p == 0) {
            ans++;
            n /= p;
        }
        return ans;
    }
    string isPossible(vector <int> x, int t) {
    string s = "Possible";
        int N = x.size();
        VI a(N), b(N);
        int aa = get(t, 2), bb = get(t, 3);
        REP(i, N) {
            a[i] = get(x[i], 2);
            b[i] = get(x[i], 3);
        }
        REP(i, N) {
            if (a[i] == aa && b[i] == bb) {
                if (N == 1) return s;
                bool gb = false, la = false, lb = false, ga = false;
                REP(j, N) {
                    if (i == j) continue;
                    if (a[j] >= a[i]) {
                        ga = true;
                    }
                    if (a[j] <= a[i]) {
                        la = true;
                    }
                    if (b[j] >= b[i]) {
                        gb = true;
                    }
                    if (b[j] <= b[i]) {
                        lb = true;
                    }
                }
                if (ga && gb) {
                    return s;
                }
                if (lb && la) {
                    return s;
                }
            }
        }
        REP(i, N) {
            REP(j, N) {
                if (i == j) continue;
                if (a[i] == aa && b[j] == bb) {
                    if (a[j] >= a[i] && b[i] >= b[j]) return s;
                    if (a[j] <= a[i] && b[i] <= b[j]) return s;
                    if (a[i] <= a[j] && b[i] <= b[j]) {
                        REP(k, N) {
                            if (k == i && k == j) continue;
                            if (a[k] <= a[i] && b[k] >= b[j]) return s;
                        }
                    }
                    if (a[i] >= a[j] && b[i] >= b[j]) {
                        REP(k, N) {
                            if (k == i && k == j) continue;
                            if (a[k] >= a[i] && b[k] <= b[j]) {
                                return s;
                            }
                        }
                    }
                }
            }
        }
        return "Impossible";
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are given the vector <int> x: a list containing n integers.
Each element of x is a positive integer of the form 2^a * 3^b, where a and b are some nonnegative integers.
The elements of x are not necessarily distinct.



You are going to perform n-1 operations.
Each operation will consist of the following steps:

Choose two distinct indices into your list. Let X and Y be the numbers at those indices. Remove both of them from the list. (Note that X and Y are allowed to have the same value.)
Compute one of two possible values: either the greatest common divisor (gcd) of X and Y, or the least common multiple (lcm) of X and Y.
Append the computed value to your list.

Obviously, after n-1 operations you will be left with a single integer.



In addition to x you are given the int t.
You would like to know whether it is possible to perform the sequence of operations on x in such a way that the final integer will be t.
If it is possible, return "Possible", otherwise return "Impossible".


DEFINITION
Class:LCMGCD
Method:isPossible
Parameters:vector <int>, int
Returns:string
Method signature:string isPossible(vector <int> x, int t)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element of x will be between 1 and 10^9, inclusive.
-t will be between 1 and 10^9, inclusive.
-t and each element of x will be of the form 2^i*3^j for some nonnegative i,j.


EXAMPLES

0)
{2,3}
6

Returns: "Possible"

We can take the lcm to reach the goal.

1)
{4,9}
6

Returns: "Impossible"

We have lcm(4,9) = 36 and gcd(4,9) = 1. It's impossible to get 6.

2)
{6,12,24,18,36,72,54,108,216}
36

Returns: "Possible"



3)
{6,27,81,729}
6

Returns: "Impossible"



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
1

Returns: "Possible"



5)
{72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}
72

Returns: "Possible"



6)
{100663296, 544195584, 229582512, 59049}
60466176

Returns: "Possible"

Watch out for integer overflow.
The intermediate results won't always fit into a 32-bit integer variable.

7)
{2,4,8,16,32,64}
256

Returns: "Impossible"



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
		cout << "Testing LCMGCD (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463065933;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 400.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		LCMGCD _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {2,3};
				int t = 6;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 1:
			{
				int x[] = {4,9};
				int t = 6;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 2:
			{
				int x[] = {6,12,24,18,36,72,54,108,216};
				int t = 36;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 3:
			{
				int x[] = {6,27,81,729};
				int t = 6;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 4:
			{
				int x[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
				           1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
				int t = 1;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 5:
			{
				int x[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
				int t = 72;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 6:
			{
				int x[] = {100663296, 544195584, 229582512, 59049};
				int t = 60466176;
				_expected = "Possible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 7:
			{
				int x[] = {2,4,8,16,32,64};
				int t = 256;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			case 8:
			{
				int x[] = {1, 6, 216};
				int t = 24;
				_expected = "Impossible";
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}
			/*case 9:
			{
				int x[] = ;
				int t = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
			}*/
			/*case 10:
			{
				int x[] = ;
				int t = ;
				_expected = ;
				_received = _obj.isPossible(vector <int>(x, x+sizeof(x)/sizeof(int)), t); break;
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
