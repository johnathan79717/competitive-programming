import itertools

T = int(raw_input())

for t in range(T):
    def solve():

        S, E = raw_input().split()
        base = 0

        s = [len(list(g)) for k, g in itertools.groupby(S)]
        e = [len(list(g)) for k, g in itertools.groupby(E)]

        if E == '0':
            if S == '0':
                return 0
            return len(s)
        if S == '0':
            base = 1

        if not(len(e) <= len(s) or len(e) == len(s) + 1 and len(e) % 2 == 0):
            return 'IMPOSSIBLE'

        ans = 10000000000000
        for l in xrange(min(len(s), len(e)) + 1):
            if l == 0 or s[-l:] == e[:l]:
                ans = min(ans, base + len(s) - l + sum(e[l:]))

        # print(ans)

        if len(s) > 1:
            if len(s) % 2:
                s.pop(0)
                base += 1
            if len(e) <= len(s):
                for l in xrange(min(len(s), len(e))):
                    if s[-1-l:-1] == e[:l] and s[-1] <= e[l]:
                        ans = min(ans, base + len(s) - (l+1) + sum(e[l:]) - s[-1])

        return ans

    print 'Case #{}: {}'.format(t+1, str(solve()))
