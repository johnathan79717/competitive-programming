/*
ID: johnath2
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>

#define NAME "transform"

using namespace std;

int N;
char before[10][11], after[10][11];

typedef pair<int, int> pii;

pii transform(int type, int i, int j) {
  switch(type) {
    case 1: return pii(j, N-1-i);
    case 2: return pii(N-1-i, N-1-j);
    case 3: return pii(N-1-j, i);
    case 4: return pii(i, N-1-j);
    case 6: return pii(i, j);
  }
}

int solve() {
  for(int type = 1; type <= 4; type++) {
    bool same = true;
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++) {
        pii ij = transform(type, i, j);
        if(before[i][j] != after[ij.first][ij.second])
          same = false;
      }
    if(same)
      return type;
  }

  // reflect + rotate
  for(int type = 1; type <= 4; type++) {
    bool same = true;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        pii temp = transform(4, i, j);
        pii ij = transform(type, temp.first, temp.second);
        if(before[i][j] != after[ij.first][ij.second])
          same = false;        
      }
    }
    if(same)
      return type == 4 ? 6 : 5;
  }
  return 7;
}

int main() {
  ifstream fin (NAME".in");
  ofstream fout (NAME".out");
  // istream &fin = cin;
  // ostream &fout = cout;
  fin >> N;
  for(int i = 0; i < N; i++)
    fin >> before[i];
  for(int i = 0; i < N; i++)
    fin >> after[i];

  fout << solve() << endl;
  return 0;
}