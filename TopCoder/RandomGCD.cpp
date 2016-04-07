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
 
typedef long long LL;

#define MOD 1000000007
inline int sub(int a, int b, int mod=MOD) { return a - b < 0 ? a - b + mod : a - b; }
inline void subBy(int &a, int b, int mod=MOD) { a = sub(a, b, mod); }
inline int mul(int a, int b, int mod=MOD) { return (LL)a * b % mod; }

template<class T>
T pow(T a, T b, T c=MOD){
  T x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

struct RandomGCD {
	map<pair<int, int>, int> mem;
  int countTuples(int N, int K, int low, int high) {
  	if(low > high) return 0;
  	if(K > 1) {
	  	int l = (low % K) ? low / K + 1 : low / K;
	  	int h = high / K;
  		return countTuples(N, 1, l, h);
  	}
  	auto state = make_pair(low, high);
  	if(mem.count(state))
  		return mem[state];
  	int ans = pow(high - low + 1, N);
  	for(int i = 2; i <= high; i++) {
  		if(i >= high - low + 1 && i < low) {
  			i = low;
  		}
  		subBy(ans, countTuples(N, i, low, high));
  	}
  	return mem[state] = ans;
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
		cout << "Testing RandomGCD (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1395414615;
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
		RandomGCD _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int K = 2;
				int low = 2;
				int high = 4;
				_expected = 3;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 1:
			{
				int N = 2;
				int K = 100;
				int low = 2;
				int high = 4;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 2:
			{
				int N = 1;
				int K = 5;
				int low = 5;
				int high = 5;
				_expected = 1;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 3:
			{
				int N = 73824;
				int K = 17347;
				int low = 9293482;
				int high = 9313482;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 4:
			{
				int N = 222;
				int K = 222;
				int low = 222;
				int high = 22222;
				_expected = 339886855;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			case 5:
			{
				int N = 10;
				int K = 1;
				int low = 1000000000;
				int high = 1000000000;
				_expected = 0;
				_received = _obj.countTuples(N, K, low, high); break;
			}
			/*case 6:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
			}*/
			/*case 7:
			{
				int N = ;
				int K = ;
				int low = ;
				int high = ;
				_expected = ;
				_received = _obj.countTuples(N, K, low, high); break;
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
