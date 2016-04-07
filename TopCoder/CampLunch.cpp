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

#define PZ(x) PI((x).i);

template<class Short, class Long>
struct ZZ {
    static Short MOD;
    Short i;
    ZZ():i(0) {}
    ZZ(Short i): i(i >= 0 ? i : i + MOD) {}
    ZZ(Long i): i(i % MOD) {}
    void operator +=(const ZZ& z) { i += z.i; if(i >= MOD) i -= MOD; }
    void operator -=(const ZZ& z) { i -= z.i; if(i < 0) i += MOD; }
    void operator *=(const ZZ& z) { i = (Long) i * z.i % MOD; }
    void operator /=(const ZZ& z) { (*this) *= z.inverse(); }
    ZZ operator +(const ZZ& z) const { ZZ ret(i); ret += z; return ret; }
    ZZ operator -(const ZZ& z) const { ZZ ret(i); ret -= z; return ret; }
    ZZ operator *(const ZZ& z) const { ZZ ret(i); ret *= z; return ret; }
    ZZ operator /(const ZZ& z) const { return (*this) * z.inverse(); }
    // ZZ operator -() const { return ZZ(-i); }
};

typedef ZZ<int, LL> Z;

template<>
int Z::MOD = 1000000007;

Z dp[2][70000];

class CampLunch {
	public:
	int count(int N, int M, vector <string> a) {
		int prev = 0, next = 1;
		dp[next][(1 << M) - 1] = 1;
		REP(i, N) {
			REP(j, M) {
				swap(prev, next);
				MS0(dp[next]);
				int pos;
				REP(k, M) {
					if (a[i][k] - 'A' == j) {
						pos = k;
						break;
					}
				}
				int nbr1 = (pos > 0 ? a[i][pos-1] - 'A' : -1);
				int nbr2 = (pos < M-1 ? a[i][pos+1] - 'A' : -1);
				REP(mask, 1 << M) {
					if (dp[prev][mask].i == 0) continue;
					if (nbr1 >= 0 && nbr1 < j && !((mask >> nbr1) & 1))
						dp[next][mask | (1 << nbr1) | (1 << j)] += dp[prev][mask];
					if (nbr2 >= 0 && nbr2 < j && !((mask >> nbr2) & 1))
						dp[next][mask | (1 << nbr2) | (1 << j)] += dp[prev][mask];
					if (!((mask >> j) & 1))
						dp[next][mask | (1 << j)] += dp[prev][mask];
					dp[next][mask & ~(1 << j)] += dp[prev][mask];
				}
			}
		}
		Z ans = 0;
		REP(mask, 1 << M) {
			ans += dp[next][mask];
		}
		return ans.i;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is a small IOI training camp for students.
The camp is N days long.
The days are numbered 0 through N-1.
There are M students taking part in the camp.
The students are labeled using the first M uppercase English letters.
(For example, if there are M=3 students, we will call them 'A', 'B', and 'C'.)



During lunch, the students sit in a single row along one long table.
There are M different positions at the table.
The positions are numbered 0 through M-1.
You are given a vector <string> a with the seating arrangements:
during lunch on day i, the person sitting on position j will be a[i][j].



The camp must provide lunch for all people on all days.
There are three different lunch plans:

A double lunch for two people on the same day. The two people have to sit next to each other on that day.
A double lunch for one person in two consecutive days.
A single lunch for one person.




Two methods of providing lunch are considered different if for some d and P the lunch plans for person P on day d are different.
Let X be the number of different ways in which the camp can provide lunch to the participants.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:CampLunch
Method:count
Parameters:int, int, vector <string>
Returns:int
Method signature:int count(int N, int M, vector <string> a)


CONSTRAINTS
-N will be between 1 and 16, inclusive.
-M will be between 1 and 16, inclusive.
-The number of elements in a will be exactly N.
-The length of elements in a will be exactly M.
-Each element of a will be a permutation of the first M uppercase English letters.


EXAMPLES

0)
2
2
{"AB","AB"}

Returns: 7


There are two days and two students.
In this setting there are 7 different ways to provide lunch:

Both students use plan 3 each day.
Student A uses a single plan 2 for both days, student B uses plan 3 twice.
Student A uses plan 3 twice, student B uses a single plan 2 for both days.
Each student uses a single plan 2.
On day 0 both students are served by a single plan 1. On day 1 each student uses their own plan 3.
On day 0 each student uses their own plan 3. On day 1 both students are served by a single plan 1.
Each day both students are served by a single plan 1.



1)
2
3
{"ABC","ABC"}

Returns: 22



2)
2
3
{"ABC","BAC"}

Returns: 21

Note that students A and C cannot use the same plan 1 on day 0, as they are not sitting next to each other.
However, they are able to use the same plan 1 on day 1 when there is a different seating arrangement.

3)
1
1
{"A"}

Returns: 1



4)
1
10
{"ABDEFHIGJC"}

Returns: 89



5)
16
16
{"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"}

Returns: 950052677



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
		cout << "Testing CampLunch (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1431478809;
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
		CampLunch _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int M = 2;
				string a[] = {"AB","AB"};
				_expected = 7;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 1:
			{
				int N = 2;
				int M = 3;
				string a[] = {"ABC","ABC"};
				_expected = 22;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 2:
			{
				int N = 2;
				int M = 3;
				string a[] = {"ABC","BAC"};
				_expected = 21;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 3:
			{
				int N = 1;
				int M = 1;
				string a[] = {"A"};
				_expected = 1;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 4:
			{
				int N = 1;
				int M = 10;
				string a[] = {"ABDEFHIGJC"};
				_expected = 89;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			case 5:
			{
				int N = 16;
				int M = 16;
				string a[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"};
				_expected = 950052677;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}
			/*case 6:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int M = ;
				string a[] = ;
				_expected = ;
				_received = _obj.count(N, M, vector <string>(a, a+sizeof(a)/sizeof(string))); break;
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
