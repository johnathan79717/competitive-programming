#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

typedef unsigned long long ULL;

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
  int test = 3;
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

#define MAX_P 15000000
vector<int> primes;
bool p[MAX_P];

void Eratosthenes() {
  memset(p, true, sizeof p);
  for(int i = 2; i < MAX_P; i++)
    if(p[i]) {
      primes.push_back(i);
      if((ll)i*i < MAX_P) 
        for(int j = i*i; j < MAX_P; j+=i)
          p[j] = false;
    }
}

int main() {
  Eratosthenes();
  vector<ll> cum(primes.size() + 1);
  cum[0] = 0;
  for(int i = 0; i < primes.size(); i++) {
    cum[i+1] = cum[i] + primes[i];
  }  
  cerr << "start" << endl;
  // for(int l = 1; l < cum.size();l++) {
  int T;
  cin >> T;
  while(T--) {
    long long N;
    cin >> N;
    for(int l = cum.size(); l >= 1; l--) {
      bool success = false;
      for(int i = l; i < cum.size(); i++) {
        ll p = cum[i] - cum[i-l];
        if(p > N) break;
        if(isprime(p)) {
          cout << p << ' ' << l << '\n';
          success = true;
          break;
        }
      }
      if(success) {
        break;
      }
    }
  }
  // int T;
  // cin >> T;
  // while(T--) {
  //   int N;
  //   cin >> N;
    // int l = 1;
    // ll s;
    // for(int i = 0; i < cum.size(); i++) {
    //   for(int j = i-l; j >= 0; j--) {
    //     ll p = cum[i] - cum[j];
    //     if(p >= N)
    //       break;
    //     if(isprime(p)) {
    //       l = i - j;
    //       s = p;
    //     }
    //   }
    // }
  //   cout << s << ' ' << l << endl;
  // }
}