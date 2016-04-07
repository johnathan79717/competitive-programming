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

const int MAX = 4005;
template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short i): i(i >= 0 ? i : i + MOD) {}
    ZZ(Long i): i(i % MOD) {}
    void operator *=(const ZZ& z) { i = (Long) i * z.i % MOD; }
    ZZ operator *(const ZZ& z) const { ZZ ret(i); ret *= z; return ret; }
    ZZ pow(long long b) {
        ZZ x=Short(1),y=*this;
        while(b > 0){
            if(b%2 == 1)
                x *= y;
            y *= y; // squaring the base
            b /= 2;
        }
        return x;
    }
};

typedef ZZ<int, LL> Z;
template<> int Z::MOD = 1000000007;

class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		Z::MOD = A + B;
		Z C = Z(2).pow(K) * min(A, B);
		// cout << C.i << endl;
		return C.i <= (A+B)/2 ? C.i : A + B - C.i;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Limak is a little bear who loves to play.
Today he is playing by moving some stones between two piles of stones.
Initially, one of the piles has A and the other has B stones in it.

Limak has decided to perform a sequence of K operations.
In each operation he will double the size of the currently smaller pile.
Formally, if the current pile sizes are labeled X and Y in such a way that X <= Y, he will move X stones from the second pile to the first one.
After this move the new pile sizes will be X+X and Y-X.

You are given the ints A, B, and K.
Determine the pile sizes after Limak finishes all his operations.
Return the size of the smaller of those piles.

Formally, suppose that the final pile sizes are labeled P and Q in such a way that P <= Q.
Return P.

DEFINITION
Class:BearPlays
Method:pileSize
Parameters:int, int, int
Returns:int
Method signature:int pileSize(int A, int B, int K)


NOTES
-Pay attention to the unusual time limit.


CONSTRAINTS
-A and B will be between 1 and 1,000,000,000, inclusive. 
-K will be between 1 and 2,000,000,000, inclusive.


EXAMPLES

0)
4
7
2

Returns: 5

The process will look as follows:

Initially, the pile sizes are 4 and 7.
First operation: Limak doubles the pile of size 4 by moving 4 stones from the other pile to this pile. The new pile sizes are 8 and 3.
Second operation: Limak doubles the pile of size 3. The final pile sizes are 5 and 6.
As 5 <= 6, the correct return value is 5.


1)
5
5
3

Returns: 0

The initial pile sizes are 5 and 5.
In the first operation Limak will double one of them, so after the operation the new pile sizes will be 10 and 0.
The second and third operation do nothing: in each of them Limak doubles the size of an empty pile.

As 0 ≤ 10, the correct return value is 0.

2)
2
6
1

Returns: 4

After the only operation the pile sizes will be 4 and 4, hence the correct return value is 4.

3)
2
8
2000000000

Returns: 2



4)
900000000
350000000
3

Returns: 300000000



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
		cout << "Testing BearPlays (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1438444810;
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
		BearPlays _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A = 4;
				int B = 7;
				int K = 2;
				_expected = 5;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 1:
			{
				int A = 5;
				int B = 5;
				int K = 3;
				_expected = 0;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 2:
			{
				int A = 2;
				int B = 6;
				int K = 1;
				_expected = 4;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 3:
			{
				int A = 2;
				int B = 8;
				int K = 2000000000;
				_expected = 2;
				_received = _obj.pileSize(A, B, K); break;
			}
			case 4:
			{
				int A = 900000000;
				int B = 350000000;
				int K = 3;
				_expected = 300000000;
				_received = _obj.pileSize(A, B, K); break;
			}
			/*case 5:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
			}*/
			/*case 6:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
			}*/
			/*case 7:
			{
				int A = ;
				int B = ;
				int K = ;
				_expected = ;
				_received = _obj.pileSize(A, B, K); break;
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
