#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char **argv) {
  int p = atoi(argv[1]);
  int ans = 0;
  for(int r = 1; r <= 10000; r++)
    for(int s = 1; s <= 10000; s++)
      if(p*(r+s+p) % (r*s) == 0)
        ans++;

  cout << ans << endl;
}