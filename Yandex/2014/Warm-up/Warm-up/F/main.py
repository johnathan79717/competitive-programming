n = int(raw_input())
a = map(int, raw_input().split())

if a[1] > 1:
  if n == 1 and a[1] == 2:
    ans = [0, 2]
  else:
    ans = [0, 1] + [a[1]-1] + a[2:]
else:
  ans = [0] + [a[2]+1] + a[3:]

print len(ans) - 1
print ' '.join(map(str, ans))