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

int a[6001];

class ApplesAndOrangesEasy {
	public:
	int maximumApples(int N, int K, vector <int> info) {
		int ans = info.size();
		for(int i: info) {
			a[i-1+N] = 1;
		}
		REP1(i, N, 2*N-1) {
			if (a[i]) continue;
			int cnt = 0;
			REP1(j, i - K + 1, i) {
				cnt += a[j];
			}
			bool fail = false;
			REP1(j, i - K + 1, i) {
				if (cnt == K / 2) {
					fail = true;
				}
				cnt = cnt - a[j] + a[j+K];
			}
			if (!fail) {
				ans++;
				a[i] = 1;
			}
		}
		return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Garth likes apples and oranges. Recently he bought N fruits, where each fruit was either an apple or an orange. Then he ate all N fruits in some order. You are given an int K. Garth observed that at every point in time, if he made a list of the last K fruits he ate, there were at most K/2 (rounded down) apples in this list.


For each valid i, you know that the info[i]-th fruit Garth ate was an apple. (Fruits Garth ate are numbered starting from 1. For example, info[i]=1 means that the very first fruit Garth ate was an apple.)


Please find and return the maximum number of apples Garth could have eaten.

DEFINITION
Class:ApplesAndOrangesEasy
Method:maximumApples
Parameters:int, int, vector <int>
Returns:int
Method signature:int maximumApples(int N, int K, vector <int> info)


NOTES
-If Garth makes his list at a point in time when he ate fewer than K fruits, his list will have fewer than K fruits but the requirement will still be the same: there have to be at most K/2 apples in the list.


CONSTRAINTS
-N will be between 2 and 2,000, inclusive.
-K will be between 2 and N, inclusive.
-info will contain between 0 and N elements, inclusive.
-Each element of info will be between 1 and N, inclusive.
-The elements of info will be distinct.
-The elements of info will be consistent with Garth's observation.


EXAMPLES

0)
3
2
{}

Returns: 2

Garth ate N=3 fruites. The requirement is that any K=2 consecutive fruits may contain at most K/2 = 1 apple. As info is empty, you have no additional information about the fruits Garth ate.


Garth might have eaten an apple, then an orange, then an apple. This satisfies the conditions:

After eating the 1st fruit, the list is [apple].
After eating the 2nd fruit, the list is [apple, orange].
After eating the 3rd fruit, the list is [orange, apple].

Each list contains at most 1 apple.

1)
10
3
{3, 8}

Returns: 2

All fruits, except for the 3rd and the 8th, must have been oranges.

2)
9
4
{1, 4}

Returns: 5



3)
9
4
{2, 4}

Returns: 4



4)
23
7
{3, 2, 9, 1, 15, 23, 20, 19}

Returns: 10



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
		cout << "Testing ApplesAndOrangesEasy (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431481406;
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
		ApplesAndOrangesEasy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 3;
				int K = 2;
				int info[] = {};
				_expected = 2;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 10;
				int K = 3;
				int info[] = {3, 8};
				_expected = 2;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 9;
				int K = 4;
				int info[] = {1, 4};
				_expected = 5;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 9;
				int K = 4;
				int info[] = {2, 4};
				_expected = 4;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 23;
				int K = 7;
				int info[] = {3, 2, 9, 1, 15, 23, 20, 19};
				_expected = 10;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}
			/*case 5:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int info[] = ;
				_expected = ;
				_received = _obj.maximumApples(N, K, vector <int>(info, info+sizeof(info)/sizeof(int))); break;
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
