T = int(input())


def gcd(a, b):
  if a == 0:
    return b
  else:
    return gcd(b % a, a)

for t in range(T):
  N = int(input())
  A = list(map(int, input().split()))
  ans = 1
  s = set()
  for i in range(N):
    cnt = 0
    # print('start from ' + str(i))
    while i not in s:
      s.add(i)
      cnt += 1
      i = A[i]-1
    #   print('i: ' + str(i))
    # print(cnt)
    if cnt > 0:
      ans = ans * cnt // gcd(ans, cnt)
  print(ans % 1000000007)
