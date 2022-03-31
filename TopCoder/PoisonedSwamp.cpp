#line 2 "PoisonedSwamp.cpp"
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

bool visited[20][20][10];

class PoisonedSwamp {
public:
    string cross(vector <string> swamp) {
	int N = swamp.size();
	int M = swamp[0].size();
	MS0(visited);
	visited[0][0][0] = true;
	queue<int> q;
	q.push(0);
	q.push(0);
	q.push(0);
	while (q.size()) {
	    int i = q.front(); q.pop();
	    int j = q.front(); q.pop();
	    int d = q.front(); q.pop();
	    //cout << i << ' ' << j << ' ' << d << endl;
	    int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};
	    REP(k, 4) {
		int i1 = i + di[k], j1 = j + dj[k];
		if (i1 >= 0 && i1 < N && j1 >= 0 && j1 < M && swamp[i1][j1] != '#') {
		    int d1;
		    switch (swamp[i1][j1]) {
			case '.':
			    d1 = d;
			    break;
			case 'S':
			    d1 = 0;
			    break;
			default:
			    assert(swamp[i1][j1] >= '1' && swamp[i1][j1] <= '9');
			    d1 = d + swamp[i1][j1] - '0';
		    }
		    if (d1 < 10 && !visited[i1][j1][d1]) {
			if (i1 == N-1 && j1 == M-1) {
			    return "possible";
			}
			visited[i1][j1][d1] = true;
			q.push(i1);
			q.push(j1);
			q.push(d1);
		    }
		}
	    }
	}
	return "impossible";
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are about to cross a poisoned swampy area.
Luckily, you have its map: the vector <string> swamp containing a rectangle of characters.
Each character represents one unit square of the swamp as follows:


'.' is a safe square, you can step on it.
'#' is a blocked square, you cannot step on it.
'1'-'9' are poisoned squares. Stepping on a square with digit X increases your poison count by X.
'S' is a spring with cleansing water. Stepping on it resets your poison count back to zero.



You start in the top left corner of the map (row 0, column 0) and your poison count is 0.
You want to reach the bottom right corner of the map.
You move in steps. 
In each step you can move from your current square to another square that shares a side with your current one.
You may not leave the mapped area.
If your poison count reaches 10 or more, you die.


You ARE allowed to enter the same square multiple times.
If you step on the same poisoned square multiple times, you get the corresponding amount of poison each time you do so.
If you step on the same spring multiple times, you get cleansed each time you do so.



Return "possible" if you can cross the swamp alive and "impossible" if you cannot do so.


DEFINITION
Class:PoisonedSwamp
Method:cross
Parameters:vector <string>
Returns:string
Method signature:string cross(vector <string> swamp)


CONSTRAINTS
-swamp will contain between 2 and 20 elements, inclusive.
-Each element of swamp will contain the same number of characters, and that number will be between 2 and 20, inclusive.
-Each character in swamp will be one of ".#123456789S" (quotes for clarity).
-The characters in the top left and bottom right corner of swamp will be '.'.


EXAMPLES

0)
{".....",
 "####.",
 ".....",
 ".####",
 "....."}

Returns: "possible"

There's no poison, just find your way across.

1)
{".....",
 "####.",
 "97...",
 "9#2##",
 "97..."}

Returns: "possible"

There is a strongly poisoned area in this swamp but luckily it can be avoided completely by taking a shortcut and only receiving 2 poison.

2)
{".111111111.",
 ".#########.",
 "..22222...."}

Returns: "possible"

If you go down and right, you'll eventually collect 10 poison and die. Luckily, if you go right and then down, you'll only collect 9 poison and you'll reach the end of the swamp alive.

3)
{".#222#111",
 "4#S#2#1#S",
 "4#3#S#1#9",
 "S33#111#."}

Returns: "possible"

A lot of poison in this swamp, but luckily for us the cleansing springs are frequent enough to get us through.

4)
{"..111111111111..",
 "###############."}

Returns: "impossible"

Too much poison along this way.

5)
{"..111111111111..",
 "#######S#######."}

Returns: "possible"

This example shows that sometimes we need to revisit the same cell. In this case, the only way to cross the swamp is to make a detour: after you have 6 poison, step down to reach the cleansing spring and then return back and continue. You will reach the end of the swamp alive (with 7 poison) if you do so.

6)
{"..#.#.",
 "..#.#.",
 "#5#.5.",
 "....#."}

Returns: "impossible"



7)
{".1.#.",
 ".9.#.",
 ".###.",
 "2#.1.",
 ".#.7."}

Returns: "impossible"



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
		cout << "Testing PoisonedSwamp (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1613235902;
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
		PoisonedSwamp _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string swamp[] = {".....",
				                  "####.",
				                  ".....",
				                  ".####",
				                  "....."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 1:
			{
				string swamp[] = {".....",
				                  "####.",
				                  "97...",
				                  "9#2##",
				                  "97..."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 2:
			{
				string swamp[] = {".111111111.",
				                  ".#########.",
				                  "..22222...."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 3:
			{
				string swamp[] = {".#222#111",
				                  "4#S#2#1#S",
				                  "4#3#S#1#9",
				                  "S33#111#."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 4:
			{
				string swamp[] = {"..111111111111..",
				                  "###############."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 5:
			{
				string swamp[] = {"..111111111111..",
				                  "#######S#######."};
				_expected = "possible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 6:
			{
				string swamp[] = {"..#.#.",
				                  "..#.#.",
				                  "#5#.5.",
				                  "....#."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			case 7:
			{
				string swamp[] = {".1.#.",
				                  ".9.#.",
				                  ".###.",
				                  "2#.1.",
				                  ".#.7."};
				_expected = "impossible";
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}
			/*case 8:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string swamp[] = ;
				_expected = ;
				_received = _obj.cross(vector <string>(swamp, swamp+sizeof(swamp)/sizeof(string))); break;
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
