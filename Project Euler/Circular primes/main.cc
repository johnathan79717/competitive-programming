#include <iostream>
using namespace std;

typedef long long ll;

ll mul(ll a,ll b,ll c){
  ll x = 0,y=a%c;
  while(b > 0){
    if(b%2 == 1){
      x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
  }
  return x%c;
}

ll mul(ll a, ll b, int c) {
  return (a%c) * (b%c) % c;
}

int mul(int a, int b, int c) {
  ll temp = ll(a) * b;
  return temp % c;
}

template<class T>
T pow(T a, T b, T c){
  ll x=1,y=a; // ll is taken to avoid overflow of intermediate results
  while(b > 0){
    if(b%2 == 1){
      x=mul(x, y, c);
    }
    y = mul(y, y, c); // squaring the base
    b /= 2;
  }
  return x%c;
}

template<class T>
bool isprime(T n)
{
  // 預先判斷偶數與1，節省一點時間。
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
 
  T u = n - 1, t = 0;
  while (u % 2 == 0) {u >>= 1; t++;}
 
  // 推定是質數，就實施下一次測試；
  // 確定是合數，就馬上結束。

  T sprpl[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
  T sprpi[] = {2, 7, 61};

  T *sprp;
  int test;
  if(sizeof(T) > 4) {
    sprp = sprpl;
    test = 7;
  }
  else {
    sprp = sprpi;
    test = 3;
  }



  for (int k=0; k<test; ++k)
  {
    // a沒有大於1、小於n-1的限制，
    // 沒有測試意義的數字，當作是通過測試。
    // （a是質數時，模n後不會等於零，不必特別判斷。）
    T a = sprp[k] % n;
    if (a == 0 || a == 1 || a == n-1) continue;
 
    ll x = pow(a, u, n);
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

bool is_prime[1000000];

int rotate(int n) {
  int p = 1;
  while(10*p <= n)
    p *= 10;
  return n / 10 + n % 10 * p;
}

bool circular(int n) {
  if(!is_prime[n])
    return false;
  // cout << n << endl;
  int m = rotate(n);
  while(m != n) {
    if(!is_prime[m])
      return false;
    m = rotate(m);
  }
  return true;
}

int main() {
  int N;
  cin >> N;
  for(int i = 0; i < N; ++i)
    is_prime[i] = isprime(i);
  int ans = 0;
  for(int i = 0; i < N; ++i)
    if(circular(i)) {
      // ++ans;
      // cout << i << endl;
      ans += i;
    }
  cout << ans << endl;
}