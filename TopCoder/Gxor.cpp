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
#line 39 "Gxor.cpp"
#include <string>
#include <vector>
class Gxor {
	public:
	long long countsubs(vector <string> S) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// There is a fixed integer n.
All graphs in this problem are undirected unweighted graphs on n vertices.
The vertices in each graph are numbered 0 through n-1.
Additionally, all graphs are simple, i.e., they do not contain self-loops and multiple edges between the same two vertices.

Given a sequence X of such graphs, the xor of that sequence is again a graph on our n vertices.
We will denote this graph XOR(X).
For each u and v, vertices u and v are connected by an edge in XOR(X) if and only if the number of graphs in X that contain the edge uv is odd.
(In other words, the xor of two graphs is a graph that contains the edge uv if and only if exactly one of those two graphs contains the edge uv. We then extend this definition to a xor of arbitrarily many graphs in exactly the same way that is used to extend the bitwise xor to arbitrarily many integers.)

Given a graph, we can convert it into a string using the following pseudocode:

string(G):
    for u = 0 .. n-1:
        for v = u+1 .. n-1:
            if G contains the edge uv: print 1
            else: print 0


You are given a vector <string> S that describes a sequence S of n-vertex graphs.
Each element of S is the string representation of one of those graphs.

We want to erase some (possibly none, possibly all) graphs from S.
Our goal is to produce a sequence T such that XOR(T) is a connected graph.
Return the number of ways in which we can do that.
(Two ways are considered distinct if the sets of indices of erased graphs differ.)
Note that all n vertices of the graph XOR(T) have to be in the same connected component - there must not be any isolated vertices.

DEFINITION
Class:Gxor
Method:countsubs
Parameters:vector <string>
Returns:long long
Method signature:long long countsubs(vector <string> S)


CONSTRAINTS
-S will contain between 1 and 50 elements, inclusive.
-Each element in S will contain exactly n * (n - 1) / 2 characters.
-n will be between 2 and 9, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
{"1","1","0"}

Returns: 4

This S contains three 2-vertex graphs.
Two of them contain the edge 0-1, one doesn't.
In order to have a connected XOR(T) we have to erase exactly one of the first two graphs, and we may or may not erase the last graph.

1)
{"011001"}

Returns: 0



2)
{"111011"}

Returns: 1



3)
{"110","011","101"}

Returns: 6



4)
{"111110","100000","100101","010101"}

Returns: 11



5)
{"110010000000111110101001001001101010",
"101011011000101001111110010000000001",
"010001101100000010010110000001100010",
"101100011110001011101000100010001111",
"111010000010010101010111001000000100",
"101100001101011101101011011001000010",
"111111010000000000110000010101100100"}


Returns: 121



6)
{"000000100000100110001000110001001000","010100001000000000000001001010000000",
"101000100010000100000000010000000010","110001101110110000010000000001000101",
"000001000000010000000110001010100101","100100010001010000000000000010000010",
"111001000000111111001001011001010000","100001100000110001011110000001010001",
"111000000001100100000000000011100000","111010110000011000100000000001101000",
"001000100000001010001001001000011001","110111001101000100000101000100100100",
"100111000010100110001100101101000001","000010100000110111000000000100100000",
"000100001010000000010010000000100100","001100000010010000000100100001100000",
"001000100100000100001000000100010001","011010000110001000000001010011001100",
"000100011111100000000010010010110000","000001010101001010011111100000000110",
"000010000010001010100100010001100000","010001011000000000000100000110000001",
"010000000100100000000000000000011000","100101001000001100000100001000000001",
"100010000000000000000001000000010000","101010000010001001011011000000000100",
"000010000000011010111000010111100100","010001101111000100100101110000100000",
"000110010000000100000000000010000010","111000001000000010010000011100000100",
"000010101100100100010100000000000000","110010001000100100010000000000000000",
"011000100000000100110101101100100001","000100000011001110100000001100111010",
"000110001101100010100000000000010000","000110010010011001010010100110001001",
"110001100000010000000000100100010110","001110011000110000100110000011001000",
"000001000100000110011100000100000101","100001000000010000100000101001101100",
"011010110000011000110011111101011110","010001100010101100000101000000010001",
"011011000101000001101110100011110110","101000001100010010001100011000000010",
"001111000011100001110000010010010001","010000001010010000010000101000110000",
"001101100001000101000100010011001110","001010110110101000010100101101010101",
"000100010111110010010100101000100101","100010000000010101111010010000110001"}


Returns: 1086198432923648



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
		cout << "Testing Gxor (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444831812;
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
		Gxor _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S[] = {"1","1","0"};
				_expected = 4LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 1:
			{
				string S[] = {"011001"};
				_expected = 0LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 2:
			{
				string S[] = {"111011"};
				_expected = 1LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 3:
			{
				string S[] = {"110","011","101"};
				_expected = 6LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 4:
			{
				string S[] = {"111110","100000","100101","010101"};
				_expected = 11LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 5:
			{
				string S[] = {"110010000000111110101001001001101010",
				             "101011011000101001111110010000000001",
				             "010001101100000010010110000001100010",
				             "101100011110001011101000100010001111",
				             "111010000010010101010111001000000100",
				             "101100001101011101101011011001000010",
				             "111111010000000000110000010101100100"};
				_expected = 121LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			case 6:
			{
				string S[] = {"000000100000100110001000110001001000","010100001000000000000001001010000000",
				             "101000100010000100000000010000000010","110001101110110000010000000001000101",
				             "000001000000010000000110001010100101","100100010001010000000000000010000010",
				             "111001000000111111001001011001010000","100001100000110001011110000001010001",
				             "111000000001100100000000000011100000","111010110000011000100000000001101000",
				             "001000100000001010001001001000011001","110111001101000100000101000100100100",
				             "100111000010100110001100101101000001","000010100000110111000000000100100000",
				             "000100001010000000010010000000100100","001100000010010000000100100001100000",
				             "001000100100000100001000000100010001","011010000110001000000001010011001100",
				             "000100011111100000000010010010110000","000001010101001010011111100000000110",
				             "000010000010001010100100010001100000","010001011000000000000100000110000001",
				             "010000000100100000000000000000011000","100101001000001100000100001000000001",
				             "100010000000000000000001000000010000","101010000010001001011011000000000100",
				             "000010000000011010111000010111100100","010001101111000100100101110000100000",
				             "000110010000000100000000000010000010","111000001000000010010000011100000100",
				             "000010101100100100010100000000000000","110010001000100100010000000000000000",
				             "011000100000000100110101101100100001","000100000011001110100000001100111010",
				             "000110001101100010100000000000010000","000110010010011001010010100110001001",
				             "110001100000010000000000100100010110","001110011000110000100110000011001000",
				             "000001000100000110011100000100000101","100001000000010000100000101001101100",
				             "011010110000011000110011111101011110","010001100010101100000101000000010001",
				             "011011000101000001101110100011110110","101000001100010010001100011000000010",
				             "001111000011100001110000010010010001","010000001010010000010000101000110000",
				             "001101100001000101000100010011001110","001010110110101000010100101101010101",
				             "000100010111110010010100101000100101","100010000000010101111010010000110001"};
				_expected = 1086198432923648LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}
			/*case 7:
			{
				string S[] = ;
				_expected = LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string S[] = ;
				_expected = LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string S[] = ;
				_expected = LL;
				_received = _obj.countsubs(vector <string>(S, S+sizeof(S)/sizeof(string))); break;
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
