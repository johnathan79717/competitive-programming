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

class WolfDelaymaster {
public:
	string check(string str) {
    int n = 0;
    string valid("VALID");
    string invalid("INVALID");
    int i = 0;
		while(i < str.size()) {
      if(str[i] == 'w') {
        ++n;
        ++i;
      } else {
        if(n == 0)
          return invalid;
        for(int j = 0; j < n; ++j)
          if(i == str.size() || str[i++] != 'o')
            return invalid;
        for(int j = 0; j < n; ++j)
          if(i == str.size() || str[i++] != 'l')
            return invalid;
        for(int j = 0; j < n; ++j)
          if(i == str.size() || str[i++] != 'f')
            return invalid;
        n = 0;
      }
    }
    if(n == 0)
      return valid;
    else
      return invalid;
	}
};
