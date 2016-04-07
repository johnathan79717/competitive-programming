sqrt x = sqrtIter 1.0 where
  sqrtIter guess =
    if isGoodEnough guess then guess
    else sqrtIter (improve guess)
  improve guess = (guess + x / guess) / 2
  isGoodEnough guess = abs (guess * guess - x) < 0.000001 * x
