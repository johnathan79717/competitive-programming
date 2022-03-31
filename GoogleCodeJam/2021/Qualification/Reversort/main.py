T = int(input())
for t in range(T):
    N = int(input())
    A = [int(x) for x in input().split()]
    ans = 0
    for i in range(N):
        # print(A)
        j = A.index(min(A[i:]))
        # print(i, j, A[i:j+1], A[j:i-1:-1])
        A[i:j+1] = A[i:j+1][::-1]
        ans += j - i + 1
    print('Case #{}: {}'.format(t+1, ans))
