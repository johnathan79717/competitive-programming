H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = input()
T = input()

lr, rr = 1, H
lc, rc = 1, W
# print(lr, rr, lc, rc)

for i in range(N-1, -1, -1):
    if T[i] == 'L':
        rc = min(rc+1, W)
    elif T[i] == 'R':
        lc = max(lc-1, 1)
    elif T[i] == 'U':
        rr = min(rr+1, H)
    else:
        lr = max(lr-1, 1)

    # print(lr, rr, lc, rc)

    if S[i] == 'L':
        lc += 1
    elif S[i] == 'R':
        rc -= 1
    elif S[i] == 'U':
        lr += 1
    else:
        rr -= 1

    # print(lr, rr, lc, rc)

    if lc > rc or lr > rr:
        print('NO')
        exit()

if not lr <= sr <= rr or not lc <= sc <= rc:
    print('NO')
else:
    print('YES')
