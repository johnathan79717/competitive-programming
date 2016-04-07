#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char subs(char a, char b) {
    if (a != '0' && b != '0') return '0';
    if (a != '1' && b != '1') return '1';
    return '2';
}

void solve() {
    int K;
    char S[105];
    scanf("%d%s", &K, S);
    int L = strlen(S);
    if (L == 1) {
        if (S[0] == '?') S[0] = '0';
        puts(S);
        return;
    }
    if (K == 1) { // L>=2
        puts("NO");
        return;
    }
    if (K == 2) {
        if (L % 2) {
            puts("NO");
            return;
        }
        int zero = -1;
        int one = -1;
        for (int i = 0; i < L; ++i) {
            if (S[i] == '0') {
                if (one == i%2) {
                    puts("NO");
                    return;
                }
                zero = i%2;
                one = 1-zero;
            }
            else if (S[i] == '1') {
                if (zero == i%2) {
                    puts("NO");
                    return;
                }
                one = i%2;
                zero = 1-one;
            }
        }
        if (one == 0) {
            for (int i = 0; i < L; ++i)
                printf("%d", 1-i%2);
        }
        else {
            for (int i = 0; i < L; ++i)
                printf("%d", i%2);
        }
        puts("");
        return;
    }
    if (S[0] == '?') S[0] = subs(S[1], S[L-1]);
    for (int i = 1; i < L-1; ++i)
        if (S[i] == '?') S[i] = subs(S[i-1], S[i+1]);
    if (S[L-1] == '?') S[L-1] = subs(S[0], S[L-2]);
    if (S[0] == S[L-1]) {
        puts("NO");
        return;
    }
    for (int i = 1; i < L; ++i)
        if (S[i] == S[i-1]) {
            puts("NO");
            return;
        }
    puts(S);
//     // k >= 3
//     int i;
//     for (i = 0; i < L; ++i) if (S[i] != '?') break;
//     // cout << "i " << i << endl;
//     if (i == L) {
//         for (i = 0; i < L-1; ++i)
//             printf("%d", i%2);
//         if (L%2) puts("2");
//         else puts("1");
//         return;
//     }
//     for (int j = i+1; j < L-1; ++j) {
//         if (S[j] == '?') S[j] = subs(S[j-1], S[j+1]);
//         else if (S[j] == S[j-1]) {
//             puts("NO");
//             return;
//         }
//     }
//     if (S[L-1] == '?') S[L-1] = subs(S[L-2], S[0]);
//     else if (S[L-1] == S[L-2]) {
//         puts("NO");
//         return;
//     }
//     if (S[0] == '?') S[0] = subs(S[1], S[L-1]);
//     else if (S[0] == S[L-1]) {
//         puts("NO");
//         return;
//     }
//     for (int j = 1; j < i; ++j) {
//         if (S[j] == '?') S[j] = subs(S[j-1], S[j+1]);
//         else if (S[j] == S[j-1]) {
//             puts("NO");
//             return;
//         }
//     }
//     if (i > 0 && S[i] == S[i-1]) {
//         puts("NO");
//         return;
//     }
//     puts(S);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}