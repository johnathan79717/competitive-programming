def z(n, p):
    a = 0
    while n % p == 0:
        n //= p
        a += 1
    return a

input()

for x in input().split():
    t = b = int(x)
    while t % 10 == 0: t //= 10
    k = z(t, 5)
    for _ in range((k+1)//2):
        b *= 4
    print(b)