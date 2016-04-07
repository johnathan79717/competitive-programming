T = int(input())

M = 10**9 + 7
     
for t in range(T):
  S = input()
  ans = 1
  for i in range(len(S)):
    ans *= 2
    if i % 2 == 0:
      if S[i] == 'r':
        ans += 2
    else:
      if S[i] == 'l':
        ans -= 1
      else:
        ans += 1
    ans += M
    ans %= M
    # print(ans)
  print(ans)