roots = []

def root(x):
	if roots[x] == x:
		return x
	r = root(roots[x])
	roots[x] = r
	return r

def union(a, b):
	if root(a) != root(b):
		roots[root(b)] = root(a)

s, e, c = map(int, raw_input().split())
adj = [[] for _ in range(s)]
r_adj = [[] for _ in range(s)]

roots = [x for x in range(s)]

for _ in range(c):
	u, v = map(int, raw_input().split())
	adj[u].append(v)
	r_adj[v].append(u)

is_private = [False for _ in range(s)]

em = {x:x for x in map(int, raw_input().split())} if e > 0 else {}
q = []
for k in em.keys():
	q.append(k)
private_cnt = 0
while len(q):
	u = q.pop()
	for v in r_adj[u]:
		if not is_private[v] and v not in em:
			is_private[v] = True
			private_cnt += 1
			q.append(v)

for a in range(s):
	if is_private[a] or a in em:
		continue
	for b in adj[a]:
		if b not in em and not is_private[b]:
			union(a, b)

cache = {}
cnt = 0
for x in roots:
	cache[root(x)] = 1
for k in cache.keys():
	if k not in em and not is_private[k]:
		cnt += 1
print cnt + private_cnt