#include <stdlib.h>
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int t;
    for (t = 0; t < T; ++t) {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        x = x % 10;
        int table[10];
        table[0] = 1;
        int i;
        int j;
        int repeat = 0;
        for (i = 1; i < 10; ++i) {
            table[i] = ( table[i-1] * x ) % 10;
            for (j = 0; j < i; ++j) {
                if (table[j] == table[i]) {
                    repeat = 1;
                    break;
                }
            }
            if (repeat) break;
        }
        int head = j, tail = i, cycle = i-j;
        int round = 0;
        for (i = head; i < tail; ++i) {
            round += table[i];
        }
        int sum = 0;
        if (b == 0) {
            printf("%d\n", 1);
            return 0;
        }
        if (a == 0) {
            a = 1;
            sum += 1;
        }
        int first = (a-head) / cycle;
        int last = (b-head) / cycle;
        sum += (last - first + 1) * round;
        a = (a - head) % cycle + head;
        b = (b - head) % cycle + head;
        for (i = head; i < a; ++i)
            sum -= table[i];
        for (i = b + 1; i < tail; ++i)
            sum -= table[i];
        printf("%d\n", sum%10);
    }
    return 0;
}

