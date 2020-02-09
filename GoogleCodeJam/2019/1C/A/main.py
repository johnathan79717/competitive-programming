beats = {'S': 'P', 'P': 'R', 'R': 'S'}
loses = {'P': 'S', 'R': 'P', 'S': 'R'}

def solve():
    A = int(input())
    C = []
    for a in range(A):
        C.append(input())
    i = 0
    ans = ''

    while C:
        s = { c[i % len(c)] for c in C }
        assert(len(s) <= 3)
        if len(s) == 3:
            return 'IMPOSSIBLE'
        if len(s) == 1:
            ans += loses[list(s)[0]]
            return ans
        # len(s) == 2
        for m in 'RPS':
            if m not in s:
                ans += beats[m]
        C2 = []
        for c in C:
            if not beats[ans[-1]] == c[i % len(c)]:
                C2.append(c)
        assert(len(C2) < len(C))
        C = C2
        i += 1
    return ans

T = int(input())
for t in range(T):
    print('Case #{}:'.format(t+1), solve())


