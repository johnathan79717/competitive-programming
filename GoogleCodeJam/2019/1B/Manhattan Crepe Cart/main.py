T = int(input())

for t in range(T):
    P, Q = map(int, input().split())
    x = [0] * (Q+2)
    y = [0] * (Q+2)
    a = b = 0
    for p in range(P):
        s = input().split()
        X, Y, D = int(s[0]), int(s[1]), s[2]
        if D == 'E':
            x[X+1] += 1
        elif D == 'W':
            a += 1
            x[X] -= 1
        elif D == 'N':
            y[Y+1] += 1
        else:
            b += 1
            y[Y] -= 1

    ans = [(a, 0), (b, 0)]
    for q in range(Q+1):
        a += x[q]
        b += y[q]
        if a > ans[0][0]:
            ans[0] = (a, q)
        if b > ans[1][0]:
            ans[1] = (b, q)
    print('Case #{}:'.format(t+1), ans[0][1], ans[1][1])
