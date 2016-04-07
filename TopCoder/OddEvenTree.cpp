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
#define PB push_back
typedef vector<int> VI;

struct DisjointSet {
  VI par, _size;
  int N;

  DisjointSet(int N): par(N), _size(N), N(N) {
    init();
  }

  void init() {
    for(int i = 0; i < N; i++) {
      par[i] = i;
      _size[i] = 1;
    }
  }

  int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_size[x] < _size[y]) {
      par[x] = y;
      _size[y] += _size[x];
    } else {
      par[y] = x;
      _size[x] += _size[y];
    }
  }

  int size(int x) {
    return _size[find(x)];
  }
};

int d[51][51];

class OddEvenTree {
	public:
	vector <int> getTree(vector <string> x) {
        int N = x.size();
        DisjointSet s(N);
        VI ans;
        REP(i, N) {
            if (x[i][i] == 'O') return {-1};
            d[i][i] = 0;
            REP(j, i) {
                d[i][j] = d[j][i] = 1e9;
                if (x[i][j] != x[j][i]) return {-1};
                if (x[i][j] == 'O' && s.find(i) != s.find(j)) {
                    s.unite(i, j);
                    d[i][j] = d[j][i] = 1;
                    ans.PB(j); ans.PB(i);
                }
            }
        }

        REP(k, N) {
            REP(i, N) {
                REP(j, N) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        REP(i, N) {
            REP(j, N) {
                if (d[i][j] == 1e9) {
                    return {-1};
                }
                if (d[i][j] % 2) {
                    if (x[i][j] == 'E')
                        return {-1};
                } else {
                    if (x[i][j] == 'O') {
                        return {-1};
                    }
                }
            }
        }
        return ans;
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// In a tree, the distance between two nodes is the number of edges on the (only) simple path that connects them.


You are given a vector <string> x with N elements, each containing N characters.
Draw a tree with N nodes, numbered 0 through N-1.
The tree must have the following properties:
For each i and j, if x[i][j] is 'E' the distance between i and j must be even, and if it is 'O' (uppercase o) this distance must be odd.


If there is no tree with these properties, return {-1}.
Otherwise, return a vector <int> with 2N-2 elements: the list of edges in one such tree.
For example, if N=3 and your tree contains the edges 0-2 and 1-2, return {0,2,1,2}.
If there are multiple correct outputs you may output any of them.

DEFINITION
Class:OddEvenTree
Method:getTree
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getTree(vector <string> x)


NOTES
-If you use plugins to test your solution, be careful. Plugins cannot tell you whether your solution is correct -- they'll just tell you whether it matches the example output exactly.


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-x will contain exactly n elements.
-Each element in x will have exactly n characters.
-Each character in x will be 'O' or 'E'.


EXAMPLES

0)
{"EOE",
 "OEO",
 "EOE"}

Returns: {0, 1, 2, 1 }

The tree: 0-1-2 is a valid answer.

1)
{"EO",
 "OE"}

Returns: {0, 1 }



2)
{"OO",
 "OE"}

Returns: {-1 }

dist[0][0] must be 0, and it should be an even number, so it is impossible.

3)
{"EO",
 "EE"}

Returns: {-1 }

dist[0][1] should be same with dist[1][0].

4)
{"EOEO",
 "OEOE",
 "EOEO",
 "OEOE"}

Returns: {0, 1, 0, 3, 2, 1 }



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
		cout << "Testing OddEvenTree (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1430838003;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		OddEvenTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string x[] = {"EOE",
				              "OEO",
				              "EOE"};
				int __expected[] = {0, 1, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 1:
			{
				string x[] = {"EO",
				              "OE"};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 2:
			{
				string x[] = {"OO",
				              "OE"};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 3:
			{
				string x[] = {"EO",
				              "EE"};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 4:
			{
				string x[] = {"EOEO",
				              "OEOE",
				              "EOEO",
				              "OEOE"};
				int __expected[] = {0, 1, 0, 3, 2, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			case 5:
			{
				string x[] = {"EE","EE"};
				int __expected[] = {-1};
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}
			/*case 6:
			{
				string x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getTree(vector <string>(x, x+sizeof(x)/sizeof(string))); break;
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
