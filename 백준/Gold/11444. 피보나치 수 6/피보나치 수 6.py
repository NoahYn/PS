import sys

# 입력 받기 (n이 매우 크므로 sys.stdin.read 사용 권장)
n = int(sys.stdin.readline())
MOD = 1000000007

# 행렬 곱셈 함수
def multiply(A, B):
    res = [[0] * 2 for _ in range(2)]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j] += A[i][k] * B[k][j]
            res[i][j] %= MOD
    return res

# 행렬 거듭제곱 함수 (분할 정복 이용)
def power(A, n):
    if n == 1:
        return A
    
    # n이 짝수인 경우: A^n = (A^(n/2))^2
    # n이 홀수인 경우: A^n = A * (A^((n-1)/2))^2
    tmp = power(A, n // 2)
    if n % 2 == 0:
        return multiply(tmp, tmp)
    else:
        return multiply(multiply(tmp, tmp), A)

# 초기 행렬 설정 [[1, 1], [1, 0]]
adj = [[1, 1], [1, 0]]

if n == 0:
    print(0)
elif n == 1:
    print(1)
else:
    # A^n을 구하면 [[F_{n+1}, F_n], [F_n, F_{n-1}]] 형태가 됨
    result = power(adj, n)
    # n번째 피보나치 수는 결과 행렬의 [0][1] 또는 [1][0] 위치
    print(result[0][1])