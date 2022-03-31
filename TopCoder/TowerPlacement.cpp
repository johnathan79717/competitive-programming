#line 2 "TowerPlacement.cpp"
#include <array>
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

class TowerPlacement {
public:
    int solve(int R, int C, int seed, int X) {
		
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Time limit is 6 seconds.


Absurdistan is a rectangular country that is divided into a grid of R rows by C columns of unit squares.
These have coordinates from (0, 0) to (R-1, C-1).



We are building broadcast towers.
Each broadcast tower occupies one square of the grid.
Additionally, in the future each broadcast tower will have to be anchored.
The anchors for a tower must occupy either both squares that are horizontally adjacent to the tower, or both vertically-adjacent squares.


Each square can only contain at most one object (i.e., either a tower, or the anchor of exactly one tower, or nothing).
Anchors of a tower cannot be placed outside the grid.
This limits how towers on the boundary of Absurdistan can be anchored.



Below is an example of several correctly anchored towers, using 'T' to denote towers and different numbers to denote anchors for different towers. Note that tower with anchors denoted '5' could have also been anchored vertically.


    +----------+
    | 0       4|
    | T1  5T5 T|
    | 0T3T3   4|
    |  12T2    |
    +----------+



You are given a sequence of 50,000 not necessarily distinct squares: (qr[0], qc[0]), ..., (qr[49999], qc[49999]). These are candidates for the places of towers in Absurdistan.


The tower building committee processes these candidates in the given order, using the following algorithm:



    start with an empty set T of towers
    for each i from 0 to 49999:
        let S = (qr[i], qc[i]) be the current candidate square
        if S is already in T:
            ignore candidate number i (do nothing)
        else:
            let T' = T + {S}
            if it is possible to build and correctly anchor all towers in T':
                accept candidate number i and set T = T'
            else:
                reject candidate number i



You are given X.
Return the number of the X-th (1-based index) rejected candidate, or -1 if there is no such candidate.


X is usually small. Please read the exact constraints for X carefully.


--------------------


In order to keep the input small, the sequence of candidate squares is generated pseudorandomly.
Please use the following pseudocode to generate it:



state = seed
for i = 0 to 49999:
    state = (state * 1103515245 + 12345) modulo 2^31
    qr[i] = (state div 1000) mod R
    state = (state * 1103515245 + 12345) modulo 2^31
    qc[i] = (state div 1000) mod C



DEFINITION
Class:TowerPlacement
Method:solve
Parameters:int, int, int, int
Returns:int
Method signature:int solve(int R, int C, int seed, int X)


NOTES
-Candidates that are ignored do not count as rejected candidates.
-It is possible that a rejected square shares coordinates with another, previously rejected square. Each of those still counts as a separate rejection.


CONSTRAINTS
-R will be between 1 and 100,000, inclusive.
-C will be between 1 and 100,000, inclusive.
-seed will be between 0 and 2^31 - 1, inclusive.
-X will be between 1 and 500, inclusive.
-Let N = min(50000, R*C). Then, X*N will not exceed 200,000.


EXAMPLES

0)
1
1
47
5

Returns: 4

The sequence has 50,000 copies of the cell (0, 0). Each of them gets rejected because Absurdistan is too small for the tower's anchors.

1)
3
3
47
4

Returns: 6


The sequence of candidates begins as follows: (1,1) (2,0) (0,2) (0,0) (1,1) (1,0) (2,1) (2,0) (1,1) (0,1) (1,0) (0,1) ...


The following happens:


Candidate 0 is accepted. We have T = { (1,1) }.
Candidates 1, 2, and 3 are rejected. We cannot ever anchor a tower built in a corner of Absurdistan.
Candidate 4 is ignored, we already have it in T.
Candidate 5 is accepted. It is possible to build towers at (1,1) and (1,0) and anchor both of them vertically. Now T = { (1,1), (1,0) }.
Candidate 6 is rejected: if we build towers at (1,1), (1,0), and (2,1) it is not possible to anchor all three while keeping everything disjoint.

Candidate 6 was the fourth rejected candidate, so we return 6.

2)
10000
14700
12345
1

Returns: -1


Plenty of room for all the towers and their anchors, nothing gets rejected. (A few candidates do get ignored.)


The first few candidates: (6932,7783) (9466,8783) (9335,7850) (3799,671) (1188,9750) (2930,3413) (9546,171) (5770,4508) (9212,12084) 


3)
10
12
123456789
3

Returns: 19


The first 20 candidates: (4,2) (5,2) (7,2) (9,5) (0,4) (9,7) (0,8) (6,6) (1,4) (6,3) (6,7) (3,6) (7,10) (2,0) (9,2) (0,6) (2,0) (5,10) (3,6) (7,7)


Candidates 0-4 get accepted.
Candidate 5 gets rejected. Towers at (9,5) and (9,7) both need to be anchored horizontally, as they are in the last row. However, they both want to use (9,6) for one of their anchors, which isn't allowed.
Candidates 6-14 all get accepted.
Candidate 15, the square (0,6), gets rejected. The issue is similar to the previous one.
Candidate 16 gets ignored as a duplicate of an already accepted square.
Candidate 17 gets accepted.
Candidate 18 gets ignored.
Candidate 19 gets rejected.


The situation when processing candidate 19 is shown below: candidate 19 is '#', previously accepted candidates are '*' and empty squares are '.'.


....*...*...
....*.......
*...........
......*.....
..*.........
..*.......*.
...*..**....
..*....#..*.
............
..*..*......



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
		cout << "Testing TowerPlacement (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1625744903;
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
		TowerPlacement _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 1;
				int C = 1;
				int seed = 47;
				int X = 5;
				_expected = 4;
				_received = _obj.solve(R, C, seed, X); break;
			}
			case 1:
			{
				int R = 3;
				int C = 3;
				int seed = 47;
				int X = 4;
				_expected = 6;
				_received = _obj.solve(R, C, seed, X); break;
			}
			case 2:
			{
				int R = 10000;
				int C = 14700;
				int seed = 12345;
				int X = 1;
				_expected = -1;
				_received = _obj.solve(R, C, seed, X); break;
			}
			case 3:
			{
				int R = 10;
				int C = 12;
				int seed = 123456789;
				int X = 3;
				_expected = 19;
				_received = _obj.solve(R, C, seed, X); break;
			}
			/*case 4:
			{
				int R = ;
				int C = ;
				int seed = ;
				int X = ;
				_expected = ;
				_received = _obj.solve(R, C, seed, X); break;
			}*/
			/*case 5:
			{
				int R = ;
				int C = ;
				int seed = ;
				int X = ;
				_expected = ;
				_received = _obj.solve(R, C, seed, X); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int seed = ;
				int X = ;
				_expected = ;
				_received = _obj.solve(R, C, seed, X); break;
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
