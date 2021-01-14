#line 2 "FlightPlan.cpp"
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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
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

struct T {
    LL d;
    int r, c, h;
    //bool operator<(const T& t2) const {
	//return d < t2.d;
    //}
};

struct Compare {
    bool operator()(const T& t1, const T& t2) const {
	return t1.d > t2.d;
    }
};

class FlightPlan {
public:
    long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr) {
	VI h = H;
	SORT_UNIQUE(h);	
	priority_queue<T, vector<T>, Compare> pq;
	pq.push((T){0, 0, 0, (int)GET_POS(h, H[0])});
	vector<vector<VL>> D(R, vector<VL>(C, VL(SZ(h), 1e18)));
	while (pq.size()) {
	    const T &t = pq.top();
	    LL d = t.d;
	    int r = t.r, c = t.c, i = t.h;
	    pq.pop();
	    if (d > D[r][c][i]) {
		continue;
	    }
	    //cout << d << ' ' << r << ' ' << c << ' ' << h[i] << endl;
	    if (r == R-1 && c == C-1 && h[i] == H[r * C + c]) {
		return d;
	    }
	    if (i+1 < SZ(h) && D[r][c][i+1] > d + 1ll * cup * (h[i+1] - h[i])) {
		pq.push((T){D[r][c][i+1] = d + 1ll * cup * (h[i+1] - h[i]), r, c, i+1});
	    }
	    if (i-1 >= 0 && h[i-1] >= H[r * C + c] && D[r][c][i-1] > d + cdn * 1ll * (h[i] - h[i-1])) {
		pq.push((T){D[r][c][i-1] = d + cdn * 1ll * (h[i] - h[i-1]), r, c, i-1});
	    }
	    if (r+1 < R && h[i] >= H[(r+1)*C+c] && D[r+1][c][i] > d + clr) {
		pq.push((T){D[r+1][c][i] = d + clr, r+1, c, i});
	    }
	    if (r-1 >= 0 && h[i] >= H[(r-1)*C+c] && D[r-1][c][i] > d + clr) {
		pq.push((T){D[r-1][c][i] = d + clr, r-1, c, i});
	    }
	    if (c+1 < C && h[i] >= H[r*C+c+1] && D[r][c+1][i] > d + clr) {
		pq.push((T){D[r][c+1][i] = d + clr, r, c+1, i});
	    }
	    if (c-1 >= 0 && h[i] >= H[r*C+c-1] && D[r][c-1][i] > d + clr) {
		pq.push((T){D[r][c-1][i] = d + clr, r, c-1, i});
	    }
	}
	return 0;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
There is a horizontal rectangular board with R rows and C columns of unit squares.


A three-dimensional world is built on top of this board: on each square of the board there is a stack of zero or more unit cubes.
The number of cubes on the square (r, c) is H[r*C + c].



We have a helicopter. The helicopter is negligibly tiny in comparison to the unit cubes that form the world, so we'll pretend it's a point. The helicopter is currently standing in the middle of the top face of the stack of cubes on square (0, 0). 


We want to get the helicopter to land in the opposite corner of the board: in the middle of the top face of the stack of cubes at coordinates (R-1, C-1).



The helicopter can move in three ways: it can fly up, down, or sideways. Each time it moves, it must move by exactly 1 unit of distance. Flying an unit of distance upwards costs cup, flying the same distance downwards costs cdn,
and flying an unit of distance sideways costs clr. When flying sideways, the direction of travel must be one of the four cardinal directions, so after each move the helicopter will be hovering over the center of one of the unit squares.


Obviously, the helicopter cannot leave the board and it cannot fly into a stack of cubes. It can fly while touching the top surface of a stack of cubes, so for example the helicopter's first move can be sideways as long as it goes into a square that doesn't have a higher stack of cubes. 



Calculate and return the minimum total cost of reaching the helicopter's destination.


DEFINITION
Class:FlightPlan
Method:fly
Parameters:int, int, vector <int>, int, int, int
Returns:long long
Method signature:long long fly(int R, int C, vector <int> H, int cup, int cdn, int clr)


CONSTRAINTS
-R will be between 1 and 50, inclusive.
-C will be between 1 and 50, inclusive.
-H will contain exactly R * C elements.
-Each element of H will be between 0 and 10^6, inclusive.
-cup, cdn and clr will each be between 1 and 10^6, inclusive.


EXAMPLES

0)
1
5
{10, 8, 6, 8, 10}
40
10
20

Returns: 80

This world has just a single row. The helicopter both starts and wants to end in height 10, and as there are no obstacles in its way, the cheapest solution is to simply fly horizontally (i.e., to the next column) four times.

1)
6
1
{10, 8, 16, 18, 8, 12}
40
10
20

Returns: 480

One optimal solution looks as follows:

Start in row 0, column 0, with starting altitude 10.
Fly to the next row. (This costs 20 and results in a helicopter hovering 2 units of distance above the surface at this point.)
Fly 6 units upwards. (Cost 240, now the helicopter's altitude is 16.)
Fly to the next row. (Cost 20. We are now in the middle row and we are touching its surface.)
Fly another 2 units upwards. (Cost 80, now the helicopter's altitude is 18.)
Fly two units to the right. (Cost 40.)
Fly 6 units down. (Cost 60. We are now in row 0, column 4 and our altitude is 12.
Fly one unit to the right (cost 20), and as we have exactly the correct altitude, terminate. 


The total cost is 480.


2)
5
5
{  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}
1000
1000
1

Returns: 5010

Flying up and down is very expensive. It's better to take a longer route, starting by moving from row 0 to row 1.

3)
5
5
{  100, 1000,  100,  100,  100,
    97, 9999, 9999, 9999,  100,
    93, 9999,    0, 9999,  100,
    99, 9999,   83,   65,  100,
    98,   93,   90, 9999,   95}
1
1
1000

Returns: 9805

The same map but now horizontal movement is expensive. Here it's better to travel through the square (0, 4).

4)
1
1
{47}
123
234
345

Returns: 0

The obligatory example illustrating that travel starting and finishing at the same spot has cost 0.

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
		cout << "Testing FlightPlan (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1610211903;
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
		FlightPlan _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 1;
				int C = 5;
				int H[] = {10, 8, 6, 8, 10};
				int cup = 40;
				int cdn = 10;
				int clr = 20;
				_expected = 80LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}
			case 1:
			{
				int R = 6;
				int C = 1;
				int H[] = {10, 8, 16, 18, 8, 12};
				int cup = 40;
				int cdn = 10;
				int clr = 20;
				_expected = 480LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}
			case 2:
			{
				int R = 5;
				int C = 5;
				int H[] = {  100, 1000,  100,  100,  100,
				              97, 9999, 9999, 9999,  100,
				              93, 9999,    0, 9999,  100,
				              99, 9999,   83,   65,  100,
				              98,   93,   90, 9999,   95};
				int cup = 1000;
				int cdn = 1000;
				int clr = 1;
				_expected = 5010LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}
			case 3:
			{
				int R = 5;
				int C = 5;
				int H[] = {  100, 1000,  100,  100,  100,
				              97, 9999, 9999, 9999,  100,
				              93, 9999,    0, 9999,  100,
				              99, 9999,   83,   65,  100,
				              98,   93,   90, 9999,   95};
				int cup = 1;
				int cdn = 1;
				int clr = 1000;
				_expected = 9805LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}
			case 4:
			{
				int R = 1;
				int C = 1;
				int H[] = {47};
				int cup = 123;
				int cdn = 234;
				int clr = 345;
				_expected = 0LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}
			/*case 5:
			{
				int R = ;
				int C = ;
				int H[] = ;
				int cup = ;
				int cdn = ;
				int clr = ;
				_expected = LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int H[] = ;
				int cup = ;
				int cdn = ;
				int clr = ;
				_expected = LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
			}*/
			/*case 7:
			{
				int R = ;
				int C = ;
				int H[] = ;
				int cup = ;
				int cdn = ;
				int clr = ;
				_expected = LL;
				_received = _obj.fly(R, C, vector <int>(H, H+sizeof(H)/sizeof(int)), cup, cdn, clr); break;
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
