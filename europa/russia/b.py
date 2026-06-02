import sys

import sys

def check(N):
    C = N // 5
    R = N % 5
    
    score = 50 * C * C + 20 * C
    base_level = 2 * C
    if R >= 1: score += 10 * (base_level + 1)
    if R >= 2: score += 10 * (base_level + 1)
    if R >= 3: score += 10 * (base_level + 1)
    if R == 4: score += 10 * (base_level + 2)
     
    return score

def solve():
    x = int(input())
    l, r = 0, 10**505 
    ans = r
    
    while l <= r:
        mid = (l + r) // 2 
        if check(mid) >= x:
            ans = mid 
            r = mid - 1
        else:
            l = mid + 1 

    p = check(ans)
    nivel = (4 * ans) // 10

    print(f"{nivel} {p}")

if __name__ == '__main__':
    solve()