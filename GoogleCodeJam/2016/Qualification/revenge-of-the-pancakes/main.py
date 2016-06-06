def solve(S):
    N = len(S)
    ans = 0
    for i in range(N):
        if i == N-1:
            if S[i] == '-':
                ans += 1
        else:
            if S[i] != S[i+1]:
                ans += 1
    return ans

T = int(input())

for t in range(T):
    S = input()
    print('Case #' + str(t+1) + ': ' + str(solve(S)))

