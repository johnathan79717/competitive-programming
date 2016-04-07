N, M, L, R = [int(x) for x in input().split()]

def divisors(N):
    d1 = []
    for i in range(1, N+1):
        if i * i > N:
            break
        if N % i == 0:
            d1.append(i)
            if i * i < N:
                d1.append(N // i)
    d1.sort()
    return d1

d1 = divisors(N)
d2 = divisors(M)

# print(d1)
# print(d2)

ans = 0

for a in d1:
    for b in d2:
        if L <= a * b <= R:
            ans+=1

print(ans)