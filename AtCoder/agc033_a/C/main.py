N = int(input())
adj = [[] for i in range(N)]
for i in range(N-1):
    a, b = map(int, input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)

def bfs(i):
    global depth
    depth = [0] * N
    s = [i]
    depth[i] = 1
    while s:
        v = s.pop()
        for u in adj[v]:
            if not depth[u]:
                depth[u] = depth[v] + 1
                s.append(u)

bfs(0)
i = depth.index(max(depth))
bfs(i)

print('Second' if max(depth) % 3 == 2 else 'First')
