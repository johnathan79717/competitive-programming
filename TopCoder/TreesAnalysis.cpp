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
 
typedef long long LL;

struct TreesAnalysis {
  long long treeSimilarity(vector <int> tree1, vector <int> tree2) {

  }
};

// BEGIN CUT HERE
/*
PROBLEM STATEMENT

  Vasa has two undirected trees. Each of the trees has n 
vertices. In each tree, the vertices are labeled 0 through 
n-1, inclusive, in no particular order. The shapes of the 
trees may be different.



	You are given the description of the two trees as vector 
<int>s tree1 and tree2 with n-1 elements each. For each 
valid i, the vertices i and tree1[i] are connected by an 
edge in the first tree. Similarly, for each valid i, the 
vertices i and tree2[i] are connected by an edge in the 
second tree.



  Vasa tried to measure how similar the two trees are. He 
did so in two steps. First, he defined the value S(e1,e2): 
the similarity between the edge e1 in the first tree and 
the edge e2 in the second tree. Then, he defined the 
similarity between his two trees as the sum of sqr(S(e1,
e2)) over all pairs (e1,e2), where sqr(x)=x*x. The 
definition of S(e1,e2) follows.



	We will now define the similarity S(e1,e2). Consider the 
following process:


	If we were to remove the edge e1 from the first tree, it 
would split into two components. Choose one of them and 
call it A.
	If we were to remove the edge e2 from the second tree, it 
would split into two components. Choose one of them and 
call it B.
	Let X be the set of labels that are present both in A and 
in B.


	Then, the similarity S(e1,e2) is defined to be the 
largest possible size of the set X. (The maximum is taken 
over both choices of A and both choices of B.)



	Compute and return the similarity between the two given 
trees.



DEFINITION
Class:TreesAnalysis
Method:treeSimilarity
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long treeSimilarity(vector <int> 
tree1, vector <int> tree2)


NOTES
-An undirected graph is a tree if and only if between any 
two vertices of the graph there is exactly one simple path 
(i.e., one that never visits the same node twice).


CONSTRAINTS
-n will be between 2 and 4,000, inclusive.
-tree1 will contain n - 1 elements.
-tree1 and tree2 will contain the same number of elements.
-Each element of tree1 will be between 0 and n - 1, 
inclusive.
-Each element of tree2 will be between 0 and n - 1, 
inclusive.
-tree1 and tree2 will represent trees as described in the 
problem statement.


EXAMPLES

0)
{1}
{1}

Returns: 1

The similarity between the edge 0-1 in the first tree and 
the edge 0-1 in the second tree is 1. One corresponding 
set X is the set X = {0}.

1)
{2, 4, 1, 0}
{1, 4, 4, 4}

Returns: 111

Here the first tree is a path (edges 0-2, 1-4, 2-1, and 3-
0) and the second tree is not a path (edges 0-1, 1-4, 2-4, 
and 3-4). As each tree has four edges, their similarity is 
the sum of 4*4 = 16 terms.

For example, let's compute one of those 16 terms. The 
similarity between the edge e1 = 0-2 in the first tree and 
the edge e2 = 0-1 in the second tree is 3, as depicted in 
the figure below. Hence, this pair of edges contributes sqr
(3) = 3*3 = 9 towards the total similarity between these 
two trees.



2)
{1, 2, 3, 4}
{1, 2, 3, 4}


Returns: 128



3)
{2, 3, 4, 4, 5, 8, 5, 6, 10, 8}
{9, 0, 1, 0, 3, 0, 5, 0, 7, 10}

Returns: 6306



4)
{222, 261, 167, 133, 174, 150, 165, 311, 208, 268, 111, 
222, 154, 277, 282, 201, 46, 124, 194, 331, 4, 216, 111, 
275, 72, 322, 137, 216, 241, 48, 72, 101, 232, 165, 151, 
263, 139, 16, 122, 140, 84, 135, 314, 106, 309, 126, 102, 
151, 208, 27, 242, 93, 83, 314, 136, 77, 82, 215, 16, 232, 
286, 156, 294, 38, 67, 204, 206, 137, 174, 282, 188, 
143, 84, 279, 236, 136, 158, 10, 65, 332, 122, 44, 329, 
62, 174, 67, 102, 216, 245, 296, 287, 307, 93, 197, 169, 
268, 266, 294, 157, 277, 95, 68, 214, 135, 211, 127, 82, 
108, 212, 161, 243, 212, 207, 119, 119, 158, 97, 290, 21, 
217, 230, 85, 171, 13, 138, 294, 304, 204, 318, 115, 70, 
210, 195, 223, 37, 164, 149, 3, 164, 328, 316, 108, 330, 
48, 38, 324, 222, 193, 50, 41, 184, 93, 148, 41, 151, 139, 
106, 301, 264, 80, 249, 110, 244, 109, 212, 223, 279, 
330, 67, 27, 301, 165, 236, 194, 3, 157, 1, 217, 311, 87, 
105, 4, 286, 37, 6, 31, 111, 66, 230, 227, 244, 322, 
196, 65, 69, 305, 112, 133, 231, 68, 153, 206, 309, 248, 
329, 58, 69, 69, 328, 0, 29, 233, 243, 305, 167, 80, 65, 
194, 190, 179, 142, 196, 324, 206, 134, 50, 272, 261, 10, 
147, 329, 322, 14, 142, 169, 21, 296, 284, 241, 55, 304, 
150, 166, 230, 167, 304, 87, 156, 156, 97, 274, 324, 196, 
101, 82, 106, 260, 242, 233, 207, 305, 10, 166, 53, 18, 
154, 233, 217, 296, 263, 168, 138, 30, 115, 135, 188, 98, 
309, 292, 204, 150, 210, 332, 330, 166, 96, 70, 24, 229, 
215, 201, 285, 40, 287, 142, 68, 133, 208, 268, 161, 310, 
41, 203, 73, 275, 184, 163, 227, 89, 110, 328, 108, 112, 
125, 164, 127, 179, 267, 221, 49, 139, 1, 84, 136, 38, 6, 
70, 246, 243, 3, 188, 297}
{174, 262, 195, 288, 157, 278, 36, 133, 230, 273, 222, 
138, 97, 23, 189, 141, 296, 55, 45, 301, 81, 199, 188, 289, 
187, 164, 113, 58, 138, 300, 289, 282, 329, 91, 130, 178, 
92, 143, 48, 81, 311, 133, 151, 286, 171, 196, 199, 80, 
83, 121, 65, 151, 277, 136, 49, 111, 58, 36, 259, 14, 31, 
9, 136, 181, 122, 324, 249, 114, 9, 37, 259, 242, 165, 
174, 34, 36, 298, 92, 301, 237, 178, 82, 65, 295, 110, 
311, 274, 235, 68, 56, 259, 180, 195, 52, 110, 68, 140, 71, 
52, 296, 290, 115, 213, 82, 209, 209, 74, 178, 302, 131, 
99, 205, 296, 309, 288, 180, 329, 71, 143, 58, 152, 273, 
196, 7, 169, 88, 231, 331, 213, 181, 80, 249, 170, 246, 
16, 127, 75, 276, 332, 174, 21, 180, 163, 78, 242, 312, 
295, 199, 89, 142, 85, 195, 115, 119, 95, 94, 279, 290, 3, 
33, 93, 284, 20, 47, 47, 78, 331, 271, 113, 179, 249, 
331, 92, 324, 9, 71, 232, 46, 28, 289, 80, 28, 80, 134, 
20, 280, 277, 48, 205, 107, 52, 320, 4, 191, 160, 182, 
189, 227, 295, 115, 54, 195, 78, 292, 189, 273, 301, 69, 
305, 36, 222, 167, 326, 106, 48, 45, 74, 61, 181, 311, 
292, 270, 201, 34, 314, 218, 214, 92, 269, 18, 37, 151, 
142, 209, 11, 227, 327, 198, 28, 272, 152, 22, 47, 143, 
332, 253, 273, 35, 78, 130, 295, 223, 181, 329, 18, 238, 
300, 186, 274, 99, 300, 322, 41, 185, 311, 288, 198, 2, 
37, 83, 238, 133, 122, 178, 107, 106, 66, 238, 69, 90, 38, 
109, 246, 278, 288, 250, 321, 269, 130, 28, 115, 122, 
33, 185, 275, 99, 130, 99, 152, 268, 133, 249, 180, 30, 
210, 201, 324, 29, 290, 143, 3, 269, 68, 106, 230, 1, 
269, 29, 120, 259, 324, 328, 23, 243, 9, 61, 14, 118, 199, 
146, 237, 14}

Returns: 11478648052



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
		cout << "Testing TreesAnalysis (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1400599189;
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
		TreesAnalysis _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int tree1[] = {1};
				int tree2[] = {1};
				_expected = 1LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}
			case 1:
			{
				int tree1[] = {2, 4, 1, 0};
				int tree2[] = {1, 4, 4, 4};
				_expected = 111LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}
			case 2:
			{
				int tree1[] = {1, 2, 3, 4};
				int tree2[] = {1, 2, 3, 4};
				_expected = 128LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}
			case 3:
			{
				int tree1[] = {2, 3, 4, 4, 5, 8, 5, 6, 10, 8};
				int tree2[] = {9, 0, 1, 0, 3, 0, 5, 0, 7, 10};
				_expected = 6306LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}
			case 4:
			{
				int tree1[] = {222, 261, 167, 133, 174, 150, 165, 311, 208, 268, 111, 222, 154, 277, 282, 201, 46, 124, 194, 331, 4, 216, 111, 
				              275, 72, 322, 137, 216, 241, 48, 72, 101, 232, 165, 151, 263, 139, 16, 122, 140, 84, 135, 314, 106, 309, 126, 102, 
				              151, 208, 27, 242, 93, 83, 314, 136, 77, 82, 215, 16, 232, 286, 156, 294, 38, 67, 204, 206, 137, 174, 282, 188, 
				              143, 84, 279, 236, 136, 158, 10, 65, 332, 122, 44, 329, 62, 174, 67, 102, 216, 245, 296, 287, 307, 93, 197, 169, 
				              268, 266, 294, 157, 277, 95, 68, 214, 135, 211, 127, 82, 108, 212, 161, 243, 212, 207, 119, 119, 158, 97, 290, 21, 
				              217, 230, 85, 171, 13, 138, 294, 304, 204, 318, 115, 70, 210, 195, 223, 37, 164, 149, 3, 164, 328, 316, 108, 330, 
				              48, 38, 324, 222, 193, 50, 41, 184, 93, 148, 41, 151, 139, 106, 301, 264, 80, 249, 110, 244, 109, 212, 223, 279, 
				              330, 67, 27, 301, 165, 236, 194, 3, 157, 1, 217, 311, 87, 105, 4, 286, 37, 6, 31, 111, 66, 230, 227, 244, 322, 
				              196, 65, 69, 305, 112, 133, 231, 68, 153, 206, 309, 248, 329, 58, 69, 69, 328, 0, 29, 233, 243, 305, 167, 80, 65, 
				              194, 190, 179, 142, 196, 324, 206, 134, 50, 272, 261, 10, 147, 329, 322, 14, 142, 169, 21, 296, 284, 241, 55, 304, 
				              150, 166, 230, 167, 304, 87, 156, 156, 97, 274, 324, 196, 101, 82, 106, 260, 242, 233, 207, 305, 10, 166, 53, 18, 
				              154, 233, 217, 296, 263, 168, 138, 30, 115, 135, 188, 98, 309, 292, 204, 150, 210, 332, 330, 166, 96, 70, 24, 229, 
				              215, 201, 285, 40, 287, 142, 68, 133, 208, 268, 161, 310, 41, 203, 73, 275, 184, 163, 227, 89, 110, 328, 108, 112, 
				              125, 164, 127, 179, 267, 221, 49, 139, 1, 84, 136, 38, 6, 70, 246, 243, 3, 188, 297};
				int tree2[] = {174, 262, 195, 288, 157, 278, 36, 133, 230, 273, 222, 138, 97, 23, 189, 141, 296, 55, 45, 301, 81, 199, 188, 289, 
				              187, 164, 113, 58, 138, 300, 289, 282, 329, 91, 130, 178, 92, 143, 48, 81, 311, 133, 151, 286, 171, 196, 199, 80, 
				              83, 121, 65, 151, 277, 136, 49, 111, 58, 36, 259, 14, 31, 9, 136, 181, 122, 324, 249, 114, 9, 37, 259, 242, 165, 
				              174, 34, 36, 298, 92, 301, 237, 178, 82, 65, 295, 110, 311, 274, 235, 68, 56, 259, 180, 195, 52, 110, 68, 140, 71, 
				              52, 296, 290, 115, 213, 82, 209, 209, 74, 178, 302, 131, 99, 205, 296, 309, 288, 180, 329, 71, 143, 58, 152, 273, 
				              196, 7, 169, 88, 231, 331, 213, 181, 80, 249, 170, 246, 16, 127, 75, 276, 332, 174, 21, 180, 163, 78, 242, 312, 
				              295, 199, 89, 142, 85, 195, 115, 119, 95, 94, 279, 290, 3, 33, 93, 284, 20, 47, 47, 78, 331, 271, 113, 179, 249, 
				              331, 92, 324, 9, 71, 232, 46, 28, 289, 80, 28, 80, 134, 20, 280, 277, 48, 205, 107, 52, 320, 4, 191, 160, 182, 
				              189, 227, 295, 115, 54, 195, 78, 292, 189, 273, 301, 69, 305, 36, 222, 167, 326, 106, 48, 45, 74, 61, 181, 311, 
				              292, 270, 201, 34, 314, 218, 214, 92, 269, 18, 37, 151, 142, 209, 11, 227, 327, 198, 28, 272, 152, 22, 47, 143, 
				              332, 253, 273, 35, 78, 130, 295, 223, 181, 329, 18, 238, 300, 186, 274, 99, 300, 322, 41, 185, 311, 288, 198, 2, 
				              37, 83, 238, 133, 122, 178, 107, 106, 66, 238, 69, 90, 38, 109, 246, 278, 288, 250, 321, 269, 130, 28, 115, 122, 
				              33, 185, 275, 99, 130, 99, 152, 268, 133, 249, 180, 30, 210, 201, 324, 29, 290, 143, 3, 269, 68, 106, 230, 1, 
				              269, 29, 120, 259, 324, 328, 23, 243, 9, 61, 14, 118, 199, 146, 237, 14};
				_expected = 11478648052LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}
			/*case 5:
			{
				int tree1[] = ;
				int tree2[] = ;
				_expected = LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int tree1[] = ;
				int tree2[] = ;
				_expected = LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int tree1[] = ;
				int tree2[] = ;
				_expected = LL;
				_received = _obj.treeSimilarity(vector <int>(tree1, tree1+sizeof(tree1)/sizeof(int)), vector <int>(tree2, tree2+sizeof(tree2)/sizeof(int))); break;
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
