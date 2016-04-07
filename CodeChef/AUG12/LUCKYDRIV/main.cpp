#include <cstdio>
#include <cstring>

#define M 1000000007

inline long long c2(long long n) {
  return n*(n-1)/2;
}

inline long long c3(long long n) {
  return n*(n-1)*(n-2)/6;
}

inline long long c4(long long n) {
  return n*(n-1)*(n-2)*(n-3)/24;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char S[10001];
    scanf("%s", S);
    int L = strlen(S), i, j;
    long long t[10], ans = 0;
    memset(t, 0, sizeof(t));
    for(int i = 0; i < L; ++i) 
      ++t[S[i]-'0'];

    for(int i = 1; i <= 9; ++i) {
      if(i % 9 == 0) ans += (t[i] + c2(t[i]) + c4(t[i])) % M;
      if(i % 3 == 0) ans += c3(t[i]);
      for(int j = 0; j < i; ++j) {
        if((3*i + j) % 9 == 0)
          ans += (c3(t[i]) * t[j]) % M;
        if((i + 3*j) % 9 == 0)
          ans += (t[i] * c3(t[j])) % M;
        if((2*i + j) % 9 == 0)
          ans += (c2(t[i]) * t[j]) % M;
        if((i + 2*j) % 9 == 0)
          ans += (t[i] * c2(t[j])) % M;
        if((i + j) % 9 == 0)
          ans += ( t[i] * t[j] + c2(t[i]) * c2(t[j]) ) % M;
        for(int k = 0; k < j; ++k) {
          if((i + j + k) % 9 == 0)
            ans += (t[i] * t[j] * t[k]) % M;
          if((2*i + j + k) % 9 == 0)
            ans += (c2(t[i]) * t[j] * t[k]) % M;
          if((i + 2*j + k) % 9 == 0)
            ans += (t[i] * c2(t[j]) * t[k]) % M;
          if((i + j + 2*k) % 9 == 0)
            ans += (t[i] * t[j] * c2(t[k])) % M;
          for(int l = 0; l < k; ++l)
            if((i + j + k + l) % 9 == 0)
              ans += (t[i] * t[j] * t[k] * t[l]) % M;
        }
      }
    }

    printf("%lld\n", ans % M);
  }
}