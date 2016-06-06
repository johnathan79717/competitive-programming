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
#define MS0(x) memset(x,0,sizeof(x))
#define V(T) vector<T >

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "MultiplicationTable3.cpp"
#include <string>
#include <vector>
int ans[22][22];
class MultiplicationTable3 {
public:
    vector <int> construct(int x) {
        memset(ans, -1, sizeof(ans));
        int N = solve(x);
        VI ret(N*N);
        REP(i, N) {
            REP(j, N) {
                ret[i*N+j] = ans[i][j];
            }
        }
        //cout << N << endl;
        //int cnt = 0;
        //REP(mask, 1<<N) {
            //if (mask == 0) continue;
            //bool fail =false;
            //REP(i, N) {
                //if ((mask >> i) & 1) {
                    //REP(j, N) {
                        //if ((mask >> j) & 1) {
                            //if ((mask >> ans[i][j]) % 2 == 0) {
                                //fail = true;
                            //}
                        //}
                    //}
                //}
            //}
            //if (!fail) {
                //cnt++;
                //if (x < 100) {
                    //printf("good: %d\n", mask);
                //}
            //}
        //}
        //printf("x = %d\n", x);
        //printf("N = %d\n", N);
        //printf("cnt = %d\n", cnt);

        return ret;
    }
    int solve(int x) {
        if (x == 1) {
            ans[0][0] = 0;
            return 1;
        }
        if (x == 2) {
            REP(i, 2) REP(j, 2) ans[i][j] = 0;
            return 2;
        }
        if (x % 2) {
            int N = solve(x / 2);
            REP(i, N) {
                ans[i][N] = ans[N][i] = N;
            }
            ans[N][N] = N;
            return N+1;
        }
        int N = solve(x / 2 - 1);
        REP(i, N) {
            ans[i][N] = ans[N][i] = N;
        }
        ans[N][N] = N;
        N++;
        REP(i, N) {
            ans[N][i] = ans[i][N] = (i+1) % N;
        }
        ans[N][N] = 0;
        return N+1;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Fox Ciel is creating a new binary operation.



The operation will be denoted $ and it will be defined on the finite set S = {0, 1, 2, ..., n-1}. I.e., for each ordered pair (i, j) of elements of S the operation (i $ j) will return some element of S.



For example, we can have S = {0, 1}, and we can define that (0 $ 0) = 0, (0 $ 1) = 1, (1 $ 0) = 0, and (1 $ 1) = 0.



Note that Ciel's operation is not necessarily symmetric. In other words, it is possible that for some i and j the operations (i $ j) and (j $ i) return two different values.



A subset T of S is called good if it has the following property: for any two elements i and j in T, (i $ j) is also in T.



You are given an int x.
Construct a binary operation $ with the following properties:

The number n (i.e., the size of the set S) must be between 1 and 20, inclusive.
The number of good subsets of the set S must be exactly x.


Return a vector <int> containing the "multiplication table" of your operation $.
More precisely, the return value should consist of n*n elements.
For each i and j from the set S, element (i*n+j) of the return value should be the value (i $ j).



If there are multiple solutions, you may return any of them.
You may assume that there is always at least one valid solution.

DEFINITION
Class:MultiplicationTable3
Method:construct
Parameters:int
Returns:vector <int>
Method signature:vector <int> construct(int x)


CONSTRAINTS
-x will be between 1 and 1,000, inclusive.


EXAMPLES

0)
2

Returns: {1, 1, 1, 1 }

We have chosen n = 2.
Regardless of the inputs, our binary operation $ always returns 1.
For this operation we have exactly x = 2 good subsets of S: the subset {1} and the subset {0,1}.

1)
3

Returns: {0, 1, 0, 1 }

The length of the return value is 4, hence it describes an operation with n = 2.
This particular return value describes the following operation:

0 $ 0 = 0
0 $ 1 = 1
1 $ 0 = 0
1 $ 1 = 1

This operation has exactly 3 good subsets: {0}, {1}, and {0,1}.

2)
6

Returns: {0, 1, 1, 0, 1, 2, 0, 1, 2 }



3)
31

Returns: {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 }

All non-empty subsets of S are good.

4)
1

Returns: {0 }



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
		cout << "Testing MultiplicationTable3 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461428594;
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
		MultiplicationTable3 _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 2;
				int __expected[] = {1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 1:
			{
				int x = 3;
				int __expected[] = {0, 1, 0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 2:
			{
				int x = 6;
				int __expected[] = {0, 1, 1, 0, 1, 2, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 3:
			{
				int x = 31;
				int __expected[] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 4:
			{
				int x = 1;
				int __expected[] = {0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 5:
			{
				int x = 1000;
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			case 6:
			{
				int x = 500;
				int __expected[] = {};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
			}
			/*case 7:
			{
				int x = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(x); break;
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
