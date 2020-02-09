import sys

def get_block(N, B):
    return min(B+1, (N+1) // 2)

def gen_test(N, B):
    block = get_block(N, B)
    s = '0' * block + '1' * block
    s *= (N + 2 * block - 1) // (2 * block)
    return s[:N]

def p(*args, **kwargs):
    return
    print(*args, file=sys.stderr, **kwargs)

for t in range(int(input())):
    s = input()
    N, B, F = [int(x) for x in s.split()]
    state = [(N, B)]
    while len(state) < N:
        F -= 1
        if F < 0: exit(1)
        test = ''.join(gen_test(n, b) for n, b in state)
        print(test)
        response = input()
        offset = 0
        next_state = []
        for n, b in state:
            res = response[offset:offset+n-b]
            offset += n-b
            block = get_block(n, b)
            if block == (n + 1) // 2: # split in half
                n0 = block
                n1 = n - block
                next_state.append((n0, n0 - res.count('0')))
                if n1:
                    next_state.append((n1, n1 - res.count('1')))
            else:
                nn, bb = n, b
                l = r = 0
                while r < len(res):
                    while r < len(res) and res[r] == res[l]:
                        r += 1
                    if block <= nn:
                        next_state.append((block, block - r + l))
                        nn -= block
                    else:
                        next_state.append((nn, nn - r + l))
                        nn = 0
                    l = r
                if nn:
                    next_state.append((nn, nn))
        state = next_state
        p(state)
    ans = []
    for i, (N, B) in enumerate(state):
        if B: ans.append(str(i))
    ans = ' '.join(ans)
    print(ans)
    p(ans)
    response = int(input())
    if response != 1:
        exit(1)
