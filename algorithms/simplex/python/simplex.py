from sys import stdin
import sys

M = 99

def Read_Input():
    n, m = list(map(int, stdin.readline().split()))
    A = []
    for i in range(n):
        A += [list(map(int, stdin.readline().split()))]
    b = list(map(int, stdin.readline().split()))
    b.append(0)
    c = list(map(int, stdin.readline().split()))
    for i in range(len(c)):
        c[i] = 0 - c[i]
    A.append(c)
    return n, m, A, b

# Add slack variable for each inequality such that
# for row i of A,  s_j = 1 if i = j and 0 otherwise
def Add_Slack_Variables(A, m):
    for i in range(len(A)):
        for j in range(len(A) - 1):
            A[i].append(0)
    for i in range(len(A) - 1):
        A[i][i + m] = 1

# Add artificial variable to every row i of A
# that has a negative solution b[i]
def Add_Artificial_Variables(A, b):
    artificial_var = 0
    for i in range(len(b)):
        if b[i] < 0:
            artificial_var += 1
            b[i] = 0 - b[i]
            for j in range(len(A[i])):
                A[i][j] = 0 - A[i][j]
            for k in range(len(A)):
                A[k].append(0)
            A[i][-1] = 1
            A[-1][-1] = M
    return artificial_var

# Complete the matrix by appending P and b as
# the final columns
def Add_b_and_P(A, b):
    for i in range(len(A)):
        A[i].append(0)
    A[-1][-1] = 1
    for j in range(len(b)):
        A[j].append(b[j])

# Check whether there is only 1 non-zero entry in column
def Test_Basis(A, column):
    appearances = 0
    row = -1
    for i in range(len(A)):
        if A[i][column] != 0:
            appearances += 1
            row = i
    if appearances == 1:
        return row
    return -1

# Build up basis of columns that satisfy test criteria
def Create_Basis(A, basis, m):
    for i in range(m, len(A[0])):
        row = Test_Basis(A, i)
        if row != -1:
            val = A[row][-1] / A[row][i]
            basis[i] = (row, val)

# check for invalid (negative) values in basis
def Validate_Basis(A, basis, P):
    for val in basis:
        if basis[val][1] < 0 and val != P:
            return False
    return True

def Move_M(A):
    pivot_row = -1
    pivot_column = -1
    for i in range(len(A[-1])):
        if A[-1][i] == M:
            pivot_column = i
    for j in range(len(A)):
        if A[j][pivot_column] == 1:
            pivot_row = j
    if pivot_row == -1 or pivot_column == -1:
        return False
    for k in range(len(A[-1])):
        A[-1][k] = A[-1][k] - (M * A[pivot_row][k])
    return True

# Perform normal Pivot operations until all val on bottom row are non-negative
def Find_Pivot_Column(A, m):
    min_val = 0
    min_index = -1
    for i in range(len(A[0]) - 1):
        if A[-1][i] < min_val:
            min_val = A[-1][i]
            min_index = i
    return min_index

def Find_Pivot_Row(A, column):
    if column == -1:
        return -1
    min_val = 999999999
    row = -1
    for i in range(len(A) - 1):
        if A[i][column] > 0:
            val = A[i][-1] / A[i][column]
            if val < min_val:
                min_val = val
                row = i
    return row

def Pivot(A, pivot_row, pivot_column):
    val = A[pivot_row][pivot_column]
    for i in range(len(A[pivot_row])):
        A[pivot_row][i] = A[pivot_row][i] / val
    for i in range(len(A)):
        if i != pivot_row:
            Scale_Row(A, i, pivot_row, pivot_column)

def Scale_Row(A, row, pivot_row, pivot_column):
    scale = A[row][pivot_column]
    if scale != 0:
        for i in range(len(A[row])):
            comp = A[pivot_row][i] * scale
            A[row][i] = A[row][i] - comp


def Update_Basis(basis, pivot_row, pivot_column, m):
    entering = pivot_column
    for val in basis:
        if basis[val][0] == pivot_row:
            exiting = val
    del basis[exiting]
    val = A[pivot_row][-1] / A[pivot_row][pivot_column]
    basis[pivot_column] = (pivot_row, val)
    for val in basis:
        row = basis[val][0]
        basis[val] = (row, A[row][-1] / A[row][val])

def Test_No_Solution(basis, real_var, slack_var, artificial_var):
    lower = real_var + slack_var
    upper = lower + artificial_var
    for val in basis:
        if val >= lower and val < upper and basis[val][1] > .0005:
            return True

def Get_Solution(basis, real_var, solution):
    for var in basis:
        if var < real_var:
            solution[var] = basis[var][1]
    return solution

def Print_Solution(solution):
    print("Bounded solution")
    print(' '.join(list(map(lambda x : '%.18f' % x, solution))))

def Solve(n, m, A, b):
    # Create matrix
    Add_Slack_Variables(A,m)
    artificial_var = Add_Artificial_Variables(A, b)
    Add_b_and_P(A, b)
    slack_var = n
    real_var = m
    P = real_var + slack_var + artificial_var

    # Create basis
    basis = {}
    Create_Basis(A, basis, m)

    # Validate basis
    valid = Validate_Basis(A, basis, P)
    i = 0
    while not valid:
        flag = Move_M(A)
        if not flag:
            break
        basis = {}
        Create_Basis(A, basis, m)
        valid = Validate_Basis(A, basis, P)

    # Perform pivots while negative val in bottom row
    col = Find_Pivot_Column(A, m)
    while col != -1:
        row = Find_Pivot_Row(A, col)
        if row == -1:
            print("Infinity")
            return
        Pivot(A, row, col)
        Update_Basis(basis, row, col, m)
        col = Find_Pivot_Column(A, m)
    if Test_No_Solution(basis, real_var, slack_var, artificial_var):
        print("No solution")
        return

    solution = [0 for i in range(real_var)]
    Get_Solution(basis, real_var, solution)
    Print_Solution(solution)

if __name__ == "__main__":
    n, m, A, b = Read_Input()
    Solve(n, m, A, b)
