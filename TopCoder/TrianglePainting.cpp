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

class TrianglePainting {
	public:
	double expectedArea(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> prob) {
		
	}
};
// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
Cat Noku has a list of N paintbrushes to use for his next masterpiece.
The paintbrushes are labeled from 0 to N-1, and are described by the vector <int>s x1,y1,x2,y2.
Each paintbrush is a nondegenerate triangle.
The vertices of paintbrush i have coordinates (0,0), (x1[i],y1[i]), (x2[i],y2[i]).



Noku will go through his paintbrushes from 0 to N-1 and he will use the vector <int> prob to help him paint his masterpiece.
Initially his masterpiece is a single point.
He repeats the following procedure for each paintbrush.

 He chooses to use paintbrush i with probability prob[i] / 100. 
 If he chooses to use the paintbrush i, he will place the brush (without rotating it) so that the point (0,0) of the paintbrush will lie somewhere on the boundary of his current masterpiece. 
 He will then make a stroke with the paintbrush.
During the stroke, the brush will move (again, without any rotation) around the entire boundary of the current masterpiece in such a way that the point (0,0) of the paintbrush always lies on the boundary of the current masterpiece.
The region painted by the stroke is added to the masterpiece. 




Compute and return the expected area of Noku's final masterpiece.



DEFINITION
Class:TrianglePainting
Method:expectedArea
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double expectedArea(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, vector <int> prob)


NOTES
-Your return value must have an absolute or relative error smaller than or equal to 1e-6.


CONSTRAINTS
-N will be between 1 and 2,500, inclusive.
-x1,y1,x2,y2,prob will each have exactly N elements.
-Each element of x1,y1,x2,y2 will be between -100 and 100, inclusive.
-Each triangle will have a positive area.
-Each element of prob will be between 1 and 100, inclusive.


EXAMPLES

0)
{1,-2,-4}
{2,3,-1}
{2,2,-2}
{-1,-1,1}
{100,100,100}

Returns: 52.5


Cat Noku has the following paintbrushes:





All the paintbrushes will be used. The final masterpiece will look as follows:





Note that in the drawing of the final masterpiece each color represents just the area added to the masterpiece after using the brush of the corresponding color, and not the area actually painted by that brush.


1)
{1,-2,-4}
{2,3,-1}
{2,2,-2}
{-1,-1,1}
{50,50,50}

Returns: 15.0



2)
{1}
{1}
{1}
{-1}
{1}

Returns: 0.01



3)
{1,1,1,1,1,1,1,1,1,1}
{-1,1,-1,1,-1,1,-1,1,-1,1}
{1,1,1,1,1,1,1,1,1,1}
{1,-1,1,-1,1,-1,1,-1,1,-1}
{10,20,30,40,50,60,70,80,90,100}

Returns: 31.899999999999995



4)
{-6,-2,-10,9,8,-1,10,5,7,3}
{-5,2,-5,6,6,-10,8,7,-4,-5}
{5,-1,-1,-8,6,7,10,-6,6,3}
{0,-5,-7,4,10,0,10,-3,-3,-4}
{71,100,43,59,51,41,11,53,3,27}

Returns: 940.1964999999999



5)
{34,-71,19,78,69,-73,27,64,-100,70,-87,50,8,-97,46,-46,-30,-40,-30,-23,77,81,48,93,-40,70,
37,-66,53,-87,-85,38,-90,63,-16,24,-2,-60,-88,67,-56,-8,-80,-19,-84,35,95,-24,-26,-15}
{58,-24,-80,33,-98,61,99,79,-34,29,-1,-70,70,90,43,25,-50,-54,73,18,36,8,41,3,26,-6,-80,
-22,65,33,-100,-1,80,-19,-6,-8,-4,-86,-43,-34,0,-93,-61,92,74,-77,32,-78,-56,-21}
{-78,-100,-1,27,67,-31,-82,-24,44,-26,12,36,-36,-71,-84,3,59,28,-26,-79,-47,56,-75,-44,
-85,-72,56,53,-27,53,-19,-65,14,62,96,-44,12,-20,-57,83,59,71,85,-62,21,24,-38,20,52,-64}
{90,-41,79,18,7,-85,-88,-16,12,38,-7,12,-27,-43,-30,-93,48,-19,58,54,70,73,81,89,-35,-75,
63,-73,66,-90,-25,44,-53,59,-14,83,18,-35,-81,49,-11,-63,-87,-92,-83,-43,60,-42,5,-96}
{9,61,1,16,78,4,12,1,17,4,30,28,13,6,4,14,11,6,55,9,66,5,14,8,
70,3,2,6,3,15,8,1,2,12,1,20,37,1,3,66,3,11,2,1,21,2,1,1,27,11}

Returns: 306025.109



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
		cout << "Testing TrianglePainting (950.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1433073603;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 950.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TrianglePainting _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x1[] = {1,-2,-4};
				int y1[] = {2,3,-1};
				int x2[] = {2,2,-2};
				int y2[] = {-1,-1,1};
				int prob[] = {100,100,100};
				_expected = 52.5;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			case 1:
			{
				int x1[] = {1,-2,-4};
				int y1[] = {2,3,-1};
				int x2[] = {2,2,-2};
				int y2[] = {-1,-1,1};
				int prob[] = {50,50,50};
				_expected = 15.0;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			case 2:
			{
				int x1[] = {1};
				int y1[] = {1};
				int x2[] = {1};
				int y2[] = {-1};
				int prob[] = {1};
				_expected = 0.01;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			case 3:
			{
				int x1[] = {1,1,1,1,1,1,1,1,1,1};
				int y1[] = {-1,1,-1,1,-1,1,-1,1,-1,1};
				int x2[] = {1,1,1,1,1,1,1,1,1,1};
				int y2[] = {1,-1,1,-1,1,-1,1,-1,1,-1};
				int prob[] = {10,20,30,40,50,60,70,80,90,100};
				_expected = 31.899999999999995;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			case 4:
			{
				int x1[] = {-6,-2,-10,9,8,-1,10,5,7,3};
				int y1[] = {-5,2,-5,6,6,-10,8,7,-4,-5};
				int x2[] = {5,-1,-1,-8,6,7,10,-6,6,3};
				int y2[] = {0,-5,-7,4,10,0,10,-3,-3,-4};
				int prob[] = {71,100,43,59,51,41,11,53,3,27};
				_expected = 940.1964999999999;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			case 5:
			{
				int x1[] = {34,-71,19,78,69,-73,27,64,-100,70,-87,50,8,-97,46,-46,-30,-40,-30,-23,77,81,48,93,-40,70,
				           37,-66,53,-87,-85,38,-90,63,-16,24,-2,-60,-88,67,-56,-8,-80,-19,-84,35,95,-24,-26,-15};
				int y1[] = {58,-24,-80,33,-98,61,99,79,-34,29,-1,-70,70,90,43,25,-50,-54,73,18,36,8,41,3,26,-6,-80,
				           -22,65,33,-100,-1,80,-19,-6,-8,-4,-86,-43,-34,0,-93,-61,92,74,-77,32,-78,-56,-21};
				int x2[] = {-78,-100,-1,27,67,-31,-82,-24,44,-26,12,36,-36,-71,-84,3,59,28,-26,-79,-47,56,-75,-44,
				           -85,-72,56,53,-27,53,-19,-65,14,62,96,-44,12,-20,-57,83,59,71,85,-62,21,24,-38,20,52,-64};
				int y2[] = {90,-41,79,18,7,-85,-88,-16,12,38,-7,12,-27,-43,-30,-93,48,-19,58,54,70,73,81,89,-35,-75,
				           63,-73,66,-90,-25,44,-53,59,-14,83,18,-35,-81,49,-11,-63,-87,-92,-83,-43,60,-42,5,-96};
				int prob[] = {9,61,1,16,78,4,12,1,17,4,30,28,13,6,4,14,11,6,55,9,66,5,14,8,
				             70,3,2,6,3,15,8,1,2,12,1,20,37,1,3,66,3,11,2,1,21,2,1,1,27,11};
				_expected = 306025.109;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}
			/*case 6:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int prob[] = ;
				_expected = ;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int prob[] = ;
				_expected = ;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int x1[] = ;
				int y1[] = ;
				int x2[] = ;
				int y2[] = ;
				int prob[] = ;
				_expected = ;
				_received = _obj.expectedArea(vector <int>(x1, x1+sizeof(x1)/sizeof(int)), vector <int>(y1, y1+sizeof(y1)/sizeof(int)), vector <int>(x2, x2+sizeof(x2)/sizeof(int)), vector <int>(y2, y2+sizeof(y2)/sizeof(int)), vector <int>(prob, prob+sizeof(prob)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
