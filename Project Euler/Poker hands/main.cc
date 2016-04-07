#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>
using namespace std;

enum Rank {
  HighCard, OnePair, TwoPair, ThreeOfAKind, Straight,
  Flush, FullHouse, FourOfAKind, StraightFlush, RoyalFlush
};

Rank getHand(vector<int> &high) {
  char card[3];
  bool flush = true;
  char suit = 0;
  int freq[15];
  int hand[5];
  memset(freq, 0, sizeof(freq));
  for(int i = 0; i < 5; i++) {
    cin >> card;
    switch(card[0]) {
      case 'A': hand[i] = 14; break;
      case 'K': hand[i] = 13; break;
      case 'Q': hand[i] = 12; break;
      case 'J': hand[i] = 11; break;
      case 'T': hand[i] = 10; break;
      default: hand[i] = card[0] - '0'; break;
    }
    freq[hand[i]]++;
    if(!suit)
      suit = card[1];
    else {
      if(suit != card[1])
        flush = false;
    }
  }
  sort(hand, hand + 5, greater<int>());
  int four = 0, three = 0, pair1 = 0, pair2 = 0;
  
  for(int i = 14; i >= 2; i--) {
    switch(freq[i]) {
      case 4: four = i; break;
      case 3: three = i; break;
      case 2: if(!pair1) pair1 = i; else pair2 = i; break;
    }
  }

  if(four) {
    high.push_back(four);
    for(int i = 0; i < 5; i++)
      if(hand[i] != four)
        high.push_back(hand[i]);
    return FourOfAKind;
  }

  if(three) {
    if(pair1) {
      high.push_back(three);
      high.push_back(pair1);
      return FullHouse;
    } else {
      high.push_back(three);
      for(int i = 0; i < 5; i++)
        if(hand[i] != three)
          high.push_back(hand[i]);
      return ThreeOfAKind;
    }
  }

  if(pair1) {
    if(pair2) {
      high.push_back(pair1);
      high.push_back(pair2);
      for(int i = 0; i < 5; i++)
        if(hand[i] != pair1 && hand[i] != pair2)
          high.push_back(hand[i]);
      return TwoPair;
    } else {
      high.push_back(pair1);
      for(int i = 0; i < 5; i++)
        if(hand[i] != pair1)
          high.push_back(hand[i]);
      return OnePair;
    }
  }

  assert(!pair1);
  if(hand[0] - hand[4] == 4 || (hand[0] == 14 && hand[1] == 5)) {
    // Straight
    if(hand[0] == 14 && hand[1] == 5)
      high.push_back(5);
    else
      high.push_back(hand[0]);
    if(flush) {
      if(high[0] == 14)
        return RoyalFlush;
      else
        return StraightFlush;
    } else {
      return Straight;
    }
  }

  for(int i = 0; i < 5; i++)
    high.push_back(hand[i]);

  if(flush) {
    return Flush;
  } else {
    return HighCard;
  }
}

bool win(Rank rank1, vector<int> &high1, Rank rank2, vector<int> &high2) {
  if(rank1 > rank2)
    return true;
  else if(rank1 < rank2)
    return false;
  else {
    for(int i = 0; i < high1.size(); i++) {
      if(high1[i] < high2[i])
        return false;
      if(high1[i] > high2[i]) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  int ans = 0;
    int N;
    cin >> N;
  for(int line = 1; line <= N; line++) {
    vector<int> high1, high2;
    Rank rank1 = getHand(high1);
    Rank rank2 = getHand(high2);

//    cout << line << ": " << endl;
    if(win(rank1, high1, rank2, high2)) {
      ans++;
      cout << "Player 1" << endl;
    } else cout << "Player 2" << endl;
/*    
    cout << "Player 1: " << rank1 << endl;
    for(int a : high1)
      cout << a << ' ';
    cout << endl;
    cout << "Player 2: " << rank2 << endl;
    for(int a : high2)
      cout << a << ' ';
    cout << endl;
*/
    // Rank r = Straight;
    // if(rank1 == r || rank2 == r)
    //   cout << line << endl;

  }
//  cout << ans << endl;
}