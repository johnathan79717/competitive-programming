def solve(X, Y):
    if Y <= 0 and Y % 2 == 0 and Y <= X and X <= -Y+1:
        return True
    if X > 0 and X % 2 == 1 and -X+1 <= Y and Y <= X+1:
        return True
    if Y > 0 and Y % 2 == 0 and -Y <= X and X <= Y-1:
        return True
    return X < 0 and X % 2 == 0 and X <= Y and Y <= -X
     
T = int(input())
 
for t in range(T):
    X, Y = map(int, input().split())
    print("YES" if solve(X, Y) else "NO") 