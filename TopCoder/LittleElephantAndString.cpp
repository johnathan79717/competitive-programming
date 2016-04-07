#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <queue>

using namespace std;

class LittleElephantAndString {
public:
	int getNumber(string A, string B) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    vector<int> position[26];
    for(int i = 0; i < A.size(); i++) {
      freq[A[i]-'A']++;
      position[A[i]-'A'].push_back(i);
      freq[B[i]-'A']--;
    }
    for(int i = 0; i < 26; i++)
      if(freq[i] != 0)
        return -1;

    int j = A.size() - 1;
    for(int ans = B.size() - 1; ans >= 0; ans--) {
      while(j >= 0 && A[j] != B[ans]) j--;
      if(j < 0) return ans + 1;
      j--;
    }
    return 0;
	}
};
