T = int(input())

for t in range(T):
  m = set([])
  ans = []
  input()
  n = input()
  S = map(int, input().split())
  for s in S:
    if s not in m:
      m.add(s)
      ans.append(str(s))
  print(' '.join(ans))