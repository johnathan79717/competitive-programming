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

template <class T>
T mul(T a,T b,T c){
  if(sizeof(T) <= 4) {
    ULL temp = ULL(a) * b;
    return temp % c;
  } else {
    __int128 temp = (__int128) a * b;
    return temp % c;
  }
  // T x = 0,y=a%c;
  // while(b > 0){
  //   if(b%2 == 1){
  //     x = (x+y)%c;
  //   }
  //   y = (y*2)%c;
  //   b /= 2;
  // }
  // return x%c;
}

template<class T>
T pow(T a, T b, T c){
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

template <class T>
bool isprime(T n)
{
  // 預先判斷偶數與1，節省一點時間。
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
 
  T u = n - 1, t = 0;
  while (u % 2 == 0) {u >>= 1; t++;}
 
  // 推定是質數，就實施下一次測試；
  // 確定是合數，就馬上結束。

  ULL witness[][7] = {
    {9345883071009581737ULL},
    {336781006125ULL, 9639812373923155ULL},
    {4230279247111683200ULL, 14694767155120705706ULL, 16641139526367750375ULL},
    {2, 141889084524735ULL, 1199124725622454117ULL, 11096072698276303650ULL},
    {2, 4130806001517ULL, 149795463772692060ULL, 186635894390467037ULL, 3967304179347715805ULL},
    {2, 123635709730000ULL, 9233062284813009ULL, 43835965440333360ULL, 761179012939631437ULL, 1263739024124850375ULL},
    {2, 325, 9375, 28178, 450775, 9780504, 1795265022}
  };
  ULL bound[] = {341531, 1050535501, 350269456337ULL, 55245642489451ULL, 7999252175582851ULL, 585226005592931977ULL};

  ULL *sprp;
  int test = 0;
  while(test < 6 && n > bound[test]) test++;
  sprp = witness[test];
  test++;
  for (int k=0; k<test; ++k)
  {
    // a沒有大於1、小於n-1的限制，
    // 沒有測試意義的數字，當作是通過測試。
    // （a是質數時，模n後不會等於零，不必特別判斷。）
    T a = sprp[k] % n;
    if (a == 0 || a == 1 || a == n-1) continue;
 
    T x = pow(a, u, n);
    if (x == 1 || x == n-1) continue;
 
    for (int i = 0; i < t-1; i++)
    {
      x = mul(x, x, n);
      if (x == 1) return false;
      if (x == n-1) break;
    }
    if (x == n-1) continue;
 
    return false;
  }
  // 通過全部測試，確定是質數。
  return true;
}

bool solve(LL N, LL K) {
  if(K == 1)
    return isprime(N);
  else if(K == 2 && N % 2 == 1)
    return isprime(N - 2);
  else
    return N >= 2 * K;
}

int main() {
  DRI(T);
  while(T--) {
    DRL(N);
    DRL(K);
    if(solve(N, K))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}