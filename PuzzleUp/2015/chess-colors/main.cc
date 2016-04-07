#include <iostream>
using namespace std;
int B[64][65];
int get(int i, int j) {
    return i * 8 + j;
}
void print() {
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 65; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
}
int main() {
    int r = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                B[r][get(i, k)] = B[r][get(k, j)] = 1;
            }
            B[r][64] = r%2;
            r++;
        }
    }
    cout << "Before:" << endl;
    print();
    int N = 64;
    int row = 0;
    for(int i = 0; i < N; i++) {
      int pivot = -1;
      for(int j = row; j < N; j++)
        if (B[j][i]) {
          pivot = j;
          break;
        }
      if (pivot < 0) continue;
      swap(B[row], B[pivot]);
      //for(int j = N-1; j >= i; j--)
        //B[row][j] /= B[row][i];
      for(int j = 0; j < N; j++)
        if(row != j)
          for(int k = N; k >= i; k--)
            B[j][k] ^= B[j][i] * B[row][k];
      row++;
      cout << i << ":" << endl;
      print();
    }
    cout << "After:" << endl;
    print();
}
