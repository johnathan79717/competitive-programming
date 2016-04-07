#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys, collections
from fractions import Fraction as F
def r():
    for line in sys.stdin:
        for tok in line.strip().split():
            yield tok

input = r()
read = lambda: input.next()
cases = int(read())

def go(to_overtake, corner):
    if corner == t:
        return F(1,1) if to_overtake == 0 else F(0,1)
    global cache
    key = (to_overtake, corner)
    if key in cache: return cache[key]

    ret = go(to_overtake, corner+1) * normal[corner]
    ret = max(ret, go(to_overtake-1, corner+1) * overtake[corner])

    cache[key] = ret
    return ret

for cc in xrange(cases):
    normal = []
    overtake = []
    cache = {}

    r, t = map(int, (read(), read()))
    for i in xrange(t):
        o, m = map(int, (read(), read()))
        overtake.append(F(o-1, o))
        normal.append(F(m-1, m))
    ret = go(r-1, 0)
    print "%d/%d" % (ret.numerator, ret.denominator)
