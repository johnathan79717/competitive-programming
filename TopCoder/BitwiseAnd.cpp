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

class BitwiseAnd {
public:
	vector<long long> lexSmallest(vector<long long> subset, int N) {
    vector<long long> empty;
    for(int i = 0; i < subset.size(); i++)
      for(int j = 0; j < subset.size(); j++)
        if(!(subset[i] & subset[j]))
          return empty;

    vector<vector<int> > v(subset.size());
    int freq[60];
    memset(freq, 0, sizeof(freq));
    for(int i = 0; i < subset.size(); i++)
      for(int j = 0; j < 60; j++) {
        if(subset[i] & (1ll<<j)) {
          cout << i << ' ' << j << endl;
          v[i].push_back(j);
          freq[j]++;
        }
      }

    for(int i = 0; i < 60; i++)
      if(freq[i] > 2)
        return empty;


    N -= subset.size();
    // cout << "N: " << N << endl;
    for(int k = 0; k < N; k++) {
      long long n = 0;
      for(int i = 0; i < subset.size(); i++) {
        int j;
        for(j = 0; j < v[i].size(); j++) {
          if(freq[v[i][j]] == 1)
            break;
        }
        if(j == v[i].size())
          return empty;
        else {
          n |= (1ll<<v[i][j]);
          freq[v[i][j]] = 2;
        }
      }
      cout << "n: " << n << endl;
      for(int i = 0; i < N - k - 1; i++) {
        int j;
        for(j = 0; j < 60; j++)
          if(freq[j] == 0)
            break;
        if(j == 60)
          return empty;
        else {
          cout << "j: " << j << endl;
          n |= (1ll<<j);
          freq[j] = 1;
        }
      }
      cout << "n: " << n << endl;

      subset.push_back(n);
      v.push_back(vector<int>());
      for(int j = 0; j < 60; j++) {
        if(n & (1ll<<j)) {
          // cout << i << ' ' << j << endl;
          v.back().push_back(j);
          // freq[j]++;x`
        }
      }

      cout << "k: " << k << ", n: " << n << endl;
    }
    sort(subset.begin(), subset.end());
    return subset;
	}
};
