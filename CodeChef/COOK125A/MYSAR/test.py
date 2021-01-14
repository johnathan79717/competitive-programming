def f(a):
  N = len(a)
  for L1 in range(N):
    for R1 in range(L1+1, N):
      for L2 in range(N):
        for R2 in range(L2+1, N):
          print(L1, R1, L2, R2, max(a[L1:R1+1]) - min(a[L2:R2+1]))
f([1, 0, -1, 1])
print()
f([1, 2, 3, 1])
