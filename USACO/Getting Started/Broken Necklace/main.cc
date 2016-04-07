/*
ID: johnath2
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int N;
    fin >> N;
    char beads[352];
    fin >> beads;
    int ans = 0;

    for(int i = 0; i < N; i++) {
      char color = 'w';
      int length = 0;
      for(int j = 0; j < N; j++) {
        char &bead = beads[(i+j)%N];
        if(bead == 'w') {
          length++;
        } else if(color == 'w') {
          length++;
          color = bead;
        } else if(color == bead) {
          length++;
        } else {
          break;
        }
      }
      color = 'w';
      for(int j = 1; j <= N; j++) {
        char &bead = beads[(i-j+N)%N];
        if(bead == 'w') {
          length++;
        } else if(color == 'w') {
          length++;
          color = bead;
        } else if(color == bead) {
          length++;
        } else {
          break;
        }
      }
      ans = max(ans, length);
    }
    ans = min(ans, N);
    fout << ans << endl;
    return 0;
}