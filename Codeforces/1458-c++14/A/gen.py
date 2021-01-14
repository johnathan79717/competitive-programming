from random import randint

n = randint(1, 10)
m = randint(1, 10)
MAX = 10**18

a = []
b = []

for i in range(n):
  a.append(str(randint(1, MAX)))

for i in range(m):
  b.append(str(randint(1, MAX)))

print(n, m)
print(' '.join(a))
print(' '.join(b))
