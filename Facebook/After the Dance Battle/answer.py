#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, collections
def r():
    for line in sys.stdin:
        for tok in line.strip().split():
            yield tok

inp = r()
cases = int(inp.next())

dx = [-1, 1, 0, 0];
dy = [0, 0, -1, 1];

for cc in xrange(cases):
    r, c = map(int, [inp.next(), inp.next()])
    maze = [inp.next() for i in xrange(r)]

    sy, sx, ey, ex = -1, -1, -1, -1
    for y in xrange(r):
        try:
            x = maze[y].index("S")
            sy, sx = y, x
        except:
            pass
        try:
            x = maze[y].index("E")
            ey, ex = y, x
        except:
            pass
    inrange = lambda y, x: 0 <= y < r and 0 <= x < c and maze[y][x] != "W"
    queue = collections.deque()
    queue.append([sy, sx])
    d = [[-1] * c for i in xrange(r)]
    d[sy][sx] = 0

    def dfs(maze, color, y, x, d, set, queue):
        if not inrange(y,x): return
        if d[y][x] != -1: return
        if maze[y][x] != color: return
        d[y][x] = set
        queue.append((y,x))
        for k in xrange(4):
            dfs(maze, color, y+dy[k], x+dx[k], d, set, queue)
    #for m in maze: print m

    while True:
        y, x = queue.popleft()
        if ey == y and ex == x: break
        #print "(%d,%d) at %d" % (y, x, d[y][x])
        if maze[y][x] not in "0SE":
            for ny in xrange(r):
                for nx in xrange(c):
                    if maze[ny][nx] == maze[y][x] and d[ny][nx] == -1:
                        d[ny][nx] = d[y][x] + 1
                        queue.append((ny, nx))
        for k in xrange(4):
            ny, nx = y + dy[k], x + dx[k]
            if not inrange(ny,nx): continue
            if d[ny][nx] != -1: continue
            d[ny][nx] = d[y][x] + 1
            queue.append((ny, nx))
    print d[ey][ex]


