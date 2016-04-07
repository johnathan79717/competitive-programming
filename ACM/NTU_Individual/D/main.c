#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char killed[2000][16];
int ksize;

int alive(char* p) {
    int i;
    for (i = 0; i < ksize; ++i) {
        if (strcmp(killed[i], p) == 0)
            return 0;
    }
    return 1;
}

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        char name1[1000][16];
        char name2[1000][16];
        int time1[1000];
        int time2[1000];
        int size1 = 0, size2 = 0;
        int time = 40;
        char line[16];
        scanf("%s", line);
        while(strcmp(line, "-") != 0) {
            time += strlen(line);
            time1[size1] = time;
            strcpy(name1[size1], line);
            ++size1;
            scanf("%s", line);
        }
        time = 40;
        scanf("%s", line);
        while(strcmp(line, "-") != 0) {
            time += strlen(line);
            time2[size2] = time;
            strcpy(name2[size2], line);
            ++size2;
            scanf("%s", line);
        }
        ksize = 0;
        int i = 0, j = 0;
        while (i < size1 && j < size2) {
            if (time1[i] < time2[j]) {
                if (alive(name1[i])) {
                    strcpy(killed[ksize++], name1[i]);
                    printf("%s %d\n", name1[i], time1[i]);
                    ++i;
                }
            }
            else if (time1[i] > time2[j]) {
                if (alive(name2[j])) {
                    strcpy(killed[ksize++], name2[j]);
                    printf("%s %d\n", name2[j], time2[j]);
                    ++j;
                }
            }
            else if (time1[i] == time2[j]) {
                if (strcmp(name1[i], name2[j]) < 0) {
                    if (alive(name1[i])) {
                        strcpy(killed[ksize++], name1[i]);
                        printf("%s %d\n", name1[i], time1[i]);
                    }
                    if (alive(name2[j])) {
                        strcpy(killed[ksize++], name2[j]);
                        printf("%s %d\n", name2[j], time2[j]);
                    }
                }
                else if (strcmp(name1[i], name2[j]) > 0) {
                    if (alive(name2[j])) {
                        strcpy(killed[ksize++], name2[j]);
                        printf("%s %d\n", name2[j], time2[j]);
                    }
                    if (alive(name1[i])) {
                        strcpy(killed[ksize++], name1[i]);
                        printf("%s %d\n", name1[i], time1[i]);
                    }
                }
                ++i;
                ++j;
            }
        }
        while (i < size1) {
            if (alive(name1[i])) {
                strcpy(killed[ksize++], name1[i]);
                printf("%s %d\n", name1[i], time1[i]);
            }
            ++i;
        }
        while (j < size2) {
            if (alive(name2[j])) {
                strcpy(killed[ksize++], name2[j]);
                printf("%s %d\n", name2[j], time2[j]);
            }
            ++j;
        }
        printf("-\n");
    }
    return 0;
}

