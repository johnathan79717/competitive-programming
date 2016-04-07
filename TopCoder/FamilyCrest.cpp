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
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define SZ size()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct FamilyCrest {
  string canBeInfinite(vector <int> A, vector <int> B, vector <int> C, vector <int> D) {

  }
};

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
		cout << "Testing FamilyCrest (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1389712931;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FamilyCrest _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {0};
				int B[] = {0};
				int C[] = {0};
				int D[] = {1};
				_expected = "Infinite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {0,1,1,0};
				int B[] = {0,0,1,1};
				int C[] = {1,1,0,0};
				int D[] = {0,1,1,0};
				_expected = "Finite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {0,1,2,3};
				int B[] = {0,3,0,3};
				int C[] = {1,2,3,4};
				int D[] = {3,0,3,0};
				_expected = "Infinite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {0,1,2,3,-1,-3,-1};
				int B[] = {0,3,0,3,3,2,1};
				int C[] = {1,2,3,4,-3,-1,-3};
				int D[] = {3,0,3,0,2,1,0};
				_expected = "Finite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {0,2,4,6,-1,-2,-1};
				int B[] = {0,1,0,1,3,2,1};
				int C[] = {2,4,6,8,-2,-1,-2};
				int D[] = {1,0,1,0,2,1,0};
				_expected = "Infinite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 5:
			{
				int A[] = {0,0,0,2,3,3,4,5,6,7,9,9,9,9};
				int B[] = {0,2,1,0,0,2,0,0,2,0,0,2,1,0};
				int C[] = {0,1,1,2,3,4,4,5,8,7,9,10,10,10};
				int D[] = {2,2,1,2,2,0,2,2,2,2,2,2,1,0};
				_expected = "Finite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 6:
			{
				int A[] = {-6,-3,3,-6,-3,3};
				int B[] = {1,2,-2,-1,-2,2};
				int C[] = {-3,3,6,-3,3,6};
				int D[] = {2,-2,-1,-2,2,1};
				_expected = "Finite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			case 7:
			{
				int A[] = {-1,-2,0,1};
				int B[] = {0,0,0,0};
				int C[] = {1,0,2,-1};
				int D[] = {0,0,0,0};
				_expected = "Infinite";
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}
			/*case 8:
			{
				int A[] = ;
				int B[] = ;
				int C[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 9:
			{
				int A[] = ;
				int B[] = ;
				int C[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
			}*/
			/*case 10:
			{
				int A[] = ;
				int B[] = ;
				int C[] = ;
				int D[] = ;
				_expected = ;
				_received = _obj.canBeInfinite(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(C, C+sizeof(C)/sizeof(int)), vector <int>(D, D+sizeof(D)/sizeof(int))); break;
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
