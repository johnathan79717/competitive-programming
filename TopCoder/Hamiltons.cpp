#line 2 "Hamiltons.cpp"
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
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define PB emplace_back
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

class Hamiltons {
public:
    vector <int> construct(int N, int L) {
	int e[N][N];
	REP(i, N) {
	    REPP(j, i+1, N) {
		e[i][j] = L;
	    }
	}
	REP(i, N-1) {
	    e[i][i+1] = 1;
	}
	int x = (L + N - 4) / (N - 2);
	int d = (L + N - 4) % (N - 2);
	REP(i, d) {
	    e[i][i+2] = x + 1;
	}
	REPP(i, d, N-2) {
	    e[i][i+2] = x;
	}
	VI ans;
	REP(i, N) {
	    REPP(j, i+1, N) {
		ans.PB(e[i][j]);
	    }
	}
	return ans;
    }
	
};

// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
In this problem you are given the ints N >= 6 and L >= 10.
We will consider complete undirected graphs with N vertices in which each edge is labeled with a positive integer between 1 and L, inclusive.
Below, "a graph" denotes a graph with these properties.



Maru and Vlado were given a standard programming homework: given a graph, find the cost of the cheapest Hamiltonian path.


Maru has implemented her solution properly.
Vlado was lazy:
He realized that he had recently implemented a program that constructs one of the cheapest Hamiltonian cycles in the given graph.
Given this new homework, he now thought: "That's easy! I'll just construct the cycle and then I'll throw away the most expensive edge and I'm done."
Your task is to show that this lazy approach does not have to work.


We will now introduce several definitions.


Let Maru(G) be the cost of the optimal Hamiltonian path for G.
Let Vlado(G) be the smallest cost of a Hamiltonian path Vlado's algorithm might return for G.
That is, if G contains multiple cheapest Hamiltonian cycles, assume that Vlado's algorithm will always get lucky and pick the one among them that produces the cheapest Hamiltonian path.


Construct any graph G such that Vlado(G) - Maru(G) >= L/2.


Return a vector <int> that contains the upper triangular half of the distance matrix of your G in row major order.
That is, if the vertices of your graph G are labeled starting from 0 and e(i,j) is the weight of edge i-j, return { e(0,1), e(0,2), ..., e(0,N-1), e(1,2), e(1,3), ..., e(N-2,N-1) }.


DEFINITION
Class:Hamiltons
Method:construct
Parameters:int, int
Returns:vector <int>
Method signature:vector <int> construct(int N, int L)


NOTES
-For the given constraints a solution always exists.
-You are not required to optimize the value Vlado(G) minus Maru(G). Any graph that matches the requirements listed in the statement will be accepted.


CONSTRAINTS
-N will be between 6 and 14, inclusive.
-L will be between 10 and 1000, inclusive.


EXAMPLES

0)
6
1000

Returns: {174, 325, 60, 839, 248, 437, 398, 965, 806, 658, 985, 969, 319, 100, 149 }

The distance matrix of the returned graph G:

  0 174 325  60 839 248
174   0 437 398 965 806
325 437   0 658 985 969
 60 398 658   0 319 100
839 965 985 319   0 149
248 806 969 100 149   0


The shortest Hamiltonian path has length 920. This is the path 2-1-0-3-5-4 with edge lengths 437, 174, 60, 100, 149.


The unique shortest Hamiltonian cycle is the cycle 0-2-1-3-4-5-0. Its edge lengths are 325, 437, 398, 319, 149, 248. Thus, Vlado will discard the longest edge (2-1, length 437) and obtain the Hamiltonian path 1-3-4-5-0-2 with total length 1439.


The difference 1439 - 920 = 519 is large enough: L/2 is only 500.


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
		cout << "Testing Hamiltons (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1596299591;
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
		Hamiltons _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 6;
				int L = 1000;
				int __expected[] = {174, 325, 60, 839, 248, 437, 398, 965, 806, 658, 985, 969, 319, 100, 149 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, L); break;
			}
			/*case 1:
			{
				int N = ;
				int L = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, L); break;
			}*/
			/*case 2:
			{
				int N = ;
				int L = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, L); break;
			}*/
			/*case 3:
			{
				int N = ;
				int L = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(N, L); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
