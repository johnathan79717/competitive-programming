T = int(input())

for t in range(T):
    R, C = map(int, input().split())
    m = []
    for i in range(R):
        m.append(input())
    print 'Case #{}:'.format(t+1), solve(0, R-1, 0, C-1)
