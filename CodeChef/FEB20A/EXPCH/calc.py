N = 100000

ans = 0
for i in range(N, 0, -1):
    ans += i * ((N - i) // 2 + 1)

print(ans % 1000000007)
