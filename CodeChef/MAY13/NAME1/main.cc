#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char name[200000];
    int freq[256];
    memset(freq, 0, sizeof(freq));
    scanf("%s", name);
    for(int i = 0; name[i]; ++i)
      ++freq[name[i]];
    scanf("%s", name);
    for(int i = 0; name[i]; ++i)
      ++freq[name[i]];
    int N;
    scanf("%d", &N);
    while(N--) {
      scanf("%s", name);
      for(int i = 0; name[i]; ++i)
        --freq[name[i]];
    }
    if(*min_element(freq, freq + 256) >= 0)
      puts("YES");
    else
      puts("NO");
  }
}