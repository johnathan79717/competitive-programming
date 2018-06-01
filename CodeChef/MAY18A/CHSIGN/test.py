from random import randint
print('1')
n = randint(1, 10)
print(str(n))
a = [ str(randint(1, 10)) for i in xrange(n) ]
print(' '.join(a))

