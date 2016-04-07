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
#define FOR(i, c) for(auto &i: c)
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

struct TaroCheckers {
  int getNumber(vector <int> left, vector <int> right, int M) {

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
		cout << "Testing TaroCheckers (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395415744;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TaroCheckers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int left[] = {1, 2};
				int right[] = {2, 1};
				int M = 4;
				_expected = 1;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			case 1:
			{
				int left[] = {1, 4, 2};
				int right[] = {2, 3, 1};
				int M = 7;
				_expected = 6;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			case 2:
			{
				int left[] = {4, 7, 4};
				int right[] = {7, 4, 7};
				int M = 11;
				_expected = 5760;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			case 3:
			{
				int left[] = {10, 25, 100, 74};
				int right[] = {100, 47, 27, 100};
				int M = 200;
				_expected = 796178974;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			case 4:
			{
				int left[] = {21, 99, 87, 12, 138, 16, 78, 36, 98, 40, 57, 10, 61, 100, 8, 110, 96, 9, 69, 110, 14, 71};
				int right[] = {83, 8, 25, 169, 1, 89, 109, 89, 19, 112, 39, 112, 87, 66, 116, 16, 41, 97, 52, 70, 111, 23};
				int M = 190;
				_expected = 235017573;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			case 5:
			{
				int left[] = {3, 37, 26, 50, 8, 3, 38, 15, 58, 47, 35, 8, 27, 22, 5};
				int right[] = {19, 26, 62, 15, 84, 13, 6, 46, 22, 53, 23, 8, 29, 55, 6};
				int M = 102;
				_expected = 528024858;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}
			/*case 6:
			{
				int left[] = ;
				int right[] = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}*/
			/*case 7:
			{
				int left[] = ;
				int right[] = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
			}*/
			/*case 8:
			{
				int left[] = ;
				int right[] = ;
				int M = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(left, left+sizeof(left)/sizeof(int)), vector <int>(right, right+sizeof(right)/sizeof(int)), M); break;
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
