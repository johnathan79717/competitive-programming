#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  char tmp[5];
  gets(tmp);
  int T = atoi(tmp);
  while(T--) {
    char freqSeq[27], text[150001];
    gets(freqSeq);
    gets(text);
    int freq[26];
    memset(freq, 0, sizeof(freq));
    for(int i = 0; text[i]; i++) {
      if('a' <= text[i] && text[i] <= 'z')
        freq[text[i] - 'a']++;
      else if('A' <= text[i] && text[i] <= 'Z')
        freq[text[i] - 'A']++;
    }
    vector<pair<int, int> > v;
    for(int i = 0; i < 26; i++)
      v.push_back(make_pair(freq[i], i));
    sort(v.begin(), v.end());
    char map[26];
    for(int i = 0; i < 26; i++)
      map[v[i].second] = freqSeq[i];
    for(int i = 0; text[i]; i++) {
      if('a' <= text[i] && text[i] <= 'z')
        text[i] = map[text[i] - 'a'];
      else if('A' <= text[i] && text[i] <= 'Z')
        text[i] = map[text[i] - 'A'] - 'a' + 'A';
    }
    puts(text);
  }
}