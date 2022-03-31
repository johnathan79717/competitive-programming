T = int(input())

for t in range(T):
    print('Case #{}: '.format(t+1), end='')
    N, C = map(int, input().split())
    C -= N-1
    if C < 0 or C > N * (N-1) // 2:
        print('IMPOSSIBLE')
        continue
    j = [0] * (N-1)
    for i in range(N-1):
        j[i] = min(i + C, N-1)
        C -= min(C, j[i] - i)
    assert(C == 0)
    
    # print(j)
    y = list(range(1, N+1))
    for i in range(N-2, -1, -1):
        y[i:j[i]+1] = y[i:j[i]+1][::-1]
        
    print(' '.join(map(str, y)))
        
