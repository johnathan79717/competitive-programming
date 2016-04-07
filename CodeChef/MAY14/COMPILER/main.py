T = int(raw_input())

for t in xrange(T):
  e = raw_input()
  cnt = 0
  ans = 0
  for i in xrange(len(e)):
    if e[i] == '<':
      cnt += 1
    else:
      cnt -= 1
    if cnt < 0:
      break
    if cnt == 0:
      ans = max(ans, i + 1)
  print ans