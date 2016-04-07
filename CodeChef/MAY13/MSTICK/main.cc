#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// Segment Tree Library
// The segment tree is stored like a heap array
#define RANGE_SUM 0
#define RANGE_MIN 1
#define RANGE_MAX 2

class SegmentTree {
 public:
  SegmentTree(int c, int *A, int n) : code(c), A(A), N(n) {
    init_segment_tree();
    build_segment_tree(1, 0, N-1);
  }
  int query(int i, int j) {
    return query(1, 0, N-1, i, j);
  }

 private:
  vector<int> segment_tree;
  int code;
  int *A;
  int N;
  void init_segment_tree() { // if original array size is N,
    // the required segment_tree array length is 2*2^(floor(log2(N)) + 1);
    int length = (int)(2 * pow(2.0, floor((log((double)N) / log(2.0)) + 1)));
    segment_tree.resize(length, 0); // resize this vector and fill with 0
  }

  void build_segment_tree(int node, int b, int e) {
    if (b == e) { // as b == e, either one is fine
      if (code == RANGE_SUM)
        segment_tree[node] = A[b]; // store value of this cell
      else
        segment_tree[node] = b; // if RANGE_MIN/MAXIMUM, store index
    }
    else { // recursively compute the values in the left and right subtrees
      int leftIdx = 2 * node, rightIdx = 2 * node + 1;
      build_segment_tree(leftIdx , b , (b + e) / 2);
      build_segment_tree(rightIdx, (b + e) / 2 + 1, e );
      int lContent = segment_tree[leftIdx], rContent = segment_tree[rightIdx];
      if (code == RANGE_SUM) // make this segment contains sum of left and right subtree
        segment_tree[node] = lContent + rContent;
      else { // (code == RANGE_MIN/MAXIMUM)
        int lValue = A[lContent], rValue = A[rContent];
        if (code == RANGE_MIN)
          segment_tree[node] = (lValue <= rValue) ? lContent : rContent;
        else
          segment_tree[node] = (lValue >= rValue) ? lContent : rContent;
      }
    }
  }

  int query(int node, int b, int e, int i, int j) { 
    if (i > e || j < b) return -1; // if the current interval does not intersect query interval
    if (b >= i && e <= j) return segment_tree[node]; // if the current interval is inside query interval

    // compute the minimum position in the left and right part of the interval
    int p1 = query(2 * node , b, (b + e) / 2, i, j);
    int p2 = query(2 * node + 1, (b + e) / 2 + 1, e , i, j);

    // return the position where the overall minimum is
    if (p1 == -1) return p2; // can happen if we try to access segment outside query
    if (p2 == -1) return p1; // same as above

    if (code == RANGE_SUM)
      return p1 + p2;
    else if (code == RANGE_MIN)
      return (A[p1] <= A[p2]) ? p1 : p2;
    else
      return (A[p1] >= A[p2]) ? p1 : p2;
  }
};

int main() {
  int N;
  cin >> N;
  int b[100000];
  for(int i = 0; i < N; ++i)
    cin >> b[i];
  SegmentTree min_st(RANGE_MIN, b, N);
  SegmentTree max_st(RANGE_MAX, b, N);
  int Q;
  cin >> Q;
  while(Q--) {
    int L, R;
    cin >> L >> R;
    double inside_min = b[min_st.query(L, R)];
    double left_max, right_max;
    if(L == 0)
      left_max = 0;
    else
      left_max = b[max_st.query(0, L-1)];
    if(R == N-1)
      right_max = 0;
    else
      right_max = b[max_st.query(R+1, N-1)];
    double inside_max = b[max_st.query(L, R)];
    printf("%.1f\n", inside_min + max(max(left_max, right_max), (inside_max - inside_min) / 2));
  }
}