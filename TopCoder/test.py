for n in range(6, 15):
  for L in range(10, 1001):
    x = (L + (n - 4)) // (n-2)
    if (L + n - 2 - x - 1) - (n-1) < L / 2:
      print(n, L)
