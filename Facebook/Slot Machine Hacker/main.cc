#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 100
#define MAX_S 10000001

int seq[MAX_N];
int N;

int getRandomNumber(int &secret) {
  secret = (secret * 5402147ll + 54321) % 10000001;
  return secret % 1000;
}

void solve() {
  vector<int> v[2];
  for(int i = seq[0]; i < MAX_S; i += 1000)
    v[0].push_back(i);
  for(int i = 1; i < N; i++) {
    vector<int> &next = v[i%2];
    vector<int> &prev = v[1-i%2];
    next.clear();
    for(int j = 0; j < prev.size(); j++) {
      if(getRandomNumber(prev[j]) == seq[i])
        next.push_back(prev[j]);
    }
  }
  vector<int> &final = v[1-N%2];
  switch(final.size()) {
    case 0: cout << "Wrong machine" << endl; return;
    case 1: {
      for(int i = 0; i < 9; i++)
        cout << getRandomNumber(final[0]) << ' ';
      cout << getRandomNumber(final[0]) << endl;
    } return;
    default: cout << "Not enough observations" << endl; return;
  }

}

int main() {
  int T;
  cin >> T;
  while(T--) {
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> seq[i];
    solve();
  }
}