N = int(raw_input())

loser = {}
winner = []

for n in xrange(N-1):
  s1, s2 = raw_input().split()
  loser[s2] = True
  winner.append(s1)

for w in winner:
  if w not in loser:
    print w
    break