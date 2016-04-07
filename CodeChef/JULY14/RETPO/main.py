T = int(input())
 
for t in range(T):
  x, y = map(abs, map(int, input().split()))
  if x < y:
    if x % 2 == y % 2:
      print(2*y)
    else:
      print(2*y-1)
  else:
    if x % 2 == y % 2:
      print(2*x)
    else:
      print(2*x+1)