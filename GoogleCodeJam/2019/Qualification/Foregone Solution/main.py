T = int(raw_input())
for t in xrange(T):
    N = raw_input()
    A = ''
    B = ''
    for i in xrange(len(N)):
        if N[i] == '4':
            A += '2'
            B += '2'
        else:
            A += N[i]
            B += '0'
        # print N[i], A, B
    B = B.lstrip('0')
    if not B:
        B = '0'
    print 'Case #{}:'.format(t+1), A, B
        
