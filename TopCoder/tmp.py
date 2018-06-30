import sys, math, copy
import numpy as np
from functools import partial
from scipy.optimize import fmin

range = xrange

def cost_float(x, ab):
    i = np.arange(len(x))
    co = np.sum(np.abs(x[:] - (ab[0] * i[:] + ab[1])))
    return co

def minimize_float(x):
    cf = partial(cost_float, x)
    ab = fmin(cf, np.zeros(2))
    return ab

class ArithmeticSequenceDiv1():
    def findMinCost(self, x):
        x = np.array(x)
        ab_float = minimize_float(x)

        mi = 2147483647
        a_int = int(ab_float[0])
        b_int = int(ab_float[1])
        d = 50
        print a_int, b_int
        for a in range(a_int - d, a_int + d):
            for b in range(b_int - d, b_int + d):
                ab = [a, b]
                co = cost_float(x, ab)
                mi = min(mi, co)
        return mi

ArithmeticSequenceDiv1().findMinCost([97, 97, 97])
