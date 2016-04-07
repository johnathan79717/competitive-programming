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
#define FOR(i, c) for(auto &i: c)
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define MP make_pair
#define PB push_back
#define SZ size()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define F first
#define S second
#define V(T) vector<T >
#define EB emplace_back
 
typedef long long LL;

struct BigO {
  int minK(vector <string> graph) {

  }
};

// BEGIN CUT HERE
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
		cout << "Testing BigO (600.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391790318;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 600.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BigO _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string graph[] = {"NYY",
				                  "YNY",
				                  "YYN"};
				_expected = -1;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 1:
			{
				string graph[] = {"NYNNN",
				                  "NNYNN",
				                  "NNNYN",
				                  "NNNNY",
				                  "NNNNN"};
				_expected = 0;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 2:
			{
				string graph[] = {"NYNNN",
				                  "YNNNN",
				                  "NNNYN",
				                  "NNNNY",
				                  "NNYNN"};
				_expected = 0;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 3:
			{
				string graph[] = {"NYYYNYYYNNYYYYYYNYNN",
				                  "NNNNYNYYNNYYYNYYNYYN",
				                  "NYNNYYYNNNYYYYNYNYNN",
				                  "NYYNNYYYYNNNYYNNYNYY",
				                  "NYNYNNNNNNYYYYYNYYYN",
				                  "YNNNNNNYNNYNNYYYYYYY",
				                  "NNYYNNNNNYNYNYNNYNYY",
				                  "NNYNYYNNNNYNYNYYYYNN",
				                  "NYYNYYNNNYNNYYYNYNYN",
				                  "YYNNYNNYYNYNNNNNYNNN",
				                  "YYNYYNNYYYNYYNYNYYYY",
				                  "YYNNYYNYNYNNNNYNNNNY",
				                  "NNYYNYYYNNNNNYYYYYNY",
				                  "YNNNYNNNNYNNNNNYNNNY",
				                  "YYYYNYYNNYNNNNNYNNNN",
				                  "NYYYYNYNYYNNYNNNYNNY",
				                  "YYYYYNNNYYYYNYYYNNYN",
				                  "NNYNNYNYNYNNNNNNYNYN",
				                  "YYNYYNNNNNYNNYNYNNNY",
				                  "YYYYNYNYYNNYNYNYNNNN"};
				_expected = -1;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			case 4:
			{
				string graph[] = {"NYNYYYNYYYNYYNYYNYYNYYNYNNYYYYNNNYYNNNYNYYNYNNNYNY",
				                  "NNNNNNNNNNNNNNNNYNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNNNN",
				                  "NYNYYYYNYNYYNNYYYYYYYYYYNYYYNYYYYYYNNYYYYYYYNNYYYY",
				                  "NYNNYYNNNNNNNNNNNYNNNYNYNNYNYNYYNYYNNYYYNNNNNNNYYY",
				                  "NNNNNNNNNNNNYNNYYNNNYNNNNYNNYNNYNNYNNYNYNNNNNNNYYN",
				                  "NNNNNNNNNNNNNNNNYNNNYNNNNNNNNNYNNNNNNYNNNNNNNNNNNN",
				                  "YYNYNNNYNYYYYNYYYYYYYYYYNYYYYYYYNYYNNYNYYYYYNNYNYY",
				                  "NYNYYNNNYYNNYNNYYYNNYYNYNYYNYYYNNNYNNYYYNNNNNNNYYY",
				                  "NYNYYYNYNYNNNNNYYYNNNNNNNYYNYYYYNYYNNYYYNNNNNNNYYY",
				                  "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYNNYYNNYNYNNNYNNNNYN",
				                  "NYNYYYNNYYNYYNYNYYNYYYNYNYYNYYYYNYNNNNYYYYNYNNNYNY",
				                  "NYNNYYNNNYNNYNNYYYNNYYNNNYYNYYNNNYYNNNNYNNNYNNNYYY",
				                  "NNNNNNNNNNNNNNNYYNNNYNNNNNNNYNNYNYNNNYYNNNNNNNNYNN",
				                  "YYYYNYYYYYYYYNYYYYNYYYYYYYYYYYNYYNYYYNYYYYYNNYYNYN",
				                  "NYNYYNNYYYNYYNNYYYNYNYNYNYYNYYYYNYYNNYYYYYNYNNNNNY",
				                  "NYNNNNNNNNNNNNNNYNNNYNNNNNYNYNYYNYNNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
				                  "NYNNNYNNNNNNNNNYYNNNNNNNNNNNYNYYNYYNNYNNNNNNNNNYYN",
				                  "NYNYYYNNYYNYNNYYYYNYYYNYNYYYYNNYNNYNNYNYYYYNNNYYYY",
				                  "NNNYYYNNNYNYYNNYYYNNYYNNNYYNYYYYNYYNNNYYNYNYNNNYYY",
				                  "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN",
				                  "NYNNNYNNNNNNNNNYNNNNNNNNNYYNYYYYNYYNNYNNNNNNNNNYYN",
				                  "YYNYYYNNYYNYYNYNYYNYNYNYNYYYYYYYNYNNNYYYYYNYNNYYYY",
				                  "NYNYYYNNNNNNYNNNYYNNYYNNNYYNYYYYNYYNNYYYNNNNNNNYNY",
				                  "YNNNYYYYYYYYYNYYYYYYYYYNNYYNYNYNYNNYYYYYYYNYNNYYYY",
				                  "NYNNNYNNNNNNNNNYYNNNYNNNNNYNYNYYNYYNNNNYNNNNNNNYNN",
				                  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN",
				                  "NYNYYYNYYYNYNNNNYYNYYNNYNYYNYYYYNYYNNNNNYYNYNNYYNN",
				                  "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNN",
				                  "NYNNNYNNNNNNNNNYYNNNYNNNNNNNNNYYNYYNNNNYNNNNNNNYYY",
				                  "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNNYNNNYNNNNNYNNNYNNNNNNNNNNNNNNNNNNN",
				                  "NYNYYNNYYYNNNNNYYYNYYYNNNYYYYYYYNYYNNYYYYNNYNNNNYY",
				                  "NNNNNNNNNNNNNNNYYNNNYNNNNNYNYNYYNNNNNYNNNNNNNNNNNN",
				                  "NYNNNNNNNNNNNNNNYNNNYNNNNNYNNNYYNNNNNNNNNNNNNNNYNN",
				                  "NYNYYYYYNYYYYNYYYYYYNYYYNNNYYYYYNYYNYNYYYYYYNYYYNY",
				                  "YYNYYYNYYYNNNNNYNYYYYNYNNNYYYYYYNYYNNYYNYNNYNNYNNY",
				                  "NNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
				                  "NYNNNYNNNNNNNNNYYNNNNYNNNNYNYNNYNNNNNYNYNNNNNNNYNN",
				                  "NYNNNYNNNNNNNNNYYNNNNNNNNYYNYNYNNYYNNNNNNNNNNNNYNN",
				                  "NYNYYYNYYYNYNNNNNYNNYYNYNNYNNYYYNYYNNYYYNNNNNNNYYY",
				                  "NYNYYNNNNYNYYNNYYYNYYYNNNYYNYYYNNYYNNYYYNNNYNNNNYY",
				                  "NYNYNYNYYYNYYNYYNYNYNYYYNNYYYYYYNNNNNYYYNYNYNNYNYY",
				                  "NYNNNYNNNYNNNNNYYYNNYNNNNNYNYNNNNYYNNYNYNNNNNNNYYN",
				                  "YYYNNYNYYYNYNNYYYYYNYYNYNYYYYYNYYNYNYYYYYNNYNNYNYN",
				                  "YYNNYYYYYYYNYNYYNYYYYYYYYYYNYYYNYYYNNYYYYNYYNNYYYY",
				                  "NYNNYYNYYYNNYNNYYYNYNYNYNYYNNYYNNYNNNYYYNYNYNNNNYY",
				                  "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNN",
				                  "NNNNNNNNNNNNNNNNNNNNYNNNNNYNYNYNNNNNNYNNNNNNNNNYNN",
				                  "NYNNYYNNNNNNNNNYYNNNNNNNNYYNYNNYNYYNNYNYNNNNNNNYNN"};
				_expected = 7;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}
			/*case 5:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string graph[] = ;
				_expected = ;
				_received = _obj.minK(vector <string>(graph, graph+sizeof(graph)/sizeof(string))); break;
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
