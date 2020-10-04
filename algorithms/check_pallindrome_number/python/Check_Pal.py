def check_pal(n):
    num = n; rev = 0
    while num > 0:
        rev = rev * 10  + (num % 10)
        num //= 10
    
    return n == rev

n = int(input())

ans = 'YES' if check_pal(n) else 'NO'

print(ans)