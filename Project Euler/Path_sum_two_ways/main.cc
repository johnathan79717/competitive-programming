#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int matrix[80][80];
  for(int i = 0; i < 80; i++)
    for(int j = 0; j < 80; j++)
      cin >> matrix[i][j];
  for(int i = 1; i < 80; i++) {
    matrix[i][0] += matrix[i-1][0];
    matrix[0][i] += matrix[0][i-1];
  }
  for(int i = 1; i < 80; i++)
    for(int j = 1; j < 80; j++)
      matrix[i][j] += min(matrix[i-1][j], matrix[i][j-1]);
  cout << matrix[79][79] << endl;
}