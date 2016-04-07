/*
ID: johnath2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int N;
    fin >> N;
    map<string, int> account;
    string *name = new string[N];
    for(int i = 0; i < N; ++i) {
      fin >> name[i];
      account[name[i]] = 0;
    }
    for(int i = 0; i < N; ++i) {
      string giver;
      int money, n;
      fin >> giver >> money >> n;
      if(n == 0) continue;
      account[giver] -= (money - money % n);
      money /= n;
      for(int j = 0; j < n; ++j) {
        string receiver;
        fin >> receiver;
        account[receiver] += money;
      }
      // for(int i = 0; i < N; ++i)
      //   cout << name[i] << ' ' << account[name[i]] << endl;
    }
    for(int i = 0; i < N; ++i)
      fout << name[i] << ' ' << account[name[i]] << endl;
    return 0;
}