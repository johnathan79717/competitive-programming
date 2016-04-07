invert [] = []
invert ([a, b]:xs) = ([b, a]:(invert xs))
