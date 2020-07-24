T = int(input())

for t in range(1, T+1):
    print('Case #{}: '.format(t), end='')

    X, Y = (int(x) for x in input().split())

    if (X + Y) % 2 == 0:
        print('IMPOSSIBLE')
        continue

    k = 1
    while 2 * k - 1 < abs(X) + abs(Y):
        k *= 2

    ans = ''
    while k:
        # print(X, Y, k)
        assert(X != 0 or Y != 0)
        if abs(X) > abs(Y):
            if X > 0:
                ans = 'E' + ans
                X -= k
            else:
                X += k
                ans = 'W' + ans
        else:
            if Y > 0:
                ans = 'N' + ans
                Y -= k
            else:
                ans = 'S' + ans
                Y += k
        k //= 2

    assert(X == 0 and Y == 0)

    print(ans)

