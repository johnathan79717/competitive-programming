T = int(input())

for t in range(T):
    N, K = map(int, input().split())
    C = [int(x) for x in input().split()]
    D = [int(x) for x in input().split()]
    ans = 0
    for i in range(N):
        for j in range(i, N):
            if abs(max(C[i:j+1]) - max(D[i:j+1])) <= K:
                ans += 1
    print('Case #{}:'.format(t+1), ans)

