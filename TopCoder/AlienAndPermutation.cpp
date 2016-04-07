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

struct AlienAndPermutation {
  int getNumber(vector <int> P, int K) {

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
		cout << "Testing AlienAndPermutation (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1390309220;
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
		AlienAndPermutation _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P[] = {1, 2};
				int K = 1;
				_expected = 2;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}
			case 1:
			{
				int P[] = {3, 1, 2};
				int K = 2;
				_expected = 4;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}
			case 2:
			{
				int P[] = {4, 3, 2, 1};
				int K = 2;
				_expected = 13;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}
			case 3:
			{
				int P[] = {1, 7, 2, 3, 6, 4, 5};
				int K = 3;
				_expected = 77;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}
			case 4:
			{
				int P[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
				int K = 12;
				_expected = 379796836;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}
			/*case 5:
			{
				int P[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}*/
			/*case 6:
			{
				int P[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
			}*/
			/*case 7:
			{
				int P[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(P, P+sizeof(P)/sizeof(int)), K); break;
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
