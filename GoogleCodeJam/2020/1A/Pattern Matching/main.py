import re 

T = int(input())

for t in range(1, T+1):
    N = int(input())
    P = { input() for i in range(N) }
    print('Case #{}: '.format(t), end='')

    pure = { p for p in P if '*' not in p }
    if len(pure) > 1:
        print('*')
        continue

    if len(pure):
        ans = pure.pop()
        P.remove(ans)
        patterns = [re.compile(p.replace('*', '.*')) for p in P]
        if all(p.match(ans) for p in patterns):
            print(ans)
        else:
            print('*')
        continue

    prefixes = { p[:p.index('*')] for p in P }
    middles = ''.join({ p[p.index('*')+1:p.rindex('*')].replace('*', '') for p in P })
    suffixes = { p[p.rindex('*')+1:] for p in P }

    longest_prefix = max(prefixes, key=lambda x: len(x))
    longest_suffix = max(suffixes, key=lambda x: len(x))

    if not all(longest_prefix.startswith(prefix) for prefix in prefixes):
        # print(longest_prefix, prefixes)
        print('*')
        continue


    if not all(longest_suffix.endswith(suffix) for suffix in suffixes):
        # print(longest_suffix, suffixes)
        print('*')
        continue

    print(longest_prefix + middles + longest_suffix)
