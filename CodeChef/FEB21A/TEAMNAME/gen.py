from random import randrange, randint, shuffle

T = 100
print(T)

for t in range(T):
  L = randint(3, 3)
  N = randint(2, 2**L)
  print(N)

  a = []
  for n in range(2 ** L):
    c = ''
    for j in range(L):
      c = c + ('a' if n % 2 else 'b')
      n //= 2
    a.append(c)

  shuffle(a)
  for i in range(N):
    print(a[i])

