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
#define MP make_pair
#define V(T) vector<T >
#define F first
#define S second
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

struct SimilarRatingGraph {
  double maxLength(vector <int> date, vector <int> rating) {
  	int N = date.size()-1;
  	vector<pair<LL, LL>> ratio(N);
  	vector<double> len(N);
  	REP(i, N) {
  		ratio[i] = MP(date[i+1] - date[i], rating[i+1] - rating[i]);
  		len[i] = sqrt(ratio[i].F * ratio[i].F + ratio[i].S * ratio[i].S);
  	}
  	double ans = 0;
  	REP(i, N) {
  		REP(j, i) {
  			int k = 0;
  			double l1 = 0, l2 = 0;
  			while (k < min(N-i, N-j) && ratio[i+k].F * ratio[j+k].S == ratio[i+k].S * ratio[j+k].F
  				&& ratio[i+k].F * ratio[j].F == ratio[j+k].F * ratio[i].F) {
  				l1 += len[i+k];
  				l2 += len[j+k];
  				k++;
  			}
  			ans = max(ans, max(l1, l2));
  		}
  	}
  	return ans;
  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

Recently, I realized that a rating graph can have two 
different intervals that look quite similar. Write a 
program that would detect such intervals.



You're given a user's rating graph in two vector <int>s: 
date and rating. Suppose that a user has participated in N 
contests; for 0 <= i < N, the i-th contest has timestamp 
date[i] and the user's rating after this contest was rating
[i].



Formally, the rating graph is a sequence of points (date
[i],rating[i]); an interval of the rating graph is a 
contiguous subsequence of those points - i.e., a 
subsequence corresponding to a contiguous range of 
indices. Two intervals are similar if one can be obtained 
from the other only by translation and scaling by a 
positive real factor (zooming). Note that both dimensions 
must be scaled by the same factor.



Consider the polyline obtained by visiting the points of 
an interval of the rating graph in order. The total length 
of this polyline is called the length of that interval.



Find the longest interval I of the given rating graph 
that's similar to some other (possibly partially 
overlapping) interval of that same rating graph and return 
the length of I.


DEFINITION
Class:SimilarRatingGraph
Method:maxLength
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double maxLength(vector <int> date, 
vector <int> rating)


CONSTRAINTS
-date and rating will contain the same number of elements.
-date will contain between 2 and 400 elements, inclusive.
-Each element of date will be between 1 and 1,000,000, 
inclusive.
-The elements of date will be in strictly increasing order.
-Each element of rating will be between 1 and 5,000, 
inclusive. 


EXAMPLES

0)
{1,2,4,8,16,32}
{1,2,4,8,16,32}

Returns: 42.42640687119285

The longest interval that's similar to another interval 
has length 30*sqrt(2) and is formed by points (2,2), 
(4,4), ..., (32,32). It's similar to the interval formed 
by points (1,1), (2,2), ..., (16,16).

1)
{81,104,120,124,134,137}
{1866,2332,2510,2678,2876,3002}

Returns: 168.04761230080004



2)
{10,11,13,15,19}
{10,14,15,23,25}

Returns: 12.7183472062349



3)
{1,2,3,4}
{1700,1800,1750,1850}

Returns: 100.00499987500625



4)
{1,2,3,4}
{1,4,9,16}

Returns: 0.0

Here, only an interval consisting of a single point can be 
similar to another interval. The length of such an 
interval is obviously 0.

5)
{5,11,25,58,92,162,255,350,458,566,677,792,919,1051,1189,1331,1489,1673,1882,2093,2315,2541,2771,3012,3254,3524,3797,4087,4379,4675,4973,5278,5588,5904,6225,6550,6888,7249,7612,8018,8428,8847,9267,9688,10109,10530,10964,11407,11870,12340,12811,13288,13768,14249,14734,15242,15774,16306,16847,17400,17966,18533,19108,19692,20278,20871,21471,22074,22679,23297,23916,24553,25190,25829,26472,27135,27814,28497,29181,29865,30555,31272,31994,32729,33487,34246,35005,35764,36537,37326,38119,38913,39725,40538,41360,42185,43010,43840,44671,45509,46350,47205,48063,48932,49807,50691,51577,52464,53289,54119,54950,55788,56629,57484,58342,59211,60086,60970,61856,62743,63568,64398,65388}

{1505,1462,1436,1416,1463,1421,1411,1450,1497,1465,1423,1394,1391,1367,1358,1323,1310,1279,1268,1279,1311,1342,1359,1387,1414,1376,1424,1382,1373,1335,1359,1318,1275,1266,1227,1203,1168,1163,1184,1144,1169,1207,1250,1235,1209,1162,1124,1148,1168,1202,1190,1155,1179,1194,1195,1195,1203,1240,1218,1245,1220,1190,1208,1180,1182,1148,1139,1126,1152,1159,1147,1158,1112,1091,1101,1116,1123,1086,1126,1110,1128,1085,1132,1145,1135,1140,1117,1081,1120,1131,1081,1032,1071,1102,1071,1065,1068,1027,980,947,987,968,959,980,990,974,1003,996,999,958,911,878,918,899,890,911,921,905,934,927,930,889,844}


Returns: 11940.179271014536



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
		cout << "Testing SimilarRatingGraph (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1412438403;
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
		SimilarRatingGraph _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int date[] = {1,2,4,8,16,32};
				int rating[] = {1,2,4,8,16,32};
				_expected = 42.42640687119285;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 1:
			{
				int date[] = {81,104,120,124,134,137};
				int rating[] = {1866,2332,2510,2678,2876,3002};
				_expected = 168.04761230080004;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 2:
			{
				int date[] = {10,11,13,15,19};
				int rating[] = {10,14,15,23,25};
				_expected = 12.7183472062349;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 3:
			{
				int date[] = {1,2,3,4};
				int rating[] = {1700,1800,1750,1850};
				_expected = 100.00499987500625;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 4:
			{
				int date[] = {1,2,3,4};
				int rating[] = {1,4,9,16};
				_expected = 0.0;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 5:
			{
				int date[] = {5,11,25,58,92,162,255,350,458,566,677,792,919,1051,1189,1331,1489,1673,1882,2093,2315,2541,2771,3012,3254,3524,3797,4087,4379,4675,4973,5278,5588,5904,6225,6550,6888,7249,7612,8018,8428,8847,9267,9688,10109,10530,10964,11407,11870,12340,12811,13288,13768,14249,14734,15242,15774,16306,16847,17400,17966,18533,19108,19692,20278,20871,21471,22074,22679,23297,23916,24553,25190,25829,26472,27135,27814,28497,29181,29865,30555,31272,31994,32729,33487,34246,35005,35764,36537,37326,38119,38913,39725,40538,41360,42185,43010,43840,44671,45509,46350,47205,48063,48932,49807,50691,51577,52464,53289,54119,54950,55788,56629,57484,58342,59211,60086,60970,61856,62743,63568,64398,65388};
				int rating[] = {1505,1462,1436,1416,1463,1421,1411,1450,1497,1465,1423,1394,1391,1367,1358,1323,1310,1279,1268,1279,1311,1342,1359,1387,1414,1376,1424,1382,1373,1335,1359,1318,1275,1266,1227,1203,1168,1163,1184,1144,1169,1207,1250,1235,1209,1162,1124,1148,1168,1202,1190,1155,1179,1194,1195,1195,1203,1240,1218,1245,1220,1190,1208,1180,1182,1148,1139,1126,1152,1159,1147,1158,1112,1091,1101,1116,1123,1086,1126,1110,1128,1085,1132,1145,1135,1140,1117,1081,1120,1131,1081,1032,1071,1102,1071,1065,1068,1027,980,947,987,968,959,980,990,974,1003,996,999,958,911,878,918,899,890,911,921,905,934,927,930,889,844};
				_expected = 11940.179271014536;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			case 6:
			{
				int date[] = {1, 500000, 999999};
				int rating[] = {42, 42, 42};
				_expected = ;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}
			/*case 7:
			{
				int date[] = ;
				int rating[] = ;
				_expected = ;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int date[] = ;
				int rating[] = ;
				_expected = ;
				_received = _obj.maxLength(vector <int>(date, date+sizeof(date)/sizeof(int)), vector <int>(rating, rating+sizeof(rating)/sizeof(int))); break;
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
