N = 100
ans = []
for i in range(N+1):
  for j in range(1, i):
    ans.append((j, i))

print(len(ans))
for i, j in ans:
  print(i, j)
