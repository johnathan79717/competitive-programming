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
// #line 40 "GUMIAndSongsDiv2.cpp"
#include <string>
#include <vector>
class GUMIAndSongsDiv2 {
public:
    int maxSongs(vector <int> duration, vector <int> tone, int T) {
        int N = tone.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                vector<int> a;
                for (int k = 0; k < N; k++) {
                    if (tone[k] >= min(tone[i], tone[j]) && tone[k] <= max(tone[i], tone[j])) {
                        a.push_back(duration[k]);
                    }
                }
                sort(a.begin(), a.end());
                int t = abs(tone[j] - tone[i]);
                int c = 0;
                while (c < (int)a.size() && a[c] + t <= T) {
                    t += a[c];
                    c++;
                }
                ans = max(ans, c);
            }
        }
        return ans;
    }
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Gumi loves singing.
She knows N songs.
The songs are numbered 0 through N-1.
She now has some time and she would love to sing as many different songs as possible. 

You are given a vector <int> duration.
For each i, duration[i] is the duration of song i in Gumi's time units. 

Gumi finds it difficult to sing songs with quite different tones consecutively.
You are given a vector <int> tone with the following meaning:
If Gumi wants to sing song y immediately after song x, she will need to spend |tone[x]-tone[y]| units of time resting between the two songs.
(Here, || denotes absolute value.) 

You are also given an int T.
Gumi has T units of time for singing.
She can start singing any song she knows immediately at the beginning of this time interval.
Compute the maximal number of different songs she can sing completely within the given time.

DEFINITION
Class:GUMIAndSongsDiv2
Method:maxSongs
Parameters:vector <int>, vector <int>, int
Returns:int
Method signature:int maxSongs(vector <int> duration, vector <int> tone, int T)


CONSTRAINTS
-duration and tone will each contain between 1 and 15 elements, inclusive.
-duration and tone will contain the same number of elements.
-Each element of duration will be between 1 and 100,000, inclusive.
-Each element of tone will be between 1 and 100,000, inclusive.
-T will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
{3, 5, 4, 11}
{2, 1, 3, 1}
17

Returns: 3

There are four songs. 
Two songs have tone 1 and their durations are 5 and 11, respectively.
One song has tone 2 and its duration is 3.
One song has tone 3 and its duration is 4.
Gumi has 17 units of time to sing. 

It is impossible for Gumi to sing all four songs she knows within the given time: even without the breaks the total length of all songs exceeds 17. 

Here is one way how she can sing three songs:
First, she sings song 0 in 3 units of time.
Second, she waits for |2-3|=1 unit of time and then sings song 2 in 4 units of time.
Finally, she waits for |3-1|=2 units of time and then sings song 1 in 5 units of time.
The total time spent is 3+1+4+2+5 = 15 units of time.


1)
{100, 200, 300}
{1, 2, 3}
10

Returns: 0

In this case, T is so small that she can't sing at all.

2)
{1, 2, 3, 4}
{1, 1, 1, 1}
100

Returns: 4

There is plenty of time, so she can sing all 4 songs.


3)
{10, 10, 10}
{58, 58, 58}
30

Returns: 3



4)
{8, 11, 7, 15, 9, 16, 7, 9}
{3, 8, 5, 4, 2, 7, 4, 1}
14

Returns: 1



5)
{5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614}
{2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853}
302606

Returns: 8



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
		cout << "Testing GUMIAndSongsDiv2 (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1463322005;
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
		GUMIAndSongsDiv2 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int duration[] = {3, 5, 4, 11};
				int tone[] = {2, 1, 3, 1};
				int T = 17;
				_expected = 3;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 1:
			{
				int duration[] = {100, 200, 300};
				int tone[] = {1, 2, 3};
				int T = 10;
				_expected = 0;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 2:
			{
				int duration[] = {1, 2, 3, 4};
				int tone[] = {1, 1, 1, 1};
				int T = 100;
				_expected = 4;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 3:
			{
				int duration[] = {10, 10, 10};
				int tone[] = {58, 58, 58};
				int T = 30;
				_expected = 3;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 4:
			{
				int duration[] = {8, 11, 7, 15, 9, 16, 7, 9};
				int tone[] = {3, 8, 5, 4, 2, 7, 4, 1};
				int T = 14;
				_expected = 1;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			case 5:
			{
				int duration[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
				int tone[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
				int T = 302606;
				_expected = 8;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}
			/*case 6:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}*/
			/*case 7:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
			}*/
			/*case 8:
			{
				int duration[] = ;
				int tone[] = ;
				int T = ;
				_expected = ;
				_received = _obj.maxSongs(vector <int>(duration, duration+sizeof(duration)/sizeof(int)), vector <int>(tone, tone+sizeof(tone)/sizeof(int)), T); break;
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
