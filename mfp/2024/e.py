MOD = 10**9 + 7

def multiply(a, b, N):
    res = [0] * N
    for i in range(N):
        if a[i] == 0:
            continue
        for j in range(N):
            if b[j] == 0:
                continue
            k = (i + j) % N
            res[k] = (res[k] + a[i] * b[j]) % MOD
    return res

def power(poly, exponent, N):
    result = [0] * N
    result[0] = 1  # Identity element (t^0)
    while exponent > 0:
        if exponent % 2 == 1:
            result = multiply(result, poly, N)
        poly = multiply(poly, poly, N)
        exponent = exponent // 2
    return result

def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr]); ptr +=1
    M = int(input[ptr]); ptr +=1
    k = int(input[ptr]); ptr +=1
    l = int(input[ptr]); ptr +=1
    
    x_list = list(map(int, input[ptr:ptr+k]))
    ptr +=k
    y_list = list(map(int, input[ptr:ptr+l]))
    
    # Create initial polynomial
    poly = [0] * N
    for x in x_list:
        idx = x % N
        poly[idx] += 1
    for i in range(N):
        poly[i] %= MOD
    
    # Compute poly^M
    final_poly = power(poly, M, N)
    
    # Sum the target areas
    target = set(y_list)
    total = 0
    for s in target:
        total = (total + final_poly[s % N]) % MOD
    
    # Compute denominator: k^M mod MOD
    denominator = pow(k, M, MOD)
    # Compute inverse of denominator
    inv_denominator = pow(denominator, MOD-2, MOD)
    # Result is (total * inv_denominator) mod MOD
    result = (total * inv_denominator) % MOD
    print(result)

if __name__ == '__main__':
    main()