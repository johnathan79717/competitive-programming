import sys
T, N, B, P = map(int, input().split())

x = 7

for t in range(1, T+1):
    c = [[] for j in range(N)]
    j = 0
    for i in range(N * B):
        D = int(input())
        # sys.stderr.write(str(i) + ' ' + str(D) + '\n')
        if D not in range(10):
            exit(-1)
        ans = 0
        if D == 9:
            for j in range(N):
                if j < x:
                    if B - 2 <= len(c[j]) < B:
                        ans = j
                        break
                else:
                    if B - 1 <= len(c[j]) < B:
                        ans = j
                        break
            else:
                for j in range(N):
                    if len(c[j]) < B:
                        ans = j
                        break
        else:
            for j in range(N):
                if j < x:
                    if len(c[j]) < B - 2:
                        ans = j
                        break
                else:
                    if len(c[j]) < B - 1:
                        ans = j
                        break
            else:
                for j in range(N):
                    if len(c[j]) < B:
                        ans = j
                        break
        c[ans].append(D)
        print(ans + 1)
        # for a in c:
            # sys.stderr.write(str(a) + '\n') 
D = int(input())

