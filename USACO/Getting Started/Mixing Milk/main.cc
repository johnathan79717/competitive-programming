/*
ID: johnath2
PROG: milk
LANG: C++
*/
#ifdef STDIO
#include <iostream>
#endif

#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#define NAME "milk"

using namespace std;

#ifndef STDIO
  ifstream cin (NAME".in");
  ofstream cout (NAME".out");
#endif

int main() {
  int totalMilk, numFarmers;
  cin >> totalMilk >> numFarmers;
  vector<pair<int, int> > farmer; // first: price, second: amount
  while(numFarmers--) {
    int price, amount;
    cin >> price >> amount;
    farmer.push_back(make_pair(price, amount));
  }
  sort(farmer.begin(), farmer.end());
  int i = 0, totalPrice = 0;
  while(totalMilk > 0) {
    totalPrice += farmer[i].first * min(farmer[i].second, totalMilk);
    totalMilk -= farmer[i].second;
    i++;
  }
  cout << totalPrice << endl;
  return 0;
}