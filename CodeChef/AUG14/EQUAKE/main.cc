#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;
#define BG begin()
#define ED end()
#define FOR(i,c) for(auto &i: c)
#define SZ size()
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define RL(x) scanf("%lld",&x)
#define DRI(x) int x;RI(x)
#define DRL(x) LL x;RL(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PL(x) printf("%lld\n",x)
#define PIS(x) printf("%d ",x)
#define MP make_pair
#define PB push_back
#define PQ priority_queue
#define E emplace
#define EB emplace_back
#define LB lower_bound
#define UB upper_bound
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#define V(x) vector<x >

typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000;

#define MAX 1600000

int arr[MAX];
int tree[MAX][12];
int lazy[MAX];

int rotate(int a, int l) {
  if(a < 10) return a;
  if(a < 100) {
    if(l % 2) return (a%10)*10 + a/10;
    else return a;
  }
  if(a < 1000) {
    if(l % 3 == 1) return (a%100)*10 + a/100;
    if(l % 3 == 2) return (a%10)*100 + a/10;
    else return a;
  }
  if(l % 4 == 1) return (a%1000)*10 + a/1000;
  if(l % 4 == 2) return (a%100)*100 + a/100;
  if(l % 4 == 3) return (a%10)*1000 + a/10;
  else return a;
}

void build_tree(int node, int a, int b) {
  // PI(node);
  if(a > b) return; // Out of range
  if(a == b) { // Leaf node
    REP(i, 12)
      tree[node][i] = rotate(arr[a], i); // Init value
    return;
  }
  build_tree(node*2, a, (a+b)/2); // Init left child
  build_tree(node*2+1, 1+(a+b)/2, b); // Init right child
  REP(i, 12)
    tree[node][i] = max(tree[node*2][i], tree[node*2+1][i]); // Init root value
}

void rotate(int a[12], int l) {
  int temp[12];
  REP(i, 12) temp[i] = a[i];
  REP(i, 12-l) a[i] = temp[i+l];
  REP1(i, 12-l, 11) a[i] = temp[i+l-12];
}

/**
* Increment elements within range [i, j] with value value
*/
void update_tree(int node, int a, int b, int i, int j, int value) {
  PI(node);
  if(lazy[node] != 0) { // This node needs to be updated
    // tree[node] += lazy[node]; // Update it
    rotate(tree[node], lazy[node]);
    if(a != b) {
      lazy[node*2] += lazy[node]; // Mark child as lazy
      lazy[node*2+1] += lazy[node]; // Mark child as lazy
      if(lazy[node*2] >= 12) lazy[node*2] -= 12;
      if(lazy[node*2+1] >= 12) lazy[node*2+1] -= 12;
    }
   
    lazy[node] = 0; // Reset it
  }
  if(a > b) return;
  if(a > j || b < i) // Current segment is not within range [i, j]
    return;
  if(a >= i && b <= j) { // Segment is fully within range
    // tree[node] += value;
    rotate(tree[node], value);
    if(a != b) { // Not leaf node
      lazy[node*2] += value;
      lazy[node*2+1] += value;
      if(lazy[node*2] >= 12) lazy[node*2] -= 12;
      if(lazy[node*2+1] >= 12) lazy[node*2+1] -= 12;
    }
 
    return;
  }
 
  update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
  REP(i, 12)
    tree[node][i] = max(tree[node*2][i], tree[node*2+1][i]); // Updating root with max value
}
 
/**
* Query tree to get max element value within range [i, j]
*/
int query_tree(int node, int a, int b, int i, int j) {
  if(a > b || a > j || b < i) return 0; // Out of range
 
  if(lazy[node] != 0) { // This node needs to be updated
    // tree[node] += lazy[node]; // Update it
    rotate(tree[node], lazy[node]); 
    if(a != b) {
      lazy[node*2] += lazy[node]; // Mark child as lazy
      lazy[node*2+1] += lazy[node]; // Mark child as lazy
      if(lazy[node*2] >= 12) lazy[node*2] -= 12;
      if(lazy[node*2+1] >= 12) lazy[node*2+1] -= 12;
    }
   
    lazy[node] = 0; // Reset it
  }
 
  if(a >= i && b <= j) // Current segment is totally within range [i, j]
    return tree[node][0];
 
  int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
  int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child
 
  int res = max(q1, q2); // Return final result
  return res;
}

int main() {
  DRI(N);
  REP(i, N) {
    RI(arr[i]);
    // arr[i] = 1;
  }
  build_tree(1, 0, N-1);
  DRI(M);
  while(M--) {
    DRI(t);
    if(t == 0) {
      DRIII(L, R, F);
      F %= 12;
      if(F)
        update_tree(1, 0, N-1, L, R, F);
    } else {
      DRII(L, R);
      PI(query_tree(1, 0, N-1, L, R));
    }
  }
  return 0;
}
