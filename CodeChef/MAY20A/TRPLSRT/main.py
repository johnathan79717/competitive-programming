T = int(input())

def ass(p):
    if not p:
        print(1 / 0)

for t in range(T):
    N, K = map(int, input().split())
    p = [int(x) - 1 for x in input().split()]
    inv = [0] * N
    for i, pi in enumerate(p):
        inv[pi] = i

    ans = []
    i = 0
    pairs = set()
    while i < N:
        # print(i, p)
        while i < N and p[i] == i:
            i += 1
        if i < N:
            i1, i2, i3 = inv[i], i, p[i]
            # print(i1, i2, i3)
            if i1 == i3:
                pairs.add((min(i1, i2), max(i1, i2)))
                i += 1
                continue
            # print(i1, i2, i3)
            ans.append((i1+1, i2+1, i3+1))
            p[i2], p[i3], p[i1] = p[i1], p[i2], p[i3]
            for x in [i1, i2, i3]:
                inv[p[x]] = x
            # print(i1, p[i1], i2, p[i2], i3, p[i3])
            # assert(p[:i+1] == list(range(i+1)))
    else:
        # print(p, ans, pairs)
        if len(pairs) % 2 == 1:
            print(-1)
        else:
            pairs = list(pairs)
            for i in range(len(pairs) // 2):
                a, b = pairs[2*i]
                c, d = pairs[2*i+1]
                i1, i2, i3 = b, a, c
                ans.append((i1+1, i2+1, i3+1))
                p[i2], p[i3], p[i1] = p[i1], p[i2], p[i3]
                i1, i2, i3 = b, d, c
                ans.append((i1+1, i2+1, i3+1))
                p[i2], p[i3], p[i1] = p[i1], p[i2], p[i3]
            ass(p == list(range(N)))
            ass(len(ans) <= K)
            print(len(ans))
            for line in ans:
                print(*line)
