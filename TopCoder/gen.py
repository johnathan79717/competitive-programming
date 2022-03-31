import random

a = [str(random.randint(1, 9999)) for i in range(3000)]
print(','.join(a))
