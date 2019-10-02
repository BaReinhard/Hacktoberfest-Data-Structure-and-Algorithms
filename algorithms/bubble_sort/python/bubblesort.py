def bubble_sort(A):
    for i in range(0, len(A) - 1):
        for j in range(len(A) - 1, i, -1):
            if A[j] < A[j - 1]:
                aux = A[j]
                A[j] = A[j - 1]
                A[j - 1] = aux
            
