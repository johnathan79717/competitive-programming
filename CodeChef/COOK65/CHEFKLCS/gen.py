import random
import string

def randomword(length):
   return ''.join(random.choice('abc') for i in range(length))

n = 1000
print str(n) + ' 3'
print(randomword(n))
print(randomword(n))
