T = int(raw_input())

for t in xrange(T):
    Y = int(raw_input())
    def test(p):
        x = int(str(p) + str(p+1))
        p += 2
        while x <= Y:
            x = int(str(x) + str(p))
            p += 1
        return x
    L = len(str(Y))

    ans = 10 ** 19
    for i in xrange(1, L+1):
        ans = min(ans, test(int(str(Y)[:i])))
        ans = min(ans, test(1 + int(str(Y)[:i])))
        for j in xrange(18):
            if 10**i - j < 1:
                break
            ans = min(ans, test(10**i - j))
    print('Case #{}: {}'.format(t+1, ans))
