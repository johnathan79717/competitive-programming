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
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back
#define V(T) vector<T >
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

void mini(LL &a, LL b) {
    a = min(a, b);
}

const LL M = 1e14;
V(LL) lucky;
void genlucky(LL x) {
    if (x >= M) {
        return;
    } else {
        lucky.PB(x);
        genlucky(x * 10 + 4);
        genlucky(x*10+7);
    }
}
LL ans = LLONG_MAX;
string note;
void check(LL x) {
    char str[20];
    sprintf(str, "%lld", x);
    if (strlen(str) != note.size()) {
        return;
    } else {
        REP(i, (int)note.size()) {
            if (note[i] != '?' && str[i] != note[i]) {
                return;
            }
        }
        ans = min(ans, x);
    }
}


void genLuckySum(LL x) {
    if (x*10+8<=M) {
        check(x*10+8);
        genLuckySum(x*10+8);
    }
    if (x*10+14<=M) {
        check(x*10+14);
        genLuckySum(x*10+14);
    }
    if (x*10+11<=M) {
        check(x*10+11);
        genLuckySum(x*10+11);
    }
}

LL dp[2][3][2];
class LuckySum {
public:
    long long construct(string note) {
        ::note = note;
        genlucky(0);
        for(LL l: lucky) {
            genLuckySum(l);
        }
        return ans < LLONG_MAX ? ans : -1;
    }
    /*
     *long long construct(string note) {
     *    int N = note.size();
     *    int p = 0, n = 1;
     *    REP(i, 3) REP(j, 2) dp[n][i][j] = 1e18;
     *    dp[n][0][0] = 0;
     *    LL base = 1;
     *    PER(k, N) {
     *        swap(p, n);
     *        REP(i, 3) REP(j, 2) dp[n][i][j] = 1e18;
     *        REP(z, 3) {
     *            REP(carry, 2) {
     *                // dp[p][z][carry]
     *                for (int i: {0, 4, 7}) {
     *                    for (int j: {0, 4, 7}) {
     *                        if (z == 2) i = j = 0;
     *                        else if (z == 1) {
     *                            i = 0;
     *                        }
     *                        if (k == N-1 && (i == 0 || j == 0)) continue;
     *                        if (i == 0 && j == 0 && (k != 0 || carry == 0)) continue;
     *                        int d = i + j + carry;
     *                        if (note[k] == '?' || note[k] == '0' + (d % 10)) {
     *                            mini(dp[n][(!i)+(!j)][d/10], d%10*base + dp[p][z][carry]);
     *                        }
     *                    }
     *                }
     *            }
     *        }
     *        base *= 10;
     *    }
     *    LL ans = min(dp[n][2][0], min(dp[n][0][0], dp[n][1][0]));
     *    return ans < 1e17 ? ans : -1;
     *}
     */
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A lucky number is a positive integer such that each of its digits is a 4 or a 7.
A lucky sum is the sum of two (not necessarily distinct) lucky numbers.
Cat loves lucky sums!



Cat has a string note.
Each character in note is either a digit or a question mark.
A number matches note if it can be produced from note by changing each question mark to a single digit.
Note that the number produced this way must not have any leading zeros: after the changes, note[0] must be between '1' and '9', inclusive.



Find and return the smallest lucky sum that matches note.
If there are no lucky sums that match note, return -1.


DEFINITION
Class:LuckySum
Method:construct
Parameters:string
Returns:long long
Method signature:long long construct(string note)


CONSTRAINTS
-note will contain between 1 and 14 characters, inclusive.
-Each character of note will be either a digit ('0'-'9') or a question mark ('?').
-The first character of note will not be '0'.
-At least one character of note will be '?'.


EXAMPLES

0)
"?"

Returns: 8

4+4=8, which is the smallest lucky sum.

1)
"?1"

Returns: 11

4+7=11

2)
"4?8"

Returns: 448

4+444=448

3)
"2??"

Returns: -1

The numbers that match this note are the numbers 200 through 299. None of these numbers is a lucky sum.

4)
"??????????????"

Returns: 11888888888888



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
                cout << "Testing LuckySum (300.0 points)" << endl << endl;
                for (int i = 0; i < 20; i++)
                {
                        ostringstream s; s << argv[0] << " " << i;
                        int exitCode = system(s.str().c_str());
                        if (exitCode)
                                cout << "#" << i << ": Runtime Error" << endl;
                }
                int T = time(NULL)-1439292105;
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
                LuckySum _obj;
                long long _expected, _received;
                time_t _start = clock();
                switch (_tc)
                {
                        case 0:
                        {
                                string note = "?";
                                _expected = 8LL;
                                _received = _obj.construct(note); break;
                        }
                        case 1:
                        {
                                string note = "?1";
                                _expected = 11LL;
                                _received = _obj.construct(note); break;
                        }
                        case 2:
                        {
                                string note = "4?8";
                                _expected = 448LL;
                                _received = _obj.construct(note); break;
                        }
                        case 3:
                        {
                                string note = "2??";
                                _expected = -1LL;
                                _received = _obj.construct(note); break;
                        }
                        case 4:
                        {
                                string note = "??????????????";
                                _expected = 11888888888888LL;
                                _received = _obj.construct(note); break;
                        }
                        /*case 5:
                        {
                                string note = ;
                                _expected = LL;
                                _received = _obj.construct(note); break;
                        }*/
                        /*case 6:
                        {
                                string note = ;
                                _expected = LL;
                                _received = _obj.construct(note); break;
                        }*/
                        /*case 7:
                        {
                                string note = ;
                                _expected = LL;
                                _received = _obj.construct(note); break;
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
