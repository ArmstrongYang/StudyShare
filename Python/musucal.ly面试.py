
def matrix_multiply(x, y):
    if x is None or y is None:
        print("Matrix is empty")
        return None
    m = len(x)
    n = len(x[0])
    p = len(y)
    q = len(y[0])
    print(m, n, p, q)
    if n != p:
        print("Matrix can not multiply")
        return None
    out = [[0 for i in range(q)] for j in range(m)]

    for i in range(m):
        for j in range(q):
            for k in range(n):
                out[i][j] += x[i][k] * y[k][j]
    return out

x = [[1, 2], [1, 2], [1, 2]]
y = [[2, 2], [2, 2]]
z = matrix_multiply(x, y)
print(z)