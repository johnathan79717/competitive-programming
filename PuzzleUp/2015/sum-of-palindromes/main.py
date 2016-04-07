def isPalindrome(n):
    s = str(n)
    return s == s[::-1]
print(isPalindrome(898))

ans = (0, 0, 0, 0)
for i in range(10,1000):
    if not isPalindrome(i): continue;
    for j in range(10,i):
        if not isPalindrome(j): continue;
        for k in range(10,j):
            if not isPalindrome(k) or not isPalindrome(i+j+k): continue;
            ans = max(ans, (i*j*k, i, j, k))

print(ans)
