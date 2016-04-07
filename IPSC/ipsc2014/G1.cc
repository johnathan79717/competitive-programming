#include <cstdio>
#include <map>

using namespace std;

map<__int128, bool> mp;

bool win(__int128 t) {
  if(mp.count(t)) return mp[t];
  for(int i = 0; i < 100; i++) {
    if((t >> i) & 1) {
      if(!win((t ^ ((__int128)1 << i)) >> 1))
        return mp[t] = true;
    }
  }
  return mp[t] = false;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    scanf("%d", &n);
    char s[100002];
    scanf("%s", s);
    __int128 t = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == '1')
        t ^= ((__int128)1 << i);
    }
    if(win(t)) puts("Adam");
    else puts("Betka");
  }
  return 0;
}