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

class PrimalUnlicensedCreatures {
public:
	int maxWins(int initialLevel, vector <int> grezPower) {
		sort(grezPower.begin(), grezPower.end());
    int i;
    for(i = 0; i < grezPower.size(); ++i) {
      if(initialLevel > grezPower[i])
        initialLevel += grezPower[i] / 2;
      else
        break;
    }
    return i;
	}
};
