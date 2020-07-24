N = int(input())

a = [int(x) for x in input().split()]

ans = 0
for i, x in enumerate(a, 1):
    if i % 2 and x % 2:
        ans += 1

print(ans)
