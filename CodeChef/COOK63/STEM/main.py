T = int(input())

for t in range(T):
    n = int(input())
    words = input().split()
    L = len(words[0])
    ans = ''
    for i in range(L):
        for j in range(L):
            s = words[0][j:i+1]
            # print(s)
            for word in words:
                if s not in word:
                    break
            else:
                if len(s) > len(ans) or len(s) == len(ans) and s < ans:
                    ans = s
    print(ans)
