T = int(raw_input())

for t in xrange(T):
    print 'Case #{}:'.format(t+1),
    N, A, B = (int(x) for x in raw_input().split())
    U = [0] + [int(x) for x in raw_input().split()]
    for n in xrange(N+1, 1001):
        dp = [0] * (n+1)
        dp[n] = 1
        for i in xrange(n, 0, -1):
            if i <= N:
                if dp[i] < U[i]:
                    break
                dp[i] -= U[i]
            if i > A:
                dp[i-A] += dp[i]
                if i > B:
                    dp[i-B] += dp[i]
        else:
            print(n)
            break
    else:
        print('IMPOSSIBLE')
