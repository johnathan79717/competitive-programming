#include <iostream>

using namespace std;

char s[8][9];
int main() {
    int i, j;
    for(i=0;i<8;i++)for(j=0;j<8;j++)s[i][j]='.';

    char d = '.'^'X';
    int x, y;
    cin >> x >> y;
    while (x >= 0) {
        //for(i=0;i<8;i++) cout << s[i] << endl;
        for(i=0;i<8;i++) {
            s[x][i] ^= d;
            s[i][y] ^= d;
        }
        s[x][y] ^= d;
        cin >> x >> y;
    }
    for(i=0;i<8;i++) cout << s[i] << endl;
}
