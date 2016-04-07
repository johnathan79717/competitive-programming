T = int(input())

for t in range(T):
  input()
  P = input()
  Q = input()
  q = len(Q)
  p = len(P)
  d = 0
  for i in range(min(p, q)):
    if P[i] != Q[i]:
      break
    d = i+1
  # if d == q:
  #   print(P[d:] + '*')
  if q-d + p-d < p + 2:
    print('<' * (q-d) + P[d:] + '*')
  else:
    print('*' + P + '*')