N = int(input())

ans = 0
for i in range(1, 1000000):
  x = int(str(i) + str(i))
  if x <= N:
    ans += 1

print(ans)
