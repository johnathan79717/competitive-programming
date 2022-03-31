N = int(input())

b = 0
ans = 10 ** 18
while 2 ** b <= N:
    a = N // (2 ** b)
    c = N % (2 ** b)
    ans = min(ans, a + b + c)
    b += 1

print(ans)
