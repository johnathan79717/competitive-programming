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

class BigFatInteger {
public:
	int minOperations(int A, int B) {
		bool isprime[1000000];
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    vector<int> power;
    int m = 0;
    for(int i = 2; i < 1000000; i++) {
      if(!isprime[i]) continue;
      int p = 0;
      while(A % i == 0) {
        p++;
        A /= i;
      }
      if(p > 0) {
        power.push_back(p * B);
        m = max(m, p * B);
      }
      for(int j = i + i; j < 1000000; j += i)
        isprime[j] = false;
    }
    for(int i : power)
      cout << i << endl;
    int ans = power.size();
    int b = 1;
    while(b < m) {
      b <<= 1;
      ans++;
    }
    return ans;
	}
};
