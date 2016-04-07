from itertools import permutations

N = int(raw_input())

A = map(int, raw_input().split())

def dfs(s, i):
  if i == N:
    return s
  ans = 0
  for p in permutations(str(s + A[i])):
    ans = max(ans, dfs(int(''.join(p)), i+1))
  return ans

print dfs(0, 0)

# print ans