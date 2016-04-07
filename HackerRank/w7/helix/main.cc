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
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;
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
const int INF = 2000000000;

struct Node {
  Node *left, *right;
  Node *parent;
  int number, size;
  bool reversed;
  Node() : left( 0 ), right( 0 ), parent( 0 ) { }
  void refresh() {
    size = 1;
    if(left) size += left->size;
    if(right) size += right->size;
  }
  void reverse() {
    if(reversed) {
      reversed = false;
      swap(left, right);
      if(left) left->reversed = !left->reversed;
      if(right) right->reversed = !right->reversed;
    }
  }
} *root;

void right_rotate(Node*);

void left_rotate( Node *x ) {
  Node *y = x->right;
  // assert(!x->reversed && !y->reversed);
  x->right = y->left;
  if( y->left ) y->left->parent = x;
  y->parent = x->parent;
  if( !x->parent ) root = y;
  else if( x == x->parent->left ) x->parent->left = y;
  else x->parent->right = y;
  y->left = x;
  x->parent = y;
  // x must be refreshed first
  x->refresh();
  y->refresh();
  // assert(x->size == 1 + (x->left ? x->left->size : 0) + (x->right ? x->right->size : 0));
}

void right_rotate( Node *x ) {
  Node *y = x->left;
  // assert(!x->reversed && !y->reversed);
  x->left = y->right;
  if( y->right ) y->right->parent = x;
  y->parent = x->parent;
  if( !x->parent ) root = y;
  else if( x == x->parent->left ) x->parent->left = y;
  else x->parent->right = y;
  y->right = x;
  x->parent = y;
  // x must be refreshed first
  x->refresh();
  y->refresh();
  // assert(x->size == 1 + (x->left ? x->left->size : 0) + (x->right ? x->right->size : 0));
}
 
void splay( Node *x, bool childOfRoot = false ) {
  while( x->parent && !(childOfRoot && x->parent == root)) {
    if(x->parent->parent)
      x->parent->parent->reverse();
    x->parent->reverse();
    x->reverse();
    if( !x->parent->parent || (childOfRoot && x->parent->parent == root)) {
      if( x->parent->left == x ) right_rotate( x->parent );
      else left_rotate( x->parent );
    } else if( x->parent->left == x && x->parent->parent->left == x->parent ) {
      right_rotate( x->parent->parent );
      right_rotate( x->parent );
    } else if( x->parent->right == x && x->parent->parent->right == x->parent ) {
      left_rotate( x->parent->parent );
      left_rotate( x->parent );
    } else if( x->parent->left == x && x->parent->parent->right == x->parent ) {
      right_rotate( x->parent );
      left_rotate( x->parent );
    } else {
      left_rotate( x->parent );
      right_rotate( x->parent );
    }
  }
  // assert(x == root);
}

Node* nodes;
Node* init(Node* parent, int l, int r) {
  if(l > r) return NULL;
  int m = (l + r) / 2;
  nodes[m].left = init(nodes + m, l, m-1);
  nodes[m].right = init(nodes + m, m+1, r);
  nodes[m].parent = parent;
  nodes[m].number = m;
  nodes[m].size = r - l + 1;
  return nodes + m;
}

void find(int A, bool childOfRoot = false) {
  Node *p = root;
  while(true) {
    if(p->reversed) p->reverse();
    if(p -> left) {
      if(A > p->left->size + 1) {
        A -= p->left->size + 1;
        p = p->right;
      } else if(A <= p->left->size) {
        p = p->left;
      } else {
        break;
      }
    } else if(A == 1) {
      break;
    } else {
      A--;
      p = p->right;
    }
  }
  splay(p, childOfRoot);
  return;
}

int main() {
  DRII(N, Q);
  nodes = new Node[N+1];
  root = init(NULL, 1, N);
  while(Q--) {
    DRI(t);
    switch(t) {
      case 1: {
        DRII(A, B);
        Node *segment;
        if(A > 1) {
          find(A-1);
          if(B == N)
            segment = root->right;
          else {
            find(B+1, true);
            // if(root->left->left && root->left->left->size != A-2) {
            //   root->left->reverse();
            //   root->left->left->reverse();
            //   right_rotate(root->left);
            // }
            // assert(!root->left->left || root->left->left->size == A-2);
            // segment = root->left->right;
            segment = root->right->left;
          }
        } else {
          if(B == N)
            segment = root;
          else {
            find(B+1);
            segment = root->left;
          }
        }
        segment->reversed = !segment->reversed;
        break;
      }
      case 2: {
        DRI(A);
        splay(nodes + A);
        printf("element %d is at position %d\n", A, root->left ? root->left->size + 1 : 1);
        break;
      }
      case 3: {
        DRI(A);
        find(A);
        printf("element at position %d is %d\n", A, root->number);
        break;
      }
      default: assert(false);
    }
  }
  delete[] nodes;
  return 0;
}