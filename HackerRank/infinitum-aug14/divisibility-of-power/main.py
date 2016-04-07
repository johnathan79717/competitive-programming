N = int(input())
A = list(map(int, input().split()))
Q = int(input())
INF = 1000000000
zero = [INF] * (N+1)
one = [INF] * (N+1)
for i in range(N-2, -1, -1):
  zero[i] = i if A[i] == 0 else zero[i+1]
  one[i] = i if A[i] == 1 else one[i+1]
# print(zero)
# print(one)
def pow(a, n, x):
  if n == 0:
    return 1
  half = pow(a, n//2, x)
  if n % 2 == 0:
    return half * half % x
  else:
    return half * half * a % x

def check(i, j, x):
  # print(i, j, x)
  if x == 1:
    return True
  if A[i] == 0:
    return True
  if A[i] == 1:
    return False
  if i == j:
    return A[i] % x == 0
  if j == i + 1:
    return pow(A[i], min(64, A[j]), x) == 0

  o = one[i]
  if o == i:
    return False
  else:
    assert(o > i)
    j = min(j, o - 1)

  z = zero[i]
  if z == i:
    return True
  elif z == i + 1:
    return False
  else:
    j = min(j, z - 2)
  # print(i, j, x)
  p = 1
  for k in range(j, i, -1):
    p = A[k] ** p
    if p >= 64:
      p = 64
      break
  # print(p)
  return pow(A[i], p, x) == 0

for q in range(Q):
  i, j, x = map(int, input().split())
  i -= 1
  j -= 1
  print('Yes' if check(i, j, x) else 'No')
  # print('Yes')
