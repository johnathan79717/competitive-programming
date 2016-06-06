#include <message.h>
#include "majority.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;


int main() {
  // Local
  {
    ll k = -1, n = 0;
    for (ll i = MyNodeId(); i < GetN(); i += NumberOfNodes()) {
      ll x = GetVote(i);
      if (x == k) {
        ++n;
      } else {
        if (n == 0) {
          k = x;
          n = 1;
        } else {
          --n;
        }
      }
    }

    cerr << k << ' ' << n << endl;
    PutLL(0, k);
    PutLL(0, n);
    Send(0);
  }

  // Merge, candidate generation, and resubmit
  if (MyNodeId() == 0) {
    ll k = -1, n = 0;
    for (int i = 0; i < NumberOfNodes(); ++i) {
      Receive(i);
      ll tk = GetLL(i);
      ll tn = GetLL(i);

      if (k == tk) {
        n += tn;
      } else {
        n -= tn;
        if (n < 0) {
          k = tk;
          n = -n;
        }
      }
    }

    for (int i = 0; i < NumberOfNodes(); ++i) {
      PutLL(i, k);
      Send(i);
    }
  }

  // Count and confirm
  {
    Receive(0);
    ll k = GetLL(0), n = 0;
    // printf("k = %lld\n", k);
    for (ll i = MyNodeId(); i < GetN(); i += NumberOfNodes()) {
      ll x = GetVote(i);
      if (x == k) ++n;
    }
    PutLL(0, n);
    Send(0);

    if (MyNodeId() == 0) {
      ll n = 0;
      for (int i = 0; i < NumberOfNodes(); ++i) {
        Receive(i);
        n += GetLL(i);
      }

      if (n * 2 > GetN()) printf("%lld\n", k);
      else puts("NO WINNER");
    }
  }

  return 0;
}
