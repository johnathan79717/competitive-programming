T = int(input())

for t in range(T):
    print('Case #{}: '.format(t+1), end='')
    X, Y, M = (x for x in input().split())
    X, Y = int(X), int(Y)
    for i, m in enumerate(M, 1):
        if m == 'N':
            Y += 1
        elif m == 'S':
            Y -= 1
        elif m == 'E':
            X += 1
        else:
            assert(m == 'W')
            X -= 1
        if abs(X) + abs(Y) <= i:
            print(i)
            break
    else:
        print('IMPOSSIBLE')
