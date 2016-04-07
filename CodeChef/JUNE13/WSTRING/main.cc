#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    char S[10001];
    scanf("%s", S);
    int L = strlen(S);
    int pawn = 0;
    int total[26];
    memset(total, 0, sizeof(total));
    for(int i = 0; i < L; ++i) {
      if(S[i] == '#')
        pawn++;
      else
        total[S[i] - 'a']++;
    }
    if(pawn < 3) {
      puts("0");
      continue;
    }

    int arr1[26], arr2[26], arr3[26];
    memset(arr1, 0, sizeof(arr1));
    memset(arr2, 0, sizeof(arr2));
    memset(arr3, 0, sizeof(arr3));
    int *freq1 = arr1, *freq2 = arr2, *freq3 = arr3;
    int ans = 0, i = 0;
    while(S[i] != '#') {
      freq1[S[i] - 'a']++;
      total[S[i] - 'a']--;
      i++;
    }
    // stop at the first #
    ++i;
    while(S[i] != '#') {
      freq2[S[i] - 'a']++;
      total[S[i] - 'a']--;
      i++;
    }
    // stop at the second #
    i++;
    while(S[i] != '#') {
      freq3[S[i] - 'a']++;
      total[S[i] - 'a']--;
      i++;
    }
    i++;
    for(int k = 0; k < pawn - 2; ++k) {
      // printf("freq1:");
      // for(int j = 0; j < 26; ++j)
      //   if(freq1[j] > 0) printf(" %c%d", 'a'+j, freq1[j]);
      // printf("\nfreq2:");
      // for(int j = 0; j < 26; ++j)
      //   if(freq2[j] > 0) printf(" %c%d", 'a'+j, freq2[j]);
      // printf("\nfreq3:");
      // for(int j = 0; j < 26; ++j)
      //   if(freq3[j] > 0) printf(" %c%d", 'a'+j, freq3[j]);
      // printf("\ntotal:");
      // for(int j = 0; j < 26; ++j)
      //   if(total[j] > 0) printf(" %c%d", 'a'+j, total[j]);
      // puts("");
      int k1 = *max_element(freq1, freq1 + 26);
      int k2 = *max_element(freq2, freq2 + 26);
      int k3 = *max_element(freq3, freq3 + 26);
      int k4 = *max_element(total, total + 26);
      if(k1 > 0 && k2 > 0 && k3 > 0 && k4 > 0)
        ans = max(ans, 3 + k1 + k2 + k3 + k4);
      // printf("%d %d %d %d\n", k1, k2, k3, k4);

      for(int j = 0; j < 26; ++j)
        freq1[j] += freq2[j];
      swap(freq2, freq3);
      memset(freq3, 0, 26*sizeof(int));
      // printf("i = %d\n", i);
      while(i < L && S[i] != '#') {
        freq3[S[i] - 'a']++;
        total[S[i] - 'a']--;
        i++;
      }
      i++;
    }
    printf("%d\n", ans);
  }
}