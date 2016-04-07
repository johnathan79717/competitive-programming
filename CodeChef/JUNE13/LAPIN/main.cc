#include <cstdio>
#include <cstring>

using namespace std;

bool solve() {
  char S[1001];
  scanf("%s", S);
  int L = strlen(S);
  int freq[26];
  memset(freq, 0, sizeof(freq));
  for(int i = 0; i < L / 2; ++i)
    freq[S[i] - 'a']++;
  for(int i = (L+1)/2; i < L; ++i)
    freq[S[i] - 'a']--;
  for(int i = 0; i < 26; ++i)
    if(freq[i]) return false;

  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    if(solve()) puts("YES");
    else puts("NO");
  }
}