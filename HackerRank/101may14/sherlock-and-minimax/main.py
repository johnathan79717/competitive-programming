N = int(raw_input())

A = map(int, raw_input().split())

P, Q = map(int, raw_input().split())

A.sort()

# if Q >= max(A):
#   if Q - max(A) >= diff:
#     ans = Q
#     diff = Q - max(A)

ans = (0, -P)

if Q > max(A):
  ans = max(ans, (abs(Q-max(A)), -Q))

if P < min(A):
  ans = max(ans, (abs(P - min(A)), -P))

for i in xrange(len(A)-1, 0, -1):
  if A[i-1] < P and P < A[i]:
    ans = max(ans, (min(P-A[i-1], A[i]-P), -P))
  if A[i-1] < Q and Q < A[i]:
    ans = max(ans, (min(Q-A[i-1], A[i]-Q), -Q))
  diff = (A[i] - A[i-1]) / 2
  if P <= A[i-1] + diff and A[i-1] + diff <= Q:
    ans = max(ans, (diff, -(A[i-1]+diff)))
  # print i, ans

# if P <= min(A):
#   if min(A) - P >= diff:
#     ans = P

print -ans[1]