def isprime(n):
  if n == 2:
    return True;
  if n < 2 or n % 2 == 0:
    return False;

  u = long(n - 1)
  t = long(0)
  while u % 2 == 0:
    u = u // 2
    t = t + 1

  sprp = {2, 7, 61}
  for a in sprp:
    a = long(a % n);
    if (a == 0 or a == 1 or a == n-1):
     continue;

    x = (a ** u) % n;
    if (x == 1 or x == n-1):
      continue;

    for i in xrange(t-1):
      x = (x * x) % n;
      if (x == 1):
       return False;
      if (x == n-1):
       break;
    if x == n-1:
      continue;
    return False;
  return True;

def solve():
  n = long(input())
  while True:
    if isprime(n):
      return n
    n = n - 1


t = input()

for case in xrange(t):
  print solve()