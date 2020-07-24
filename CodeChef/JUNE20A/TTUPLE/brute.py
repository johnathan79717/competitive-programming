T = int(input())

LIMIT = 20

for t in range(T):
    p, q, r = (int(x) for x in input().split())
    a, b, c = (int(x) for x in input().split())

    def solve(p, q, r, l):
        if l == 3:
            return 3
        if (p, q, r) == (a, b, c):
            return l
        ans = 3
        for d in range(-LIMIT, LIMIT):
            ans = min(ans, solve(p, q, r, l+1))
            ans = min(ans, solve(p, q+d, r, l+1))
            ans = min(ans, solve(p, q, r+d, l+1))
            ans = min(ans, solve(p, q+d, r+d, l+1))
            ans = min(ans, solve(p+d, q, r, l+1))
            ans = min(ans, solve(p+d, q+d, r, l+1))
            ans = min(ans, solve(p+d, q, r+d, l+1))
            ans = min(ans, solve(p+d, q+d, r+d, l+1))

            ans = min(ans, solve(p, q, r, l+1))
            ans = min(ans, solve(p, q*d, r, l+1))
            ans = min(ans, solve(p, q, r*d, l+1))
            ans = min(ans, solve(p, q*d, r*d, l+1))
            ans = min(ans, solve(p*d, q, r, l+1))
            ans = min(ans, solve(p*d, q*d, r, l+1))
            ans = min(ans, solve(p*d, q, r*d, l+1))
            ans = min(ans, solve(p*d, q*d, r*d, l+1))

        return ans

    print(solve(p, q, r, 0))
