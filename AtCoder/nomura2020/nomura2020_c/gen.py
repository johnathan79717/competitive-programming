from random import randint

N = 4
print(N)
print(1)
for i in range(1, N+1):
  print(randint(0 if i < N else 1, 5))

