#include <string>
#include <cassert>
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
#define MS0(x) memset(x,0,sizeof(x))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
// #line 40 "ColorfulGarden.cpp"
#include <string>
#include <vector>
class ColorfulGarden {
public:
    vector <string> rearrange(vector <string> garden) {
        int N = garden[0].size();
        int cnt[256]; MS0(cnt);
        REP(i, 2) {
            REP(j, N) {
                cnt[garden[i][j] - 'a']++;
            }
        }
        int m = 0;
        REP(c, 26) {
            if (cnt[c] > N) {
                return vector<string>();
            }
            if (cnt[c] > cnt[m]) {
                m = c;
            }
        }
        int c = 0;
        if (cnt[m] == N) {
            REP(j, N) {
                garden[j%2][j] = 'a' + m;
            }
            cnt[m] = 0;
            int i = 1;
            REP(j, N) {
                while (c < 26 && cnt[c] == 0) {
                    c++;
                }
                assert(c < 26);
                garden[(j%2)^i][j] = 'a'+c;
                cnt[c]--;
            }
            return garden;
        }

        REP(i, 2) {
            REP(j, N) {
                while (c < 26 && cnt[c] == 0) {
                    c++;
                }
                assert(c < 26);
                garden[(j%2)^i][j] = 'a'+c;
                cnt[c]--;
            }
        }
        return garden;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// We have a garden that contains some flowers.
The flowers are arranged into a rectangle with 2 rows and n columns.
You are given a vector <string> garden that describes our garden.
The vector <string> garden has two elements, each with n characters.
Each character in garden represents one flower.
Different characters in garden represent different colors.



Two flowers are considered adjacent if they are in the same column, or if they are next to each other in the same row.
Your goal is to produce a garden in which no pair of adjacent flowers shares the same color.
You may rearrange the flowers in your garden arbitrarily (without changing its shape).
More precisely, you may swap any two flowers in your garden, and you may do so arbitrarily many times.



If the goal can be reached, return a vector <string> that will encode the resulting garden in the same format as was used for garden.
If there are multiple solutions, you may return any of them.
If there is no solution, return an empty vector <string>.


DEFINITION
Class:ColorfulGarden
Method:rearrange
Parameters:vector <string>
Returns:vector <string>
Method signature:vector <string> rearrange(vector <string> garden)


CONSTRAINTS
-garden will contain exactly 2 elements, inclusive.
-Each element in garden will contain between 1 and 50 characters, inclusive.
-Each element in garden will contain the same number of characters.
-Each character in garden will be a lowercase letter ('a'-'z').


EXAMPLES

0)
{"aa",
 "bb"}

Returns: {"ab", "ba" }

Swapping garden[0][1] and garden[1][1] produces a valid garden.

1)
{"xxxx",
 "xxxx"}

Returns: { }

No matter what we do, we will end up with the same result, and that is not a valid solution.

2)
{"abcd",
 "abcd"}

Returns: {"abcd", "dcba" }



3)
{"abcdefghijklm",
 "nopqrstuvwxyz"}

Returns: {"abcdefghijklm", "nopqrstuvwxyz" }



4)
{"aaa",
 "aab"}

Returns: { }



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
		cout << "Testing ColorfulGarden (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1461427206;
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
		ColorfulGarden _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string garden[] = {"aa",
				                   "bb"};
				string __expected[] = {"ab", "ba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 1:
			{
				string garden[] = {"xxxx",
				                   "xxxx"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 2:
			{
				string garden[] = {"abcd",
				                   "abcd"};
				string __expected[] = {"abcd", "dcba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 3:
			{
				string garden[] = {"abcdefghijklm",
				                   "nopqrstuvwxyz"};
				string __expected[] = {"abcdefghijklm", "nopqrstuvwxyz" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 4:
			{
				string garden[] = {"aaa",
				                   "aab"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			case 5:
			{
				string garden[] = {"dd", "bc"};
				string __expected[] = {};
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}
			/*case 6:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string garden[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.rearrange(vector <string>(garden, garden+sizeof(garden)/sizeof(string))); break;
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
