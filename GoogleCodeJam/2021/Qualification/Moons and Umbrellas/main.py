T = int(input())

for t in range(T):
    X, Y, S = input().split()
    X, Y = int(X), int(Y)
    
    ans = 1000000000
    def test(s):
        if S[0] != '?' and S[0] != s[0]:
            return 1000000000
        if S[-1] != '?' and S[-1] != s[-1]:
            return 1000000000
        cnt = 0
        prev = 0
        assert(s[0] != '?' and s[-1] != '?')
        
        # print(s)
        for i in range(1, len(S)):
            if s[i] != '?':
                if s[i] != s[prev]:
                    if s[prev] == 'C':
                        cnt += X
                    else:
                        cnt += Y
                    if X + Y < 0:
                        cnt += (i - prev - 1) // 2 * (X + Y)
                else:
                    if X + Y < 0:
                        cnt += (i - prev) // 2 * (X + Y)
                prev = i
            # print(i, cnt)
        return cnt
    for h in 'CJ':
        for b in 'CJ':
            ans = min(ans, test(h + S[1:-1] + b))
            # print(h, b, ans)
    print('Case #{}: {}'.format(t+1, ans))
