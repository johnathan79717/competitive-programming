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

class StonesGame {
public:
	string winner(int N, int M, int K, int L) {
    string p1("Romeo"), p2("Strangelet"), d("Draw");
		if(abs(M - L) < K)
      return p1;
    if(M < L) {
      if(M > K)
        return d;
      M = K + 1 - M;
      if(abs(M - L) < K)
        return p2;
      else
        return d;
    } else {
      if(M <= N - K)
        return d;
      M = N - K + 1 + N - M;
      if(abs(M - L) < K)
        return p2;
      else
        return d;
    }
	}
};
