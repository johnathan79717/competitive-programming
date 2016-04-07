#include <stdio.h>
#include <string.h>

int main() {
    char input[1001][21];
    int prefix[1001];
    int collision[1001];
    int n = 0;
    scanf("%s\n", input[n]);
    while (strlen(input[n])) {
        scanf("%s", input[++n]);
    }
    int i, j;
    for (i = 0; i < n; ++i) {
        prefix[i] = 0;
        int finish = 0;
        for (j = 0; j < n; ++j) {
            if (j == i)
                continue;
            collision[j] = 1;
        }
        while (!finish && prefix[i] < strlen(input[i])) {
            finish = 1;
            for (j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                if (collision[j]) {
                    if (input[j][prefix[i]] == input[i][prefix[i]]) {
                        finish = 0;
                    }
                    else
                        collision[j] = 0;
                }
            }
            ++prefix[i];
        }
        printf("%s ", input[i]);
        for (j = 0; j < prefix[i]; ++j) {
            printf("%c", input[i][j]);
        }
        printf("\n");
    }
}

