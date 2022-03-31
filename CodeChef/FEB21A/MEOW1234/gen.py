import random

w, h = 5, 5

print(2*w, 1)

for y in range(w, 0, -1):
  x1, x2 = random.randint(1, h), random.randint(1, h)
  print(x1, y)
  print(x2, y)
