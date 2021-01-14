N, K = (int(x) for x in input().split())

def f(x):
  return x - 1 if x <= N + 1 else 2 * N - x + 1

ans = 0
for y in range(2, 2*N+1):
  x = y + K
  # print(x, y)
  if 2 <= x <= 2*N:
    ans += f(x) * f(y)

print(ans);
