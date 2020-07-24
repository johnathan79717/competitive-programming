T = int(input())

def intersection(s1, s2):
    if s1[0] >= s2[1] or s1[1] <= s2[0] or s1[2] >= s2[3] or s1[3] <= s2[2]:
        return (0, 0, 0, 0)
    return (max(s1[0], s2[0]), min(s1[1], s2[1]), max(s1[2], s2[2]), min(s1[3], s2[3]))

def area(s):
    return (s[1] - s[0]) * (s[3] - s[2])

def shift(s, a, b):
    return (s[0] + a, s[1] + a, s[2] + b, s[3] + b)

def gcd(a, b):
    return b if a == 0 else gcd(b % a, a)

for t in range(T):
    print('Case #{}: '.format(t+1), end='')
    N, D = (int(x) for x in input().split())
    s = []
    for i in range(N):
        x, y = (int(x) for x in input().split())
        s.append((x-y-D, x-y+D, x+y-D, x+y+D))
    s1, s2 = s
    d1 = intersection(s1, s2)
    am = area(d1)
    if am == 0:
        print(0, 1)
        continue

    total = area(s1) + area(s2) - am
    d2 = shift(d1, s1[0] - s2[0], s1[2] - s2[2])
    d3 = shift(d1, s2[0] - s1[0], s2[2] - s1[2])

    d12 = intersection(d1, d2)
    d23 = intersection(d3, d2)
    d13 = intersection(d1, d3)

    d = am + area(d2) + area(d3) - area(d12) - area(d13) - area(d23) + area(intersection(d12, d23))

    g = gcd(d, total)

    print(d // g, total // g)


