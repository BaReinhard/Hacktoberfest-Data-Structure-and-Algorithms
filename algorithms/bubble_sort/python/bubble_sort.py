def bubbleSort(a):
    n = len(a)
    sorted = False
    while not sorted:
        sorted = True
        for i in range(0, n - 1):
            if a[i] > a[i + 1]:
                sorted = False
                a[i], a[i + 1] = a[i + 1], a[i]

a = [12, 33, 1, 3, 54, 32, 78, 54, 99, 6]
print(a)
bubbleSort(a)
print(a)
