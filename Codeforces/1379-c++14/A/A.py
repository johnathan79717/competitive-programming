T = int(input())

x = 'abacaba'

def match(s):
    for i in range(len(x)):
        if s[i] != x[i] and s[i] != '?':
            return False
    return True


def solve():
    n = int(input())
    s = input()
    if s.find(x) != s.rfind(x):
        return None
    if s.find(x) >= 0:
        return s.replace('?', 'z')
    # print('not found')
    for i in range(len(s) - len(x) + 1):
        # print('matching', s[i:i+len(x)])
        if match(s[i:i+len(x)]):
            # print('matched')
            t = s[:i] + x + s[i+len(x):]
            if t.find(x) == t.rfind(x):
                return t.replace('?', 'z')
    return None

for t in range(T):
    s = solve()
    if s is None:
        print('No')
    else:
        print('Yes')
        print(s)
