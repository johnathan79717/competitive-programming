#include <iostream>
#include <string>
using namespace std;

string ops;

int op(int a, int b) {
  if(ops[0] == 'X')
    return a ^ b;
  else if(ops[0] == 'A')
    return a & b;
  else
    return a | b;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int N, K, Answer;
    cin >> N >> K >> Answer;
    int A[1000];
    for(int i = 0; i < N; i++)
      cin >> A[i];
    cin >> ops;
    if(K == 0 || ops[0] == 'X' && K % 2 == 0)
      cout << Answer << endl;
    else {
      int val = A[0];
      for(int i = 1; i < N; i++)
        val = op(val, A[i]);
      cout << op(Answer, val) << endl;
    }
  }
}