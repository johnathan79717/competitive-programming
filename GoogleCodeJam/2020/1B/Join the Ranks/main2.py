T = int(input())

for t in range(T):
    print('Case #{}: '.format(t+1), end='')

    R, S = (int(w) for w in input().split())

    deck = [i for j in range(S) for i in range(R)]
    target = [i for i in range(R) for j in range(S)]

    # print(deck)

    ans = []
    while deck != target:
        b = len(deck) - 2
        while b >= 0:
            if deck[b] == deck[0] and deck[b] != deck[b+1]:
                break
            b -= 1
        assert(b >= 0)
        a = b
        while b >= 0 and deck[a] != deck[b+1]:
            a -= 1
        if a < 0:
            A = deck[:b+1]
            B = deck[b+1:]
            ans.append((len(A), len(B)))
            deck = B + A
            assert(deck == target)
            continue
            
        A = deck[:a+1]
        B = deck[a+1:b+1]
        C = deck[b+1:]
        # print(A, B, C)
        assert(A[0] == B[-1] and A[-1] == C[0] and A[-1] != B[0] and B[-1] != C[0])

        deck = B + A + C
        ans.append((len(A), len(B)))

    print(len(ans))
    for line in ans:
        print(' '.join(str(i) for i in line))
