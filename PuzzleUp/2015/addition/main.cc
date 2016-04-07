#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
char a[11];
int main() {
    for (int i = 0; i < 10; i++) {
        a[i] = '0' + i;
    }
    int aa, bb, cc = 0;
    do {
        for (int l1 = 1; l1 <= 3; l1++) {
            for (int l2 = l1; l2 <= 10-l1-l2; l2++) {
                string A(a, l1), B(a+l1, l2), C(a+l1+l2);
                int a, b, c;
                sscanf(A.c_str(), "%d", &a);
                sscanf(B.c_str(), "%d", &b);
                sscanf(C.c_str(), "%d", &c);
                if (a + b == c) {
                    if (c >= cc) {
                      printf("%d + %d = %d\n", a, b, c);
                      aa = a;
                      bb = b;
                      cc = c;
                    } 
                }
            }
        }
    } while (next_permutation(a, a+10));

}
