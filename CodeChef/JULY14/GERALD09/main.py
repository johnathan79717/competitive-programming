T = int(input())

p = lambda x: print(x, end='')

for t in range(T):
  N, M, K = map(int, input().split())
  ratio = round(K / (N * M))
  for n in range(N):
    for m in range(M):
      if ratio == 1:
        p('A')
      else if ratio == 2:
        if (n + m) % 2 == 0:
          p('A')
        else:
          p('T')
    print()