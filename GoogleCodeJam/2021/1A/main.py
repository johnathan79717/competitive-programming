T = int(input())

for t in range(T):
    N = int(input())
    X = [int(x) for x in input().split()]
    
    ans = 0
    for i in range(1, N):
        if X[i] > X[i-1]:
            continue
        d = len(str(X[i-1])) - len(str(X[i]))
        # print(X[i] * (10 ** d) + (10 ** d - 1))
        if X[i] * (10 ** d) + (10 ** d - 1) <= X[i-1]:
            ans += d + 1
            X[i] *= (10 ** (d+1))
            continue
        while X[i] <= X[i-1]:
            X[i] *= 10
            ans += 1
            d -= 1
            while X[i] * (10 ** d) + (10 ** d - 1) <= X[i-1]:
                X[i] += 1
        # print(ans)
    print('Case #{}: {}'.format(t+1, ans))
