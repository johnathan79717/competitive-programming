from collections import defaultdict

class Edge:
  def __init__(self, to, color):
    self.to = to
    self.color = color

class Big:
  def __init__(self):
    self.e = 0
    self.m = 0
    self.sign = 1
  def addBy(self, v):
    while self.e < v.e:
      self.e += 1
      self.m <<= 1
    while v.e < self.e:
      v.e += 1
      v.m <<= 1
    self.m += v.m
    if self.m != 0:
      while self.m & 1 == 0:
        self.m >>= 1
        self.e -= 1
  def addColor(color):
    

def value(root, parent):
  ans = Big()
  vs = []
  for e in G[root]:
    if(e.to != parent):
      v = value(e.to, root)
      v.addColor(e.color)
      ans.addBy(v)
  return ans

T = int(raw_input())
for t in xrange(T):
  N = int(raw_input())
  global G
  G = defaultdict(list)
  for i in xrange(N-1):
    U, V, C = [int(x) for x in raw_input().split()]
    G[V].append(Edge(V, C))
    G[U].append(Edge(U, C))
    v = value(1, -1)