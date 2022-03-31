#line 2 "MinMaxGame.cpp"
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
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
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

class MinMaxGame {
public:
    int lastNumber(vector <int> A) {
	if (A.size() % 2) {
	    return max(A[0], A.back());
	}
	return min(A[0], A.back());
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Nam and Quang are playing a game with a sequence of integers A. In the game they take alternating turns. Nam plays first.



In Nam's turn he has to choose two consecutive elements of A. Once he does so, he has to erase the larger of these two elements. (If they are equal, he erases one of them, it does not matter which one.)


Quang's turn also begins with him choosing two consecutive elements of A. However, Quang always erases the smaller of those two elements.



The game terminates when only one element of A remains. Its value V is the result of the game. Nam's objective is to maximize V, while Quang's objective is to minimize V.



Assume that both players play optimally. Determine and return the value of V.


DEFINITION
Class:MinMaxGame
Method:lastNumber
Parameters:vector <int>
Returns:int
Method signature:int lastNumber(vector <int> A)


NOTES
-Whenever an element gets erased from A, its neighbors become adjacent to each other. 


CONSTRAINTS
-A will have between 2 and 100 elements, inclusive.
-Each element of A will be between 1 and 100, inclusive.


EXAMPLES

0)
{3, 2, 1}

Returns: 3

There are 2 possible scenarios:

- Scenerio 1: In the first turn, Nam chooses the first two elements of A, then erases the larger one. The sequence A now becomes {2, 1}. In the second turn, Quang erases the smaller one amongst the two elements remaining in A. The sequence A now becomes {2}. The game terminates, V = 2.

- Scenerio 2: In the first turn, Nam chooses the last two elements of A, then erases the larger one. The sequence A now becomes {3, 1}. In the second turn, Quang erases the smaller one amongst the two elements remaining in A. The sequence A now becomes {3}. The game terminates, V = 3.

Because Nam's objective is to maximize V, he will choose scenerio 2.

1)
{2, 5, 3, 7}

Returns: 2



2)
{4, 5, 1, 6, 5}

Returns: 5



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
		cout << "Testing MinMaxGame (400.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613236742;
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
		MinMaxGame _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {3, 2, 1};
				_expected = 3;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {2, 5, 3, 7};
				_expected = 2;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {4, 5, 1, 6, 5};
				_expected = 5;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 3:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.lastNumber(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
