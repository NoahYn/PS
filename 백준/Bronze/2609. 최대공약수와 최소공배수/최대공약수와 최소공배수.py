import math

a, b = input().split()
a = int(a)
b = int(b)
print(math.gcd(a,b), int(a*b/math.gcd(a,b)))