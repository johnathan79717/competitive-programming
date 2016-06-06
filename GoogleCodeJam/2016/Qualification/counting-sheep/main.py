def solve(N):
    if N == 0:
        return 'INSOMNIA'
    s = set()
    i = 0
    while s != set('1234567890'):
        i += N
        s |= set(str(i))
    return str(i)

T = int(input())

for t in range(T):
    N = int(input())
    # N = t
    print 'Case #' + str(t+1) + ': ' + solve(N)

