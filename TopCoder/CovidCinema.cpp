#line 2 "CovidCinema.cpp"
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
#define REP(I, N) for (int I = 0; I < (N); ++I)
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

class CovidCinema {
public:
    vector <string> seat(int R, int C, int A, int B) {
	vector<string> ans(R, string(C, '.'));

	int d = 1;
	while (A) {
	    REP(i, d) {
		if (A == 0) {
		    break;
		}
		if (R >= C) {
		    if (i < R && d - 1 - i < C) {
			ans[i][d-1-i] = 'A';
			A--;
		    }
		} else {
		    if (d - 1 - i < R && i < C) {
			ans[d-1-i][i] = 'A';
			A--;
		    }
		}
	    }
	    d++;
	}

	REP(i, R) {
	    if (B == 0) {
		break;
	    }
	    REP(j, C) {
		if (B == 0) {
		    break;
		}
		if (ans[i][j] == 'A') {
		    continue;
		}
		if (i > 0 && ans[i-1][j] == 'A') {
		    continue;
		}
		if (j > 0 && ans[i][j-1] == 'A') {
		    continue;
		}
		ans[i][j] = 'B';
		B--;
	    }
	}

	if (B) {
	    return vector<string>();
	}

	return ans;
    }
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
You are running a cinema.
The auditorium is a rectangular array of seats with R rows and C columns in each row.


Due to the Covid-19 regulations, people who are not a part of the same group are not allowed to sit next to each other, nor immediately behind each other.


Two groups of people would like to see the same movie.
There are A people in the first group and B people in the second group.


If it is impossible to seat all those people according to the regulations, return an empty vector <string>.
Otherwise, return any one possible seating plan: a vector <string> with R elements, each containing C characters. Use 'A' for people from the first group, 'B' for people from the second group, and '.' for empty seats.


DEFINITION
Class:CovidCinema
Method:seat
Parameters:int, int, int, int
Returns:vector <string>
Method signature:vector <string> seat(int R, int C, int A, int B)


CONSTRAINTS
-R will be between 1 and 50, inclusive.
-C will be between 1 and 50, inclusive.
-A will be between 1 and R*C, inclusive.
-B will be between 1 and R*C, inclusive.


EXAMPLES

0)
4
6
2
3

Returns: {"......", ".A..BB", "......", "B.A..." }

A rather large cinema and very few people. We have many ways to place them. The example one is shown below in a nicer format:

......
.A..BB
......
B.A...


1)
4
5
13
7

Returns: { }

These two groups would fill the cinema completely, and that's not possible without some 'A' being adjacent to some 'B'.

2)
4
5
14
2

Returns: {"B.AAA", ".AAAA", "AAAA.", "AAA.B" }


B.AAA
.AAAA
AAAA.
AAA.B


3)
5
5
17
4

Returns: {"AAAAA", "AAAAA", "..AAA", "BB.AA", "BB.AA" }


AAAAA
AAAAA
..AAA
BB.AA
BB.AA


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
		cout << "Testing CovidCinema (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1599321908;
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
		CovidCinema _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int R = 4;
				int C = 6;
				int A = 2;
				int B = 3;
				string __expected[] = {"......", ".A..BB", "......", "B.A..." };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}
			case 1:
			{
				int R = 4;
				int C = 5;
				int A = 13;
				int B = 7;
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}
			case 2:
			{
				int R = 4;
				int C = 5;
				int A = 14;
				int B = 2;
				string __expected[] = {"B.AAA", ".AAAA", "AAAA.", "AAA.B" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}
			case 3:
			{
				int R = 5;
				int C = 5;
				int A = 17;
				int B = 4;
				string __expected[] = {"AAAAA", "AAAAA", "..AAA", "BB.AA", "BB.AA" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}
			case 4:
			{
				int R = 2;
				int C = 11;
				int A = 10;
				int B = 10;
				string __expected[] = {"AAAAA.BBBBB", "AAAAA.BBBBB"};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}
			/*case 5:
			{
				int R = ;
				int C = ;
				int A = ;
				int B = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
			}*/
			/*case 6:
			{
				int R = ;
				int C = ;
				int A = ;
				int B = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.seat(R, C, A, B); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
