s = input().split()

X = int(s[0])
Y = int(s[2])

N = int(input())
t = [int(x) for x in input().split()]

ans = []

if X == 1:
    Y *= 1000000000
    ans = [t[0]]
    for i in range(1, N):
        ans.append(max(t[i], ans[-1] + Y))
else:
    assert(Y == 1)
    ans = []
    for i in range(N):
        if i - X < 0:
            ans.append(t[i])
        else:
            ans.append(max(t[i], ans[-X] + 1000000000))

print(' '.join(str(x) for x in ans))