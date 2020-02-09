def gcd(a, b):
    if not a: return b
    return gcd(b % a, a)

T = int(input())

for case in range(1,T+1):
    
    N = int(input())
    store = []
    for i in range(N):
        C,J = map(int,input().split())
        store.append((C,J))
        #C, J

    diff = set()
    for i in range(N):
        for j in range(i+1, N):
            dx = store[i][0] - store[j][0]
            dy = store[i][1] - store[j][1]
            if dx * dy < 0:
                dx, dy = abs(dx), abs(dy)
                g = gcd(dx, dy)
                diff.add((dx // g, dy // g))                        

    ans = len(diff) + 1

    print ("Case #%d: %d" % (case, ans))
