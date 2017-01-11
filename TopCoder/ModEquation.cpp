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

#include <string>
#include <vector>
class ModEquation {
	public:
	vector <int> count(int n, int K, vector <int> query) {
          int p = 2;
          map<int,int> div;
          VI ps;
          int KK = K;
          while (p * p <= K) {
            if (K % p == 0) {
              ps.PB(p);
              while (K % p == 0) {
                div[p]++;
                K /= p;
              }
            }
          }
          if (K > 1) {
            div[K]++;
            ps.PB(K);
          }

          for (int q : query) {
            map<int,int> dq;
            int mask = 0;
            REP(i, SZ(ps)) {
              int p = ps[i];
              while (q % p == 0) {
                q /= p;
                dq[p]++;
              }
              if (dq[p] == 0) {
                mask |= (1 << i);
              }
            }
            REP(m, (1<<SZ(ps))) {
              if ((m & mask) == mask) {
                bool fail = false;
                REP(i, SZ(ps)) {
                  if (((m >> i) & 1) && dq[ps[i]] > 0 && dq[ps[i]] < div[ps[i]]) {
                    fail = true;
                  }
                }
                if (fail) continue;
                int c = 0;
                REP(i, SZ(ps)) {
                  if ((m ^ mask) & (1 << i)) {
                    c++;
                  }
                }
              }
            }
          }
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
		cout << "Testing ModEquation (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1483014998;
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
		ModEquation _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 2;
				int K = 2;
				int query[] = {0,1};
				int __expected[] = {3, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int K = 4;
				int query[] = {0,1,2,3};
				int __expected[] = {8, 2, 4, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 6;
				int K = 6;
				int query[] = {4};
				int __expected[] = {2016 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 1;
				int K = 2;
				int query[] = {0,0,0,1,1,1};
				int __expected[] = {1, 1, 1, 1, 1, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}
			/*case 4:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int K = ;
				int query[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.count(n, K, vector <int>(query, query+sizeof(query)/sizeof(int))); break;
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
