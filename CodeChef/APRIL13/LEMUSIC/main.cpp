#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

long long B[100000], L[100000], shortL[100000];

typedef map<long long, long long> Songs;

void print(Songs &songs) {
  for(Songs::iterator it = songs.begin(); it != songs.end(); ++it)
    printf("%lld %lld\n", it->first, it->second);
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    Songs shortSongs;
    Songs::iterator it;
    int i, N;
    long long ans = 0;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
      scanf("%lld%lld", B + i, L + i);
      long long &l = shortSongs[B[i]];
      if(l == 0 || l > L[i])
        l = L[i];
    }
    i = 0;
    for(it = shortSongs.begin(); it != shortSongs.end(); ++it)
      shortL[i++] = it->second;
    long long numShortSongs = shortSongs.size();
    sort(shortL, shortL + numShortSongs);
    for(i = 0; i < numShortSongs; ++i)
      ans += shortL[i] * (i + 1);
    for(i = 0; i < N; ++i) {
      it = shortSongs.find(B[i]);
      if(it != shortSongs.end() && it->second == L[i])
        shortSongs.erase(it);
      else
        ans += L[i] * numShortSongs;
    }
    printf("%lld\n", ans);
  }
}