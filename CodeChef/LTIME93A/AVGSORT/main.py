T = int(input())

for t in range(T):
    N = int(input())
    A = [int(x) for x in input().split()]
    if A == sorted(A)[::-1]:
      print('No')
    else:
      print('Yes')
