/*
ID: johnath2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

#define NAME "milk2"

using namespace std;

int event[1000000];

int main() {
  memset(event, 0, sizeof(event));
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");
  // istream &fin = cin;
  // ostream &fout = cout;
  int N;
  fin >> N;
  int endTime = 0, startTime = 1e6;
  // fout << N << endl;
  while(N--) {
    int start, end;
    fin >> start >> end;
    event[start]++;
    event[end]--;
    startTime = min(startTime, start);
    endTime = max(endTime, end);
  }
  // fout << startTime << ' ' << endTime << endl;
  int numCows = 0, maxMilk = 0, maxIdle = 0, currMilk = 0, currIdle = 0;
  for(int i = startTime; i < endTime; i++) {
    numCows += event[i];
    if(numCows) {
      maxMilk = max(maxMilk, ++currMilk);
      currIdle = 0;
    } else {
      maxIdle = max(maxIdle, ++currIdle);
      currMilk = 0;
    }
  }

  fout << maxMilk << ' ' << maxIdle << endl;

  return 0;
}