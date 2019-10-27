def min(A):
    min=A[0]
    for i in A:
        if i<min:
            min=i
    return min


print(min([5,1,3,4,2]))
