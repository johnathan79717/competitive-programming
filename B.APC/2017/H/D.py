movies = map(int, raw_input().split())
movies = movies[1:]
first_map = {x:x for x in movies}
second = map(int, raw_input().split())
second = second[1:]
second_map = {x:x for x in second}
for m in second:
	if m in first_map:
		continue
	movies.append(m)

n = len(movies)
movies.sort()
movies = [-1] + movies

dp = [0 for _ in range(n + 1)]
dp[0] = 0

for i in xrange(1, n + 1):
	watch = True
	if movies[i] not in first_map and movies[i - 1] not in first_map:
		watch = False
	if movies[i] not in second_map and movies[i - 1] not in second_map:
		watch = False
	if watch:
		dp[i] = 1 + dp[i - 1]
	else:
		dp[i] = max(dp[i - 1], 1 + dp[i - 2])
print dp[n]